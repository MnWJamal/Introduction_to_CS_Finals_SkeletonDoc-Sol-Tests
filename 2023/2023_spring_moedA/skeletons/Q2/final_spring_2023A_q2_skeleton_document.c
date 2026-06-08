#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int q2(char *arr[], int n);

// Do not change read_arr!!!
char** read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char** arr = malloc((*n) * sizeof(char*));
    if (!arr) return NULL;
    for (int i = 0; i < *n; i++) {
        arr[i] = malloc(31 * sizeof(char));
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
        if (scanf("%30s", arr[i]) != 1) {
            for (int j = 0; j <= i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
    }
    return arr;
}

// Do not change free_arr!!!
void free_arr(char** arr, int n) {
    if (!arr) return;
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();
    int n;
    char** arr = read_arr(&n);
    if (!arr) return 1;
    printf("%d", q2(arr, n));
    free_arr(arr, n);
    return 0;
}

int q2(char *arr[], int n) {
    // Write your code here (you can change the next line):
    return 0;
}
