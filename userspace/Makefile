CFLAGS = -Wall -g
LDFLAGS = 

spytest: spytest.o

spytest.o: spytest.c spy.h

.PHONY: clean

clean:
	rm -rf ./*.o
	rm -rf spytest

.PHONY: all

all: clean spytest


