#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 8
#define N 7
#define SIZE (M * N)

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void sort(int mat[M][N], int sorted[SIZE]);

// Do not change main!!!
// Uncomment the first line in main if you don't know the answer.
int main() {
    // printIDontKnow();

    int mat[M][N];
    int sorted[SIZE];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &mat[i][j]) != 1) {
                return 1;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        sorted[i] = 987654321;
    }

    sort(mat, sorted);

    for (int i = 0; i < SIZE; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", sorted[i]);
    }

    return 0;
}

void sort(int mat[M][N], int sorted[SIZE]) {
    // Write your code here
    (void)mat;
    (void)sorted;
}
