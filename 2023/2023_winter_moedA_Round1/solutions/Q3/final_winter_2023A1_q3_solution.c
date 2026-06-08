#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_A1_q3(int arr[], int n, int k);

int validate_remainder_order(int arr[], int n, int k) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] % k > arr[i] % k) return 0;
    }
    return 1;
}

int validate_same_values(int before[], int after[], int n) {
    int *used = calloc(n, sizeof(int));
    if (!used) return 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (!used[j] && before[i] == after[j]) {
                used[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            free(used);
            return 0;
        }
    }
    free(used);
    return 1;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int *arr = malloc(n * sizeof(int));
    int *before = malloc(n * sizeof(int));
    if (!arr || !before) {
        free(arr);
        free(before);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            free(before);
            return 1;
        }
        before[i] = arr[i];
    }

    int k;
    if (scanf("%d", &k) != 1) {
        free(arr);
        free(before);
        return 1;
    }

    exam_A1_q3(arr, n, k);
    int ok = validate_remainder_order(arr, n, k) && validate_same_values(before, arr, n);
    printf("%d", ok);

    free(arr);
    free(before);
    return 0;
}
void Swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void exam_A1_q3(int arr[], int n, int k) {
    int p = 0;
    for (int remainder = 0 ; remainder < k ; remainder++) {
        for (int i = 0 ; i < n ; i++) {
            if (arr[i] % k == remainder) {
                Swap(arr + i, arr + p);
                p++;
            }
        }
    }
}
