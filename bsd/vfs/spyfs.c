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

#include <dev/random/randomdev.h>

#include <uuid/uuid.h>

#include <stdarg.h>
#include <sys/queue.h>
#include <sys/sysproto.h>

#define SPY_START	(0)		/* Start tracking (default) */
#define SPY_END		(1 << 1)	/* Stop tracking pid */
#define SPY_WRITES	(1 << 2)	/* Track files that are written  */
#define SPY_READS	(1 << 3)	/* Track files that are read */

typedef struct spy {
	proc_t p;	/* struct proc * that is being tracked */	
	int options;
	LIST_ENTRY(spy) others;
} spy;

struct spy spy_global = { 0 };

LIST_HEAD(spylist,  spy) spylist_head = LIST_HEAD_INITIALIZER(x); 
//struct spyfs_args;
int __spyfs(int pid, int options);

int spyfs(proc_t p, struct spyfs_args *args, int32_t *retval)
{
	int pid;
	int opts;

	printf("Addr of 'args' is 0x%08lx\n", (unsigned long)args);
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
	
	printf("pid is %d\n", pid);
	printf("opts is %d\n", options);

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
	spystruct = _MALLOC(sizeof(struct spy), M_FREE, M_WAITOK); 
	if (!spystruct) {
		printf("spyfs: Couldn't malloc spystruct\n");
		return -ENOMEM;
	}
	if (pid < 0) {
		p = current_thread();
		pid  = p->p_pid;
	} else {
		p = proc_find(pid);
		if (!p)
			return -EINVAL;
	}
	printf("pid is %d\n", pid);
	printf("p_comm is %s\n", p->p_comm);
	printf("p_name is %s\n", p->p_name);
	LIST_INSERT_HEAD(&spylist_head, &spy_global, others); 
	return 0;
}
