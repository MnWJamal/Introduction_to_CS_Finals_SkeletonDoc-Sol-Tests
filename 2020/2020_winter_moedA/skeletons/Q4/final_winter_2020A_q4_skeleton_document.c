#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool is_partition_possible(int arr[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;
    if (*n == 0) return malloc(sizeof(int));
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

    int n;
    int* arr = read_arr(&n);
    if (!arr) return 1;
    printf("%d", is_partition_possible(arr, n) ? 1 : 0);
    free(arr);
    return 0;
}

bool is_partition_possible(int arr[], int n) {
    // Write your code here (you can change the next line):
    return false;
}
