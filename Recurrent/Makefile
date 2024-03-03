CC=g++
CFLAGS=-g3 -Wall -DTEST_MAIN=1

all: functions

functions: Func.cpp
	$(CC) $(CFLAGS) -o $@ $^

test: functions
		./functions

