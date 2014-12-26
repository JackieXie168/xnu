
/* List of procs being spied upon by spyfs */
#ifndef __SPYLIST__
#define __SPYLIST__

#define MAX_PATH_LENGTH		256
#define MAX_PROC_NAME_LENGTH	128
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

struct spy_msg {
	mach_msg_header_t header;
	char proc_name[128];
	char path[MAX_PATH_LENGTH];
	int mode;	/* 0 = read, 1 = write */
};

struct spy_vars {
	mach_port_name_t	port_name;
	ipc_space_t		ipc_space;
	int			set;
};

int proc_is_sibling(proc_t test, proc_t against, int locked);
int proc_is_descendant(proc_t test, proc_t against, int locked);
/* Spylist locks */
extern lck_grp_attr_t *spylist_mtx_grp_attr;
extern lck_grp_t *spylist_mtx_grp;
extern lck_attr_t *spylist_mtx_attr;
extern lck_mtx_t *spylist_mtx;
#endif
