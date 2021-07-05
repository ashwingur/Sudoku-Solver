#ifndef SOLVER
#define SOLVER

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define true 1
#define false 0

/*
    Parses a textfile in the format (zeroes represent empty cells):
    000000000
    000000000
    000000000
    000000000
    000000000
    000000000
    000000000
    000000000
    000000000
    The result is an 81 length array of integers that represents the 9x9 grid
*/
int *parse_file(char *file_name);

// Prints the grid
void print_grid(int *grid);
// Creates a boolean array where all 0 cells are 0 and all known cells are 1
// So we know not to modify any known values
int *find_known(int *grid);
// Solves the grid and returns the numbers of iterations it took (-1 if unsuccessful), updates grid
int solve(int **grid);
// Given the grid (array of 81 values), checks if the element at index i is valid
int is_valid(int *grid, int i);

#endif