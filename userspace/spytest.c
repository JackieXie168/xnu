#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mach/mach.h>
#include <mach/mach_types.h>
#include "spy.h"

void hexdie(kern_return_t err, const char *msg)
{
	fprintf(stderr, "%s:%#x\n", msg, err);
	exit(1);
}

void recv_msg(mach_port_t source)
{
	mach_msg_return_t err = 0;
	struct spy_msg msg;

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
	printf("%s : %d : %s\n",
			msg.proc_name,
			msg.mode,
			msg.path);
	
}

int main(int argc, char **argv)
{
	int err, pid, opts;
	kern_return_t kr;
	mach_port_t dest_port;
	
	if (argc != 3) {
		fprintf(stderr, "Usage: spytest <pid> <options>\n");
		exit(1);
	}

	if (atoi(argv[1]) < 0) {
		pid = getpid();
	} else {
		pid = atoi(argv[1]);
	}
	opts = atoi(argv[2]);

	err = syscall(456, pid, opts);
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
	return 0;
}
