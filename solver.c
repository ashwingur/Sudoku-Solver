#include "solver.h"

int main(int argc, char **argv){
    int *grid = parse_file(argv[1]);
    free(grid);
    return 0;
}

int solve(int **grid){
    int *known = find_known(*grid);
    int row = 0;
    int col = 0;
    int i = 0;
    
    while (i >= 0 && i < 81){
        if (!known[i]){
            // It is not a preset value

        }
    }
    free(known);
}

int is_valid(int *grid, int k){
    int num = grid[k];
    // Checking row
    int row = k / 9;
    for (int i = 0; i < 9; i++){
        if (grid[row * 9 + i] == num){
            if (row * 9 + i != k){
                return false;
            }
        }
    }

    // Checking column
    int col = k % 9;
    for (int i = 0; i < 9; i++){
        if (grid[9 * i + col] == num){
            if (9 * i + col != k){
                return false;
            }
        }
    }

    // Checking the number's corresponding 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (grid[(box_row + i) * 9 + box_col + j] == num){
                if ((box_row + i) * 9 + box_col + j != k){
                    return false;
                }
            }
        }
    }

    return true;
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
    return known;
}