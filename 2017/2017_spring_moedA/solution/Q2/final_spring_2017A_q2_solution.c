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

int * Merge(int * arr1, int len1, int * arr2 , int len2) {
    if (!arr1 || !arr2) return 0; //null arrays
    int * res = malloc((len1 + len2) * sizeof(int));
    if (!res) return 0; //null ptr for error in allocation
    int i1 = 0, i2 = 0, p = 0;
    while (i1 < len1 && i2 < len2) {
        if (arr1[i1] < arr2[i2]) {
            res[p] = arr1[i1];
            i1++;
        }
        else {
            res[p] = arr2[i2];
            i2++;
        }
        p++;
    }

    while (i1 < len1) {
        res[p] = arr1[i1];
        i1 ++;
        p ++;
    }

    while (i2 < len2) {
        res[p] = arr2[i2];
        i2 ++;
        p ++;
    }

    return res;
}


void sort(int mat[M][N], int sorted[SIZE]) {
    int ** helper = malloc(M*sizeof(int*));
    if (!helper) return;
    for (int i = 0 ; i < M ; i ++) {
        helper[i] = malloc(N*sizeof(int));
        if (!helper[i]) return;
        for (int j = 0 ; j < N ; j++) {
            (helper[i])[j] = mat[i][j];
        }
    }


    for (int rows = 2 ; rows <= M ; rows *= 2) {
        for (int r = 0 ; r < M ; r += rows) {
            int * result = Merge(helper[r],N*(rows/2), helper[r + (rows/2)], N*(rows/2));
            if (!result) return;
            free(helper[r]);
            free(helper[r + (rows/2)]);
            helper[r] = result;
        }

    }
    //at this stage all helper[i] (i x= 0) are freed and array
    //is sorted in helper[0], we copy to sorted and free
    for (int i = 0 ; i < SIZE ; i++) {
        sorted[i] = helper[0][i];
    }
    free(helper[0]);
    free(helper);
}