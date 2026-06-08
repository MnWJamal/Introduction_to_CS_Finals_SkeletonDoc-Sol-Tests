#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

double exam_q2(double arr[], int n, int k, double x);

// Do not change read_arr!!!
double* read_arr(int n) {
    double* arr = (double*)malloc(n * sizeof(double));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++) {
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

    int n, k;
    double x;
    if (scanf("%d", &n) != 1) return 1;
    double* arr = read_arr(n);
    if (!arr) return 1;
    if (scanf("%d%lf", &k, &x) != 2) {
        free(arr);
        return 1;
    }

    printf("%.1f", exam_q2(arr, n, k, x));
    free(arr);
    return 0;
}

double exam_q2(double arr[], int n, int k, double x) {
    // Write your code here (you can change the next line):
    return 0.0;
}
