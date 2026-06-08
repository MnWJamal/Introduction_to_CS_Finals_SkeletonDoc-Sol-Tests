#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3
#define M 4
#define N_ALPH 2

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindLongestPath(char letters[N_ALPH], char matrix[N][M]);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char letters[N_ALPH];
    char matrix[N][M];

    for (int i = 0; i < N_ALPH; i++) {
        if (scanf(" %c", &letters[i]) != 1) return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf(" %c", &matrix[i][j]) != 1) return 1;
        }
    }

    printf("%d", FindLongestPath(letters, matrix));
    return 0;
}

int FindLongestPath(char letters[N_ALPH], char matrix[N][M]) {
    // Write your code here (you can change the next line):
    return 0;
}
