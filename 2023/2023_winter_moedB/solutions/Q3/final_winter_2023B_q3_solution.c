#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_B_q3(int mat[N][N], int x);

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int mat[N][N];
    int x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &mat[i][j]) != 1) {
                return 1;
            }
        }
    }
    if (scanf("%d", &x) != 1) {
        return 1;
    }
    printf("%d", exam_B_q3(mat, x));
    return 0;
}


void calc_sums(int mat[N][N], int sums[N][N]){
    for (int  i = 0; i < N; i++){
        sums[i][0] = mat[i][0];
        sums[0][i] = mat[0][i];
        if(i > 0) {
            sums[i][0] += sums[i - 1][0];
            sums[0][i] += sums[0][i - 1];
        }
    }

    for(int i = 1; i < N; i++){
        for( int j = 1; j < N; j++){
            sums[i][j] = mat[i][j] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
        }
    }
}


int exam_B_q3(int mat[N][N], int x) {
    int count = 0;
    int sums[N][N] = {{0}};
    calc_sums(mat, sums);

    for(int size = 1; size <= N; size++){
        for(int i = 0; i + size <= N; i++){
            for(int j = 0; j + size <= N; j++){
                int full_square = sums[i+size-1][j+size-1];
                int up_sum = (i>0)? sums[i-1][j+size-1]: 0;
                int left_sum = (j > 0)? sums[i+size-1][j-1]: 0;
                int upper_left_sum = (i > 0 && j > 0)? sums[i-1][j-1] : 0;

                int square_sum = full_square - (up_sum + left_sum) + upper_left_sum;
                if (square_sum == x) count ++;
            }
        }
    }
    return count;
}
