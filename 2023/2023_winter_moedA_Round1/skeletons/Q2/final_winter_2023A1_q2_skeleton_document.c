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

int exam_A1_q2(int arr[], int n, int k) {
    // Write your code here (you can change the next line):
    return 0;
}
