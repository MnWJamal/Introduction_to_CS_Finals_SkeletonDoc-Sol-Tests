#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

double exam_q2(double arr[], int n);

// Do not change read_arr!!!
double* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    double* arr = malloc((*n) * sizeof(double));
    if (!arr) return NULL;
    for (int i = 0; i < *n; i++) {
        if (scanf("%lf", arr + i) != 1) {
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
    double* arr = read_arr(&n);
    if (!arr) return 1;
    printf("%.2f", exam_q2(arr, n));
    free(arr);
    return 0;
}

double exam_q2(double arr[], int n) {
    // Write your code here (you can change the next line):
    return 0.0;
}
