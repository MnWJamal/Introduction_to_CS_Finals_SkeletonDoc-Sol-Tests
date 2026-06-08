#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(int **a, int k, int n, int *r);

// Do not change main!!!
//Uncomment the first line in main if you don't know the answer.
int main() {
    // printIDontKnow();

    int k, n;
    if (scanf("%d %d", &k, &n) != 2) return 1;

    int** a = malloc(k * sizeof(int*));
    int* r = malloc(k * sizeof(int));
    if (!a || !r) {
        free(a);
        free(r);
        return 1;
    }

    for (int i = 0; i < k; i++) {
        a[i] = malloc(n * sizeof(int));
        if (!a[i]) {
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            free(r);
            return 1;
        }
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                for (int z = 0; z <= i; z++) free(a[z]);
                free(a);
                free(r);
                return 1;
            }
        }
    }

    exam_q3(a, k, n, r);

    for (int i = 0; i < k; i++) {
        if (i > 0) printf(" ");
        printf("%d", r[i]);
    }

    for (int i = 0; i < k; i++) free(a[i]);
    free(a);
    free(r);
    return 0;
}

void exam_q3(int **a, int k, int n, int *r) {
    // Write your code here.
}
