
/* List of procs being spied upon by spyfs */
#ifndef __SPYLIST__
#define __SPYLIST__
typedef struct spy {
	proc_t p;	/* struct proc * that is being tracked */	
	int options;
	LIST_ENTRY(spy) others;
} spy;
LIST_HEAD(spylist, spy); 
#endif
