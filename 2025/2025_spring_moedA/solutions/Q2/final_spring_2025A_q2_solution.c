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
double delta(double a, double b) {
    double delta = b - a;
    delta = (delta < 0)? -1*delta : delta;
    return delta;
}
double exam_q2(double arr[], int n, int k, double x) {
    int left = 0, right = n-1;
    while (right > left) {
        int middle = (right + left) / 2;
        if (arr[middle] >= x) {
            right = middle;
        }
        else {
            left = middle+1;
        }
    }
    int fits = right; //fits is where x would have been in array
    int taken_from_right = 0;
    int taken_from_left = 0;
    double sum_of_deltas = 0;
    while (taken_from_right + taken_from_left < k) {
        double deltaR = -1, deltaL = -1; //-1 for non-delta
        if (fits + taken_from_right < n) {
            //can take from right? calculate delta
            deltaR = delta(arr[fits+taken_from_right],x);
        }
        if (fits - 1 - taken_from_left >= 0) {
            //can take from left? calculate delta
            deltaL = delta(arr[fits-1-taken_from_left],x);
        }
        if (deltaL == -1 && deltaR == -1) {
            //cant take more numbers, apparently n < k
            return sum_of_deltas;
        }
        else if (deltaL == -1) {
            sum_of_deltas += deltaR;
            taken_from_right++;
        }
        else if (deltaR == -1) {
            sum_of_deltas += deltaL;
            taken_from_left++;
        }
        else {
            if (deltaR > deltaL) {
                sum_of_deltas += deltaL;
                taken_from_left++;
            }
            else {
                sum_of_deltas += deltaR;
                taken_from_right++;
            }
        }
    }
    return sum_of_deltas;
}
