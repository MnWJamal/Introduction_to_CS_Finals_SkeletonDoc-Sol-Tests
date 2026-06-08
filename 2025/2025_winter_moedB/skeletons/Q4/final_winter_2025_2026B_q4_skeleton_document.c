#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
#define N 5

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examB_q4(char mat[N][N]);

// Do not change read_mat!!!
bool read_mat(char mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf(" %c", &mat[i][j]) != 1) return false;
        }
    }
    return true;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char mat[N][N];
    if (!read_mat(mat)) return 1;

    printf("%d", examB_q4(mat));
    return 0;
}

void get_next_location(int i, int j, int* next_i, int* next_j, char direction) {
    switch(direction) {
        case 'R':
            *next_i = i;
        *next_j = j + 1;
        break;
        case 'L':
            *next_i = i;
        *next_j = j - 1;
        break;
        case 'U':
            *next_i = i - 1;
            *next_j = j;
            break;
        case 'D':
            *next_i = i + 1;
            *next_j = j;
            break;
    }
}

int examB_q4(char mat[N][N]) {
    // Write your code here (you can change the next line):
    return 0;
}
