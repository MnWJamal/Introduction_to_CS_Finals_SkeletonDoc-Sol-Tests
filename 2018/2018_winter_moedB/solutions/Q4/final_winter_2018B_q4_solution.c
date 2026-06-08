#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int count_solutions(int grid[N*N][N*N]);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int grid[N*N][N*N];
    for (int i = 0; i < N*N; i++) {
        for (int j = 0; j < N*N; j++) {
            if (scanf("%d", &grid[i][j]) != 1) return 1;
        }
    }

    printf("%d", count_solutions(grid));
    return 0;
}
void ResetHist(int * arr, int n) {
    for (int i = 0 ; i < n ; i++) arr[i] = 0;
}
bool ValidSoduko(int grid[N*N][N*N]) {
    int Hist[N*N+1] = {0};
    //VALIDATE SQUARES
    for (int sqr = 0 ; sqr < N*N ; sqr++) {
        int begin_row = sqr/N;
        begin_row*=N;
        int begin_column = (sqr%N);
        begin_column*=N;
        ResetHist(Hist,N*N+1);
        for (int idi = begin_row ; idi < begin_row+N ; idi++) {
            for (int idj = begin_column ; idj < begin_column+N ; idj++) {
                Hist[grid[idi][idj]]++;
            }
        }
        for (int n = 1 ; n <= N*N ; n++) {
            if (Hist[n] != 1) return false;
        }
    }
    //VALIDATE ROWS:
    for (int row = 0 ; row < N*N ; row++) {
        ResetHist(Hist,N*N + 1);
        for (int idj = 0 ; idj < N*N ; idj++) {
            Hist[grid[row][idj]]++;
        }
        for (int n = 1 ; n <= N*N ; n++) {
            if (Hist[n] != 1) return false;
        }
    }
    //VALIDATE COLUMNS:
    for (int column = 0 ; column < N*N ; column++) {
        ResetHist(Hist,N*N + 1);
        for (int idi = 0 ; idi < N*N ; idi++) {
            Hist[grid[idi][column]]++;
        }
        for (int n = 1 ; n <= N*N ; n++) {
            if (Hist[n] != 1) return false;
        }
    }
    return true;
}
bool ValidToAdd(int i, int j, int val, int grid[N*N][N*N]) {
    int square_head_i = (i/(N));
    int square_head_j = (j/(N));
    square_head_i *= N;
    square_head_j *= N;
    //validate block:
    for (int idi = square_head_i; idi < square_head_i + N ; idi++) {
        for (int idj = square_head_j; idj < square_head_j + N ; idj++) {
            if (grid[idi][idj] == val) return false;
        }
    }
    //validate row:
    for (int idj = 0 ; idj < N*N ; idj++) {
        if (grid[i][idj] == val) return false;
    }
    //validate column:
    for (int idi = 0 ; idi < N*N ; idi++) {
        if (grid[idi][j] == val) return false;
    }

    return true;
}

int count_solutions_aux(int grid[N*N][N*N],int i, int j, int numbers_remaining){
    if (numbers_remaining <= 0) {
        return ValidSoduko(grid)? 1 : 0;
    }
    if (grid[i][j]) {
        int solutions = 0;
        if (j == N*N-1) {
            solutions = count_solutions_aux(grid,i+1,0,numbers_remaining-1);
        }
        else {
            solutions = count_solutions_aux(grid,i,j+1,numbers_remaining-1);
        }
        return solutions;
    }
    else {
        int number_of_solutions = 0;
        for (int n = 1 ; n <= N*N ; n++) {
            if (ValidToAdd(i,j,n,grid)) {
                grid[i][j] = n;
                if (j == N*N-1) {
                    number_of_solutions += count_solutions_aux(grid,i+1,0,numbers_remaining-1);
                }
                else {
                    number_of_solutions += count_solutions_aux(grid,i,j+1,numbers_remaining-1);
                }
                //backtrack
                grid[i][j] = 0;
            }
        }
        return number_of_solutions;
    }
}

int count_solutions(int grid[N*N][N*N]) {
    return count_solutions_aux(grid,0,0,N*N*N*N);
}
