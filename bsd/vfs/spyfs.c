#include <sys/errno.h>
#include <sys/types.h>
#include <sys/malloc.h>
#include <sys/buf.h>
#include <sys/time.h>
#include <sys/kauth.h>
#include <sys/mount.h>
#include <sys/vnode.h>
#include <sys/syslog.h>
#include <sys/vnode_internal.h>
#include <sys/fslog.h>
#include <sys/mount_internal.h>
#include <sys/kasl.h>
#include <kern/locks.h>
#include <dev/random/randomdev.h>
#include <uuid/uuid.h>
#include <stdarg.h>
#include <sys/queue.h>
#include <sys/sysproto.h>
#include <sys/spyfs.h>
#include <ipc/ipc_types.h>
#define SPY_END		(1 << 1)	/* Stop tracking pid */
#define SPY_WRITES	(1 << 2)	/* Track files that are written  */
#define SPY_READS	(1 << 3)	/* Track files that are read */

extern lck_mtx_t * proc_list_mlock;
struct spylist spylist_head = LIST_HEAD_INITIALIZER(spylist_head);
struct spy_mmap_info_list mmap_info_list_head = LIST_HEAD_INITIALIZER(mmap_info_list_head); 

proc_t caller;
ipc_port_t spy_sendport = NULL;
spy_name spy_look_for_name = {0};
struct spy_vars spy_vars;
/* We don't want to start traversing any proc lists until the
 * proc that issued the spyfs command has exited. */

int __spyfs(int pid, char *name, int options);

void spy_set_header(mach_msg_header_t *header)
{
	if (!header)
		return;
	/* Not sure if this is the right way to set
	 * the "msgh bits" */
	header->msgh_bits = MACH_MSGH_BITS_REMOTE(MACH_MSG_TYPE_COPY_SEND);
	header->msgh_size = sizeof(struct spy_msg);
	header->msgh_remote_port = spy_sendport;
	header->msgh_local_port = PORT_NULL;
	/* Don't think we need to fill out the rest of the header */
}

void spy_construct_message(struct spy_msg *msg, char *path, char* proc_name, int mode)
{
	if (!(msg && path && proc_name))
		return;
	memset(msg, 0, sizeof(struct spy_msg));

	/* Note that we should have verified by this point that path
	 * and proc_name are valid strings */

	if (strlen(path) > MAX_PATH_LENGTH - 1 ||
		       	strlen(proc_name) > MAX_PROC_NAME_LENGTH - 1) {
		/* Will have to truncate the strings */
		memcpy(msg->path, path, MAX_PATH_LENGTH - 1);
		memcpy(msg->proc_name, proc_name, MAX_PROC_NAME_LENGTH - 1);
	} else {
		strlcpy(msg->path, path, strlen(path) + 3);
		strlcpy(msg->proc_name, proc_name, strlen(proc_name) + 3);
	}
	msg->mode = mode;

	spy_set_header(&msg->header);
}

/* Must hold lock for spy_mmap_info_list */
int spy_vnode_is_mapped_with_write_perms(
		struct vnode *vp,
		struct spy_mmap_info_list *lhead)
{
	spy_mmap_info *iter = NULL;
	
	lck_mtx_lock(spy_mmap_list_mtx);
	LIST_FOREACH(iter, lhead, next_vnode) {
		if (iter->vp == vp)
			return 1;
	}
	lck_mtx_unlock(spy_mmap_list_mtx);
	return 0;
}

/* Returns 1 if 'test' is a sibling of 'against' */
int proc_is_sibling(proc_t test, proc_t against, int locked)
{
	proc_t iter = NULL;

	switch (locked) {
	case 0:
		lck_mtx_lock(proc_list_mlock);
		PROC_FOREACH_SIBLING(against, iter) {
			if (iter == test) {
				lck_mtx_unlock(proc_list_mlock);
				return 1;
			}
		}
		lck_mtx_unlock(proc_list_mlock);
		return 0;
	case 1:
		PROC_FOREACH_SIBLING(against, iter)
			if (iter == test)
				return 1;
		return 0;
	}
	return 0;
}

/* Returns 1 if 'test' is a descendent of 'against' */
int proc_is_descendant(proc_t test, proc_t against, int locked)
{
	proc_t iter = NULL;
	int match = 0;

	switch (locked) {
	case 0:
		/* Wait for proclist lock */
		lck_mtx_lock(proc_list_mlock);
		
		PROC_FOREACH_DESCENDANT(against, iter) {
			if (iter == test) {
				lck_mtx_unlock(proc_list_mlock);
				return 1;
			} else {
				match = proc_is_sibling(test, iter, 1);
				if (match) {
					lck_mtx_unlock(proc_list_mlock);
					return 1;
				}
			}
		}
		lck_mtx_unlock(proc_list_mlock);
		return 0;
	case 1:
		PROC_FOREACH_DESCENDANT(against, iter) {
			if (iter == test) {
				return 1;
			} else {
				match = proc_is_sibling(test, iter, 1);
				if (match)
					return 1;
			}
		}
		return 0;
	}
	return 0;
}

int spyfs(proc_t p, struct spyfs_args *args, int32_t *retval)
{
	int pid;
	int opts;
	char *proc_name = NULL;
	char name[128] = {0};
	int err = 0;

	pid = args->pid;
	opts = args->options;
	proc_name = (char *)args->proc_name;
	if (proc_name) {
		err = copyin((user_addr_t)proc_name,
				&name, 128);
		if (err != KERN_SUCCESS)
			return -EINVAL;
	}
	if (strlen(name)) {
		*retval = 0; /* Need to move this to __spyfs() */
		return (__spyfs(pid, &name[0], opts));
	} else {
		*retval = 0; /* Need to move this to __spyfs() */
		return (__spyfs(pid, NULL, opts)); 
	}
}

int __spyfs(int pid, char *name, int options)
{
	struct spy *spystruct = NULL;
	struct spy *iter = NULL;
	struct spy *iter_temp = NULL;
	proc_t p = NULL;

	/* Remember the calling task in global */
	caller = current_proc();
	caller->p_refcount++;

	/* Remember that strlcpy only copies
	 * len - 1 bytes so that it can NULL
	 * terminate */
	if (name && strlen(name)) {
		printf("__spyfs: keeping a lookout for %s\n", name);
		strlcpy((char *)&spy_look_for_name, name, strlen(name) + 1);
		return KERN_SUCCESS;
	}

	if (options & SPY_END) {
		/* Lock before going any further */
		lck_mtx_lock(spylist_mtx);
		LIST_FOREACH_SAFE(iter, &spylist_head, others, iter_temp) {
			if (iter->p->p_pid == pid) {
				LIST_REMOVE(iter, others);
				printf("Removing %s from spy_tasks\n",
						iter->p->p_comm);
				p = iter->p;
				_FREE(iter, M_FREE);
			}
		}	
		/* Unlock */
		lck_mtx_unlock(spylist_mtx);
		if (p) {
			proc_lock(p);
			p->p_refcount--;
			proc_unlock(p);
		}
		return 0;
	}

	spystruct = _MALLOC(sizeof(struct spy), M_FREE, M_WAITOK); 
	if (!spystruct) {
		printf("spyfs: Couldn't malloc spystruct\n");
		caller->p_refcount--;
		return -ENOMEM;
	}
	if (pid < 0) {
		/* Unlikely that a proc would spy on itself, but just incase */
		p = caller;
		pid  = p->p_pid;
		p->p_refcount++;
	} else {
		p = proc_find(pid); /* This increments refcount!! */
		if (!p) {
			_FREE(spystruct, M_FREE); 
			caller->p_refcount--;
			return -EINVAL;
		}
	}
	printf("Adding %s to the spylist\n", p->p_comm);
	memset(spystruct, 0, sizeof(struct spy));
	spystruct->p = p;
	spystruct->options = options;
	lck_mtx_lock(spylist_mtx);
	LIST_INSERT_HEAD(&spylist_head, spystruct, others); 
	lck_mtx_unlock(spylist_mtx);
	return 0;
}
