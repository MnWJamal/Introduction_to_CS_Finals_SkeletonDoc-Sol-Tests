#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void CycleShift(int arr[], int n, int k);

// Do not change read_arr!!!
int* read_arr(int n) {
    if (n <= 0) return NULL;
    int* arr = malloc(n * sizeof(int));
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
    if (scanf("%d %d", &n, &k) != 2) return 1;

    int* arr = read_arr(n);
    if (!arr) return 1;

    CycleShift(arr, n, k);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }

    free(arr);
    return 0;
}

void Reverse(int * arr, int n) {
    for (int i = 0 ; i < n/2 ; i++) {
        int tmp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = tmp;
    }
}


void CycleShift(int arr[], int n, int k) {
    k %= n;
    //NOTE: no even if k>N then O(k) is at worst O(n) because % insure k < n

    if (k < 0) k+= n;
     bool reverse = (k > n/2);
    if (reverse) {
        Reverse(arr,n);
        k = n - k;
    }

    for (int i = 0 ; i < k ; i++) {
        int tmp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = tmp;
    }
    Reverse(arr+k,n - 2*k);
    Reverse(arr,k);
    Reverse(arr+k, n - k);

    if (reverse) Reverse(arr,n);
}
