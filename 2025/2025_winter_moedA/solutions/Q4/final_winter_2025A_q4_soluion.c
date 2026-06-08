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

bool CanGoUp(int i, int j, int mat[N][N]) {
    return (i > 0 && mat[i-1][j] != 0);
}
bool CanGoDown(int i, int j, int mat[N][N]) {
    return (i < N-1 && mat[i+1][j] != 0);
}
bool CanGoLeft(int i, int j, int mat[N][N]) {
    return (j > 0 && mat[i][j-1] != 0);
}
bool CanGoRight(int i, int j, int mat[N][N]) {
    return (j < N-1 && mat[i][j+1] != 0);
}
int examA_q4_aux(int mat[N][N], int i, int j) {
    if (i == N-1 && j == N-1) return mat[i][j];
    int min_path = -1; //DNE
    bool found_path = false;
    int val = mat[i][j];
    mat[i][j] = 0;
    if (CanGoUp(i,j,mat)) {
        int path = examA_q4_aux(mat,i - 1,j);
        if (path != -1) {
            if (!found_path) {
                found_path = true;
                min_path = val + path;
            }
            else
                min_path = (val + path < min_path)? val + path : min_path;
        }
    }
    if (CanGoDown(i,j,mat)) {
        int path = examA_q4_aux(mat,i + 1,j);
        if (path != -1) {
            if (!found_path) {
                found_path = true;
                min_path = val + path;
            }
            else
                min_path = (val + path < min_path)? val + path : min_path;
        }
    }
    if (CanGoRight(i,j,mat)) {
        int path = examA_q4_aux(mat,i,j + 1);
        if (path != -1) {
            if (!found_path) {
                found_path = true;
                min_path = val + path;
            }
            else
                min_path = (val + path < min_path)? val + path : min_path;
        }
    }
    if (CanGoLeft(i,j,mat)) {
        int path = examA_q4_aux(mat,i,j - 1);
        if (path != -1) {
            if (!found_path) {
                found_path = true;
                min_path = val + path;
            }
            else
                min_path = (val + path < min_path)? val + path : min_path;
        }
    }
    //backtrack:
    mat[i][j] = val;

    //if didnt find path will still be DNE
    return min_path;
}
int examA_q4(int mat[N][N]) {
    // Write your code here (you can change the next line):
    return examA_q4_aux(mat,0,0);
}
