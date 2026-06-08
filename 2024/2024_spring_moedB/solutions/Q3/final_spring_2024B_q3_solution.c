#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(int arr[], int dest[], int n, int k);

// Do not change read_arr!!!
int* read_arr(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
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
    if (scanf("%d", &n) != 1) return 1;
    int* arr = read_arr(n);
    if (!arr) return 1;
    if (scanf("%d", &k) != 1) {
        free(arr);
        return 1;
    }

    int* dest = (int*)malloc(k * sizeof(int));
    if (!dest) {
        free(arr);
        return 1;
    }
    for (int i = 0; i < k; i++) dest[i] = 0;

    exam_q3(arr, dest, n, k);

    int printed = 0;
    for (int i = 0; i < k; i++) {
        if (dest[i] > 0) {
            if (printed) printf(" ");
            printf("%d", dest[i]);
            printed++;
        }
    }

    free(arr);
    free(dest);
    return 0;
}

void exam_q3(int arr[], int dest[], int n, int k) {
    bool * Hist = malloc(k*sizeof(bool));
    if (!Hist) return; //if forgot malloc check -2
    //can make function int and return error status
    for (int i = 0 ; i < k ; i++) Hist[i] = false;
    for (int i = 0 ; i < n ; i++) {
        if (arr[i] < k) Hist[arr[i]] = true;
    }
    int p = 0;
    for (int i = 0 ; i < k ; i++) {
        if (Hist[i]) {
            dest[p] = i;
            p++;
        }
    }
    free(Hist); //if forgot free -2
}
