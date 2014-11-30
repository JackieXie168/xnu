/*
 * =====================================================================================
 *
 *       Filename:  spyfs.c
 *
 *    Description:  spyfs syscall implementation
 *
 *        Version:  1.0
 *        Created:  11/28/2014 11:46:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

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

struct spypid {
	int pid;	/* pid we are tracking. Negative indicates
       			 * no tracking */
	int options;
}
LIST_HEAD(pids, proc_t *);
LIST_INIT(pids):
struct spyfs_args;
int __spyfs(int pid, int options);
int spyfs(proc_t p, struct spyfs_args *args, int32_t *retval)
{
	struct spyfs_args kargs;
	int pid;
	int err;
	int *trackpid = NULL;
	LIST_ENTRY(
	trackpid = _MALLOC(sizeof(pid), M_FREE, M_WAITOK); 

	printf("Addr of 'args' is 0x%08lx\n", (unsigned long)args);
	pid = args->pid;
	printf("pid is %d\n", pid);
	return (__spyfs(pid, 0));
}

int __spyfs(int pid, int options)
{
	printf("pid is %d\n", pid);
	printf("opts is %d\n", options);

	return pid;	
}
