#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool q2(int arr[], int n, int min, int max);

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
    int n, min, max;
    int* arr = read_arr(&n);
    if (!arr) return 1;
    if (scanf("%d%d", &min, &max) != 2) {
        free(arr);
        return 1;
    }
    printf("%s", q2(arr, n, min, max) ? "true" : "false");
    free(arr);
    return 0;
}

bool q2(int arr[], int n, int min, int max) {
    // Write your code here (you can change the next line):
    return false;
}
