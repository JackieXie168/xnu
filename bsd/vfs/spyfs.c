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

proc_t caller;
ipc_port_t spy_sendport = NULL;
struct spy_vars spy_vars;
/* We don't want to start traversing any proc lists until the
 * proc that issued the spyfs command has exited. */

int __spyfs(int pid, int options);

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

	if (strlen(path) > 127 || strlen(proc_name) > 127) {
		/* Will have to truncate the strings */
		memcpy(msg->path, path, 127);
		memcpy(msg->proc_name, proc_name, 127);
	} else {
		strlcpy(msg->path, path, strlen(path) + 3);
		strlcpy(msg->proc_name, proc_name, strlen(proc_name) + 3);
	}
	msg->mode = mode;

	spy_set_header(&msg->header);
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

	pid = args->pid;
	opts = args->options;
	return (__spyfs(pid, opts));
}

int __spyfs(int pid, int options)
{
	int err;
	struct spy *spystruct = NULL;
	struct spy *iter = NULL;
	struct spy *iter_temp = NULL;
	proc_t p = NULL;

	/* Remember the calling task in global */
	caller = current_proc();
	caller->p_refcount++;
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
		return -ENOMEM;
	}
	if (pid < 0) {
		p = caller;
		pid  = p->p_pid;
	} else {
		p = proc_find(pid);
		if (!p) {
			_FREE(spystruct, M_FREE); 
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
