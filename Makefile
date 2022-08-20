CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ../build/

all:

calculate.o: calculate.c
	$(CC) $(CFLAGS) -c calculate.c

polish_notation.o: polish_notation.c
	$(CC) $(CFLAGS) -c polish_notation.c

project: polish_notation.o calculate.o
	$(CC) -o $(DIR)Project polish_notation.o calculate.o

clean:
	rm -rf *.o
	rm -rf ../build/Project*

rebuild: clean all
