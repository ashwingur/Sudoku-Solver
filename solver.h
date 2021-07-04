#ifndef SOLVER
#define SOLVER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define true 1
#define false 0

int *parse_file(char *file_name);
void print_grid(int *grid);
int *find_known(int *grid);
int solve(int **grid);
int is_valid(int *grid, int i);

#endif