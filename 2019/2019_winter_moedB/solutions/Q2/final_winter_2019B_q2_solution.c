#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindMissingIndex(int arr[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n <= 0) return NULL;

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

    printf("%d", FindMissingIndex(arr, n));

    free(arr);
    return 0;
}
int most_frequent(int d1, int d2, int d3) {
    if (d1 == d2) return d1;
    if (d1 == d3) return d3;
    if (d2 == d3) return d2;
    return d1;
}
int FindMissingIndex(int arr[], int n) {
    int d = most_frequent(arr[1] - arr[0],arr[2] - arr[1], arr[3] - arr[2]);
    int left = 0, right = n-1;
    while (right > left) {
        int middle = (right+ left)/2;
        if (arr[middle] == arr[0] + middle*d) {
            //ok, error idx to the right:
            left = middle+1;
        }
        else {
            right = middle;
        }
    }

    return right;
}
