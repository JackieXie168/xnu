CFLAGS = -Wall -g -c
LDFLAGS = 

spytest: spytest.o

spytest.o: spytest.c spy.h

debug: CFLAGS += -DDEBUG

debug: spytest

.PHONY: clean

clean:
	rm -rf ./*.o
	rm -rf spytest

.PHONY: all

all: clean spytest


