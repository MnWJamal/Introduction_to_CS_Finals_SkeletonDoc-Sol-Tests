#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define N 5

void exam_A1_q4(int mat[N][N], int i, int j);

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int mat[N][N];
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (scanf("%d", &mat[r][c]) != 1) return 1;
        }
    }

    int i, j;
    if (scanf("%d %d", &i, &j) != 2) return 1;

    exam_A1_q4(mat, i, j);

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (c > 0) printf(" ");
            printf("%d", mat[r][c]);
        }
        if (r + 1 < N) printf("\n");
    }
    return 0;
}

void exam_A1_q4(int mat[N][N], int i, int j) {
    // Write your code here.
}
