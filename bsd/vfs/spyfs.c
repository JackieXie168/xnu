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
#define SPY_END		(1 << 1)	/* Stop tracking pid */
#define SPY_WRITES	(1 << 2)	/* Track files that are written  */
#define SPY_READS	(1 << 3)	/* Track files that are read */

extern lck_mtx_t * proc_list_mlock;
struct spylist spylist_head = LIST_HEAD_INITIALIZER(spylist_head);


int __spyfs(int pid, int options);

/* Returns 1 if 'test' is a sibling of 'against' */
int proc_is_sibling(proc_t test, proc_t against, int locked)
{
	proc_t iter = NULL;

	switch (locked) {
	case 0:
		lck_mtx_lock(proc_list_mlock);
		PROC_FOREACH_SIBLING(against, iter) {
			if (iter == against) {
				lck_mtx_unlock(proc_list_mlock);
				return 1;
			}
		}
		lck_mtx_unlock(proc_list_mlock);
		return 0;
	case 1:
		PROC_FOREACH_SIBLING(against, iter)
			if (iter == against)
				return 1;
		return 0;
	}
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
}

int spyfs(proc_t p, struct spyfs_args *args, int32_t *retval)
{
	int pid;
	int opts;

	pid = args->pid;
	opts = args->options;
	return (__spyfs(pid, 0));
}

int __spyfs(int pid, int options)
{
	int err;
	struct spy *spystruct = NULL;
	struct spy *iter = NULL;
	struct spy *iter_temp = NULL;
	proc_t p = NULL;
	

	if (options & SPY_END) {
		/* Lock before going any further */
		lck_spin_lock(spylist_slock);
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
		lck_spin_unlock(spylist_slock);
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
		p = current_proc();
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
	lck_spin_lock(spylist_slock);
	LIST_INSERT_HEAD(&spylist_head, spystruct, others); 
	lck_spin_unlock(spylist_slock);
	return 0;
}
