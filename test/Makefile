CC = gcc
CFLAGS = -Wall -Wextra -Wconversion -Wsign-conversion -pedantic -Werror -std=c17
SRCDIR = ../src
BINDIR = ../bin

all: test_stack

test_stack: test_stack.o stack.o
	$(CC) $(CFLAGS) $^ -o $(BINDIR)/$@

test_stack.o: test_stack.c  $(SRCDIR)/stack/stack.h testutils.h
	$(CC) $(CFLAGS) -c $^

stack.o: $(SRCDIR)/stack/stack.c $(SRCDIR)/stack/stack.h
	$(CC) $(CFLAGS) -c $^
