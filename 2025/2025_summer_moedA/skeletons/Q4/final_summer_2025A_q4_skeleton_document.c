#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define N 2
#define K 6

int exam_q4(int mat1[N * 5][3], int mat2[K][K]);

int main(void) {
    // printIDontKnow();

    int mat1[N * 5][3];
    int mat2[K][K];
    for (int i = 0; i < N * 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &mat1[i][j]) != 1) return 1;
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (scanf("%d", &mat2[i][j]) != 1) return 1;
        }
    }
    printf("%d", exam_q4(mat1, mat2));
    return 0;
}

int exam_q4(int mat1[N * 5][3], int mat2[K][K]) {
    return 0;
}
