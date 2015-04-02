CC=gcc
CFLAGS=-I.
DEPS = linkedList.h students.h words.h utility.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

asgn2: cscd340asgn2.o utility.o words.o linked_list.o
	gcc -std=ansi -o $@ $^ $(CFLAGS)

asgn2a: cscd340asgn2a.o utility.o students.o linked_list.o
	gcc -std=ansi -o $@ $^ $(CFLAGS)
