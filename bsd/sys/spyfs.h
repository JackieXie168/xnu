
/* List of procs being spied upon by spyfs */
#ifndef __SPYLIST__
#define __SPYLIST__
typedef struct spy {
	proc_t p;	/* struct proc * that is being tracked */	
	int options;
	LIST_ENTRY(spy) others;
} spy;
LIST_HEAD(spylist, spy); 
/* Spylist locks */
extern lck_grp_attr_t *spylist_slock_grp_attr;
extern lck_grp_t *spylist_slock_grp;
extern lck_attr_t *spylist_slock_attr;
extern lck_spin_t *spylist_slock;
#endif
