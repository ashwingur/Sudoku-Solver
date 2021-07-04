#ifndef SOLVER
#define SOLVER

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int *parse_file(char *file_name);
void print_grid(int *grid);
int *find_known(int *grid);

#endif