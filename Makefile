CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ../build/

all: project

rpn.o: rpn.c
	$(CC) $(CFLAGS) -c rpn.c

input.o: input.c
	$(CC) $(CFLAGS) -c input.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

calculating.o: calculating.c
	$(CC) $(CFLAGS) -c calculating.c

rpn_test.o: rpn_test.c
	$(CC) $(CFLAGS) -c rpn_test.c

project: rpn_test.o input.o stack.o rpn.o calculating.o
	$(CC) -o $(DIR)graph rpn_test.c input.o stack.o rpn.o calculating.o

clean:
	rm -rf *.o

rebuild: clean all
