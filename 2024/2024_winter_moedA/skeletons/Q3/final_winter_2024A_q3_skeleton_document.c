#include <stdio.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(int* arr, int n, int a, int b, int c);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int* arr = NULL;
    if (n > 0) {
        arr = (int*)malloc(n * sizeof(int));
        if (!arr) return 1;
        for (int i = 0; i < n; i++) {
            if (scanf("%d", arr + i) != 1) {
                free(arr);
                return 1;
            }
        }
    }

    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        free(arr);
        return 1;
    }

    exam_q3(arr, n, a, b, c);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }

    free(arr);
    return 0;
}

void exam_q3(int* arr, int n, int a, int b, int c) {
    // Write your code here:
}
