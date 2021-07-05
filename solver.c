#include "solver.h"

int main(int argc, char **argv){
    if (argc != 2){
        printf("Usage ./solver <puzzle.txt>\n");
        return -1;
    }
    int *grid = parse_file(argv[1]);
    int result = solve(&grid);
    printf("Result: %s\n", result != -1 ? "Success" : "Fail");
    printf("Iterations: %d\n\n", result);
    print_grid(grid);

    free(grid);
    return 0;
}

int solve(int **grid){
    int *known = find_known(*grid);
    int *visited =  calloc(81 , sizeof(int));
    int row = 0;
    int col = 0;
    int i = 0;
    int go_back = false;
    int iterations = 0;
    
    while (i >= 0 && i < 81){
        iterations++;
        if (visited[i]){
            // We have back tracked onto this cell, so we must try a new value
            visited[i] = false;
            (*grid)[i]++;
        }
        if (!known[i]){
            // It is not a preset value

            if ((*grid)[i] == 0){
                // A zero is an empty cell, so increment it to a valid value
                (*grid)[i]++;
            }
            while (!is_valid(*grid, i) && (*grid)[i] <= 9){
                // While this cell is invalid, increment it
                (*grid)[i]++;
            }
            if ((*grid)[i] > 9){
                // Could not find a valid value, so go back to previous cell
                (*grid)[i] = 0;
                go_back = true;
            } else {
                // Set visited to true and go to the next cell
                go_back = false;
                visited[i] = true;
            }
        }
        i += go_back ? -1 : 1;
    }
    free(known);
    free(visited);
    // i will be 81 if it successfully solves the grid
    return i == 81 ? iterations : -1;
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