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
bool legal_cell(char letters[N_ALPH], char matrix[N][M], int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= M) return false;
    for (int letter_id = 0 ; letter_id < N_ALPH ; letter_id++) {
        if (matrix[i][j] == letters[letter_id]) return true;
    }
    return false;
}
int FindLongestPath_aux(char letters[N_ALPH], char matrix[N][M], int i , int j) {
    char val = matrix[i][j];
    matrix[i][j] = 0;
    int max_path = 1;
    int tmp = 0;
    if (legal_cell(letters,matrix,i+1,j)) {
        tmp = FindLongestPath_aux(letters,matrix,i+1,j);
        max_path = (1 + tmp > max_path)? 1 + tmp : max_path;
    }
    if (legal_cell(letters,matrix,i-1,j)) {
        tmp = FindLongestPath_aux(letters,matrix,i-1,j);
        max_path = (1 + tmp > max_path)? 1 + tmp : max_path;
    }
    if (legal_cell(letters,matrix,i,j+1)) {
        tmp = FindLongestPath_aux(letters,matrix,i,j+1);
        max_path = (1 + tmp > max_path)? 1 + tmp : max_path;
    }
    if (legal_cell(letters,matrix,i,j-1)) {
        tmp = FindLongestPath_aux(letters,matrix,i,j-1);
        max_path = (1 + tmp > max_path)? 1 + tmp : max_path;
    }
    matrix[i][j] = val;
    return max_path;
}

int FindLongestPath(char letters[N_ALPH], char matrix[N][M]) {
    int max_path = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < M ; j++) {
            //for each coardinate, if possible, try plant:
            if (legal_cell(letters,matrix,i,j)) {
                int len = FindLongestPath_aux(letters,matrix,i,j);
                max_path = (len > max_path)? len : max_path;
            }
        }
    }
    return max_path;
}
