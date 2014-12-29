#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

void
die(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void
die_err(const char *msg)
{
	perror(msg);
	exit(1);
}

int
main(int argc, char **argv)
{
	char temp;
	int err;
	int len;
	int i;
	char *p = NULL;	/* To be mmapped */
	FILE *f = NULL;

	if (argc != 2)
		die("Usage: mmap_test <path/to/file>");

	/* Wait for user input */
	fread(&temp, sizeof(char), 1, stdin);

	/* Open the file */
	f = fopen(argv[1], "r+");
	if (!f)
		die_err("fopen");
	/* Fast-forward */
	err = fseek(f, 0, SEEK_END);
	if (err)
		die_err("fseek");
	len = ftell(f);

	p = mmap(NULL,
		 len,
		 PROT_READ | PROT_WRITE,
		 MAP_FILE | MAP_SHARED,
		 fileno(f),
		 0);
	if (!p)
		die_err("mmap");	       

	/* Read */
	for (i = 0; i < len; ++i) {
	       temp = p[i];
	}

	/* Write */
	for (i = 0; i < len; ++i) {
	       p[i] = p[i] + 2;
	}

#ifdef DEBUG
	printf("len is %d\n", len);
#endif
	err = munmap(p, len);
	if (err)
		die_err("munmap");

	err = fclose(f);
	if (err)
		die_err("fclose");

	return 0;
}
