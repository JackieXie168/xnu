#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mach/mach.h>
#include <mach/mach_types.h>
#include "spy.h"

#define MODE_O	"opened"
#define MODE_R	"read"
#define MODE_W	"wrote"
#define MODE_C	"closed"
#define MODE_M	"mapped"
#define MODE_PI	"paged in"
#define MODE_PO	"paged out"
#define MODE_UM	"unmapped"

void hexdie(kern_return_t err, const char *msg)
{
	fprintf(stderr, "%s:%#x\n", msg, err);
	exit(1);
}

/* Globals needed by sig handler */
int port;
int success;


/* Interrupt handler */
void handle_signal(int sig)
{
	kern_return_t kr;

#ifdef DEBUG
	printf("Entering signal handler\n");
#endif	
	if (success) {
		kr = mach_port_deallocate(mach_task_self(), port);
		if (kr != KERN_SUCCESS)
			hexdie(kr, "mach_port_deallocate");
	}
	exit(0);
}


void recv_msg(mach_port_t source)
{
	mach_msg_return_t err = 0;
	struct spy_msg msg;
	const char *msg_txt = NULL;

	memset(&msg, 0, sizeof(msg));
	
	msg.header.msgh_size = sizeof(msg);
	err = mach_msg(&msg.header,
			MACH_RCV_MSG,
			0,
			sizeof(msg),
			source,
			MACH_MSG_TIMEOUT_NONE,
			MACH_PORT_NULL);
	if (err != MACH_MSG_SUCCESS) {
		hexdie(err, "Couldn't receive message");
	}

	switch(msg.mode) {
	case 0:
		msg_txt = MODE_O;
		break;
	case 1:
		msg_txt = MODE_R;
		break;
	case 2:
		msg_txt = MODE_W;
		break;
	case 3:
		msg_txt = MODE_C;
		break;
	case 4:
		msg_txt = MODE_M;
		break;
	case 5:
		msg_txt = MODE_PI;
		break;
	case 6:
		msg_txt = MODE_PO;
		break;
	case 7:
		msg_txt = MODE_UM;
		break;
	}
	printf("%s : %s : %s\n",
			msg.proc_name,
			msg_txt,
			msg.path);
	
}

int main(int argc, char **argv)
{
	int err, pid, opts;
	kern_return_t kr;
	mach_port_t dest_port;
	char *name = NULL;

	/* Install signal handler */
	signal(SIGINT, &handle_signal); 

	switch(argc) {
	case 3: /* PID, no name */
		if (atoi(argv[1]) < 0) {
			pid = getpid();
		} else {
			pid = atoi(argv[1]);
		}
		opts = atoi(argv[2]);

		err = syscall(456, pid, NULL, opts);
		if (err) {
			perror("Spyfs failed");
			exit(err);
		}
		kr = mach_port_allocate(mach_task_self(),
					    MACH_PORT_RIGHT_RECEIVE,
					    &dest_port);
		if (err != KERN_SUCCESS) {
			hexdie(err, "main: mach_port_allocate recv failed");
		}

		while(1) {
			recv_msg(dest_port);
		}

		break;
	case 4: /* Name given */
		opts = atoi(argv[3]);
		name = argv[2];
		pid = -1; /* Ignored in this case */
		err = syscall(456, pid, name, opts);
		if (err) {
			perror("Spyfs failed");
			exit(err);
		}
		kr = mach_port_allocate(mach_task_self(),
					    MACH_PORT_RIGHT_RECEIVE,
					    &dest_port);
		
		if (err != KERN_SUCCESS) {
			hexdie(err, "main: mach_port_allocate recv failed");
		}
		success = 1; /* Set global for sighandler */

		while(1) {
			recv_msg(dest_port);
		}

		break;

	default:
		fprintf(stderr, "Usage: spytest <pid> <name(optional)> <options>\n");
		exit(1);
		break;
	}
	return 0;

}
