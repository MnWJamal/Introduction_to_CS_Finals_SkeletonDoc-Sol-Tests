#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool IsKSplittable(int arr[], int n, int k);

// Do not change read_arr!!!
int* read_arr(int* n, int* k) {
    if (scanf("%d %d", n, k) != 2) return NULL;
    if (*n < 0) return NULL;
    int* arr = malloc(((*n) > 0 ? (*n) : 1) * sizeof(int));
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

    int n, k;
    int* arr = read_arr(&n, &k);
    if (!arr) return 1;
    printf("%d", IsKSplittable(arr, n, k) ? 1 : 0);
    free(arr);
    return 0;
}

bool IsKSplittable(int arr[], int n, int k) {
    // Write your code here (you can change the next line):
    return false;
}
