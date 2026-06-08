#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int pow2(int k) {
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= 2;
    }
    return result;
}

int exam_B_q2(int arr[], int n, int x);

int* read_arr(int n) {
    if (n <= 0) {
        return NULL;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, x;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int* arr = read_arr(n);
    if (n > 0 && arr == NULL) {
        return 1;
    }
    if (scanf("%d", &x) != 1) {
        free(arr);
        return 1;
    }
    printf("%d", exam_B_q2(arr, n, x));
    free(arr);
    return 0;
}

int exam_B_q2(int arr[], int n, int x) {
    // Write your code here (you can change the next line):
    return -1;
}
