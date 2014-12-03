#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int err, pid, opts;

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
	return 0;
}
