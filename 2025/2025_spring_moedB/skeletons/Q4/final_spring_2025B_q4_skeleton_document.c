#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q4(int a[], int n, int b[], int m, int k);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    int* arr = malloc((*n) * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, m, k;
    int* a = read_arr(&n);
    int* b = read_arr(&m);
    if (scanf("%d", &k) != 1 || !a || !b) {
        free(a);
        free(b);
        return 1;
    }

    exam_q4(a, n, b, m, k);

    free(a);
    free(b);
    return 0;
}

void exam_q4(int a[], int n, int b[], int m, int k) {
    // Write your code here.
}
