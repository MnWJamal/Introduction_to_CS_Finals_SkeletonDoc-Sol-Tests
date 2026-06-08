#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_A1_q2(int arr[], int n, int k);

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int *arr = malloc(n * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    int k;
    if (scanf("%d", &k) != 1) {
        free(arr);
        return 1;
    }

    printf("%d", exam_A1_q2(arr, n, k));
    free(arr);
    return 0;
}

int BinarySearchForMax(int arr[], int n) {
    int left = 0 , right = n-1;
    if (n == 1) return 0;
    while (right >= left) {
        int middle = (right + left) / 2;
        if (middle == 0 ) {
            if (arr[0] > arr[1]) return 0;
            else {
                left = middle + 1;
            }
        }
        else if (middle == n-1) {
            if (arr[n-2] < arr[n-1])return n-1;
            else right = middle - 1;
        }
        else {
            if (arr[middle - 1] < arr[middle] && arr[middle] > arr[middle+1])
                return middle;
            else if (arr[middle - 1] < arr[middle] && arr[middle] < arr[middle + 1])
                left = middle + 1;
            else {
                right = middle - 1;
            }
        }
    }
    return -1;
}
int exam_A1_q2(int arr[], int n, int k) {
    int max_idx = BinarySearchForMax(arr,n);
    int between_first_and_max = arr[max_idx] - arr[0] + 1;
    if (k < between_first_and_max) {
        return arr[0] + k;
    }
    else {
        k -= (between_first_and_max - 1);
        int between_max_and_last = arr[max_idx] - arr[n - 1] + 1;
        if (k < between_max_and_last) {
            return arr[max_idx] - k;
        }
        else {
            return -1;
        }
    }
}
