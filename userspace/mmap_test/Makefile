CC = clang
CFLAGS = -Wall -g -c

mmap_test: mmap_test.o

mmap_test.o: mmap_test.c

debug: CFLAGS += -DDEBUG

debug: mmap_test

.PHONY: clean

clean:
	rm -rf ./*.o
	rm -rf ./mmap_test

.PHONY: all

all: clean mmap_test
