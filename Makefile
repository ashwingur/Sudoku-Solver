CC=gcc
CFLAGS=-fsanitize=address -std=gnu11 -g -lm

.PHONY: solver clean

solver: solver.c solver.h
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm -f solver
	rm -f