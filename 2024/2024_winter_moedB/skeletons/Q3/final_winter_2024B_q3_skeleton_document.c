#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q3(int arr[][2], int n, int* output);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int (*arr)[2] = NULL;
    if (n > 0) {
        arr = malloc(n * sizeof(*arr));
        if (!arr) return 1;
    }

    int output_capacity = 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &arr[i][0], &arr[i][1]) != 2) return 1;
        output_capacity += arr[i][1] - arr[i][0] + 1;
    }

    int* output = (int*)malloc(output_capacity * sizeof(int));
    if (!output) return 1;

    int len = exam_q3(arr, n, output);
    printf("%d", len);
    if (len > 0) {
        printf("\n");
        for (int i = 0; i < len; i++) {
            if (i > 0) printf(" ");
            printf("%d", output[i]);
        }
    }

    free(arr);
    free(output);
    return 0;
}

int exam_q3(int arr[][2], int n, int* output) {
    // Write your code here
    (void)arr;
    (void)n;
    (void)output;
    return 0;
}
