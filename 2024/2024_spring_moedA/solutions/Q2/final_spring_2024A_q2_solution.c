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
    if(n == 2){
        return arr[0] * pow(arr[1] / arr[0],0.5);
    }
    double q01 = arr[1] / arr[0];
    double q12 = arr[2] / arr[1];
    double absq12 = (q12 < 0)? -1*q12 : q12;
    double absq01 = (q01 < 0)? -1*q01 : q01;
    double q;
    if (absq12 > absq01)
    {
        q = q01;
    }
    else {
        q = q12;
    }
    int left = 0 , right = n-1;
    while (right > left) {
        int middle = (right + left) / 2;
        double supposivly = arr[0] * pow(q,middle);
        if (arr[middle] != supposivly) {
            right = middle;
        }
        else {
            left = middle + 1;
        }
    }
    return arr[0] * pow(q,right);
}
