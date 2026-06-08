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

int count_solutions(int grid[N*N][N*N]) {
    // Write your code here (you can change the next line):
    return 0;
}
