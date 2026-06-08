#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int q3(int* a[], int n, int m);

// Do not change read_matrix!!!
int** read_matrix(int* n, int* m) {
    if (scanf("%d%d", n, m) != 2) return NULL;
    int** arr = malloc((*n) * sizeof(int*));
    if (!arr) return NULL;
    for (int i = 0; i < *n; i++) {
        arr[i] = malloc((*m) * sizeof(int));
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
        for (int j = 0; j < *m; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                for (int k = 0; k <= i; k++) free(arr[k]);
                free(arr);
                return NULL;
            }
        }
    }
    return arr;
}

// Do not change free_matrix!!!
void free_matrix(int** arr, int n) {
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();
    int n, m;
    int** arr = read_matrix(&n, &m);
    if (!arr) return 1;
    printf("%d", q3(arr, n, m));
    free_matrix(arr, n);
    return 0;
}

int q3(int* a[], int n, int m) {
    // Write your code here (you can change the next line):
    return 0;
}
