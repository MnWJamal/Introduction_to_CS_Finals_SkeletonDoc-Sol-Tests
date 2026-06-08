#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindFixedPoint(int a[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;
    int* arr = malloc(((*n) > 0 ? (*n) : 1) * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

// Do not change valid_answer!!!
int valid_answer(int ans, int a[], int n) {
    if (ans == -1) {
        for (int i = 0; i < n; i++) {
            if (a[i] == i) return 0;
        }
        return 1;
    }
    if (ans < 0 || ans >= n) return 0;
    return a[ans] == ans;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* arr = read_arr(&n);
    if (!arr) return 1;
    int ans = FindFixedPoint(arr, n);
    printf("%d", valid_answer(ans, arr, n));
    free(arr);
    return 0;
}

int FindFixedPoint(int a[], int n) {
    int right = n-1, left = 0;
    while (right >= left) {
        int middle = (right+left)/2;
        if (a[middle] == middle) return middle;
        if (a[middle] > middle) {
            //all points from middle to right will also be: a[i] > i
            //so we cut right side:
            right = middle-1;
        }
        else {
            //all points left of middle will also be a[i] < i
            //since i decreases by 1 and a decreases by >= 1
            left = middle + 1;
        }
    }
    //not found:
    return -1;
}
