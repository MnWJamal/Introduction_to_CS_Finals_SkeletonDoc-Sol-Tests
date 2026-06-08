#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void stable_shuffle(int arr[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n <= 0) return NULL;

    int* arr = malloc((*n) * sizeof(int));
    if (!arr) return NULL;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

// Do not change print_arr!!!
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* arr = read_arr(&n);
    if (!arr) return 1;

    stable_shuffle(arr, n);
    print_arr(arr, n);

    free(arr);
    return 0;
}

void ReverseArray(int * arr, int length){
    for(int i = 0 ; i < length/2 ; i++) {
        int tmp = arr[i];
        arr[i] = arr[length-1-i];
        arr[length-1-i] = tmp;
    }
}
void stable_shuffle(int arr[], int n) {
    if (n <= 2) {
        return;
    }
    stable_shuffle(arr,n/2);
    stable_shuffle(arr + n/2, n/2);


    ReverseArray(arr+n/4,n/2);
    ReverseArray(arr+n/4,n/4);
    ReverseArray(arr+n/2,n/4);

}
