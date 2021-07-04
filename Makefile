CC=gcc
CFLAGS=-fsanitize=address -Wall -Werror -std=gnu11 -g -lm

solver: solver.c solver.h
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm -f solver
	rm -f