CC = clang
CFLAGS = -Wall -g

mmap_test: mmap_test.o

mmap_test.o: mmap_test.c

.PHONY: clean

clean:
	rm -rf ./*.o
	rm -rf ./mmap_test

.PHONY: all

all: clean mmap_test
