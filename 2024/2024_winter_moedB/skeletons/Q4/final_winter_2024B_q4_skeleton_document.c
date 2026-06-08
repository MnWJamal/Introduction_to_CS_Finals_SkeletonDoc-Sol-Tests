#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q4(int* arr1, int n1, int* arr2, int n2);

int* read_arr(int n) {
    if (n == 0) return NULL;
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
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

    int n1, n2;
    if (scanf("%d", &n1) != 1) return 1;
    int* arr1 = read_arr(n1);
    if (n1 > 0 && !arr1) return 1;

    if (scanf("%d", &n2) != 1) return 1;
    int* arr2 = read_arr(n2);
    if (n2 > 0 && !arr2) return 1;

    printf("%d", exam_q4(arr1, n1, arr2, n2));

    free(arr1);
    free(arr2);
    return 0;
}

int exam_q4(int* arr1, int n1, int* arr2, int n2) {
    // Write your code here
    (void)arr1;
    (void)n1;
    (void)arr2;
    (void)n2;
    return 0;
}
