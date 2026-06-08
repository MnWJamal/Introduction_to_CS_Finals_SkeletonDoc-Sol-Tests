#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int q3(int array[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    int* array = malloc((*n) * sizeof(int));
    if (!array) return NULL;
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", array + i) != 1) {
            free(array);
            return NULL;
        }
    }
    return array;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();
    int n;
    int* array = read_arr(&n);
    if (!array) return 1;
    printf("%d", q3(array, n));
    free(array);
    return 0;
}

int q3(int array[], int n) {
    // Write your code here (you can change the next line):
    return 0;
}
