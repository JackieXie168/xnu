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

#define SPY_END		(1 << 1)	/* Stop tracking pid */
#define SPY_WRITES	(1 << 2)	/* Track files that are written  */
#define SPY_READS	(1 << 3)	/* Track files that are read */

/* List of procs being spied upon by spyfs */
#ifndef __SPYLIST__
#define __SPYLIST__
typedef struct spy {
	proc_t p;	/* struct proc * that is being tracked */	
	int options;
	LIST_ENTRY(spy) others;
} spy;
#endif
LIST_HEAD(spylist, spy) spylist_head = LIST_HEAD_INITIALIZER(spylist_head);

/* Spylist locks */
extern lck_grp_attr_t *spylist_slock_grp_attr;
extern lck_grp_t *spylist_slock_grp;
extern lck_attr_t *spylist_slock_attr;
extern lck_spin_t *spylist_slock;

int __spyfs(int pid, int options);

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
	
	/* Lock before going any further */
	lck_spin_lock(spylist_slock);

	if (options & SPY_END) {
		LIST_FOREACH_SAFE(iter, &spylist_head, others, iter_temp) {
			if (iter->p->p_pid == pid) {
				LIST_REMOVE(iter, others);
				printf("Removing %s from spy_tasks\n",
						iter->p->p_comm);
				_FREE(iter, M_FREE);
			}
		}	
		return 0;
	}
	/* Unlock */
	lck_spin_unlock(spylist_slock);

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
