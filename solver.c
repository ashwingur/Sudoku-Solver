#include "solver.h"

int main(int argc, char **argv){
    int *grid = parse_file(argv[1]);
    int *known = find_known(grid);
    free(grid);
    free(known);
    return 0;
}


int *parse_file(char *file_name){
    FILE* f = fopen(file_name, "r");
    char c;
    int *grid = malloc(sizeof(int) * 81);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            fscanf(f, "%c", &c);
            *(grid + (i * 9) + j) = c - '0';
        }
        fscanf(f, "\n");
    }
    fclose(f);
    return grid;
}

void print_grid(int *grid){
    for (int i = 0; i < 81; i++){
        printf("%d", grid[i]);
        if ((i + 1) % 9 == 0){
            printf("\n");
        }
    }
}

int *find_known(int *grid){
    int *known = malloc(sizeof(int) * 81);
    for (int i = 0; i < 81; i++){
        if (grid[i] == 0){
            known[i] = false;
        } else {
            known[i] = true;
        }
    }
}