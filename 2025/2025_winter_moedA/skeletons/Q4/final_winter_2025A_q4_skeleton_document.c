#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5
#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examA_q4(int mat[N][N]);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int mat[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &mat[i][j]) != 1) return 1;
        }
    }

    printf("%d", examA_q4(mat));
    return 0;
}

int examA_q4(int mat[N][N]) {
    // Write your code here (you can change the next line):
    return 0;
}
