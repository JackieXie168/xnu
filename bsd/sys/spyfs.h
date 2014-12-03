
/* List of procs being spied upon by spyfs */
#ifndef __SPYLIST__
#define __SPYLIST__

#define PROC_FOREACH_DESCENDANT(p, iter)\
	for (iter = p->p_children.lh_first; iter != NULL; iter = iter->p_children.lh_first)
#define PROC_FOREACH_SIBLING(p, iter)\
	LIST_FOREACH(iter, &p->p_pptr->p_children, p_sibling)

typedef struct spy {
	proc_t p;	/* struct proc * that is being tracked */	
	int options;
	LIST_ENTRY(spy) others;
} spy;
LIST_HEAD(spylist, spy); 

int proc_is_sibling(proc_t test, proc_t against, int locked);
int proc_is_descendant(proc_t test, proc_t against, int locked);
/* Spylist locks */
extern lck_grp_attr_t *spylist_slock_grp_attr;
extern lck_grp_t *spylist_slock_grp;
extern lck_attr_t *spylist_slock_attr;
extern lck_spin_t *spylist_slock;
#endif
