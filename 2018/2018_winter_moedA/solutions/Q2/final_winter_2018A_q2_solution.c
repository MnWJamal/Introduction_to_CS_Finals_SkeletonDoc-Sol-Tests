#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int count_occurences(int arr[], int n, int x);

// Do not change read_arr!!!
int* read_arr(int n) {
    if (n <= 0) return NULL;
    int* arr = malloc(n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++) {
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

    int n, x;
    if (scanf("%d %d", &n, &x) != 2) return 1;
    if (n < 0) return 1;

    int* arr = read_arr(n);
    if (n > 0 && !arr) return 1;

    printf("%d", count_occurences(arr, n, x));

    free(arr);
    return 0;
}

int count_occurences(int arr[], int n, int x) {
    int right = n-1, left = 0;
    int first = -1, last = -1;
    while (right > left) {
        int middle = (right + left) / 2;
        if (arr[middle] >= x) {
            right = middle;
        }
        else left = middle+1;
    }
    if (arr[right] == x) {
        first = right;
        last = right;
    }
    else return 0;
    left = 0;
    right = n-1;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if (arr[middle] <= x) {
            left = middle;
        }
        else right = middle-1;
    }
    if (arr[right] == x) last = right;
    else last = left;
    return (last - first + 1);
}
