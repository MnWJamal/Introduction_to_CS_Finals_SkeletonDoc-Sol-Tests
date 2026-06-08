#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool compare(int a, int b, char c);
int exam_q2(int arr[], int n, char c, int x);

int main(void) {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    int* arr = malloc(n * sizeof(int));
    if (!arr) return 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }
    char c;
    int x;
    if (scanf(" %c%d", &c, &x) != 2) {
        free(arr);
        return 1;
    }
    printf("%d", exam_q2(arr, n, c, x));
    free(arr);
    return 0;
}

bool compare(int a, int b, char c) {
    if (c == 'u') {
        if ( a > b) return true;
        return false;
    }
    else {
        if (b > a) return true;
        return false;
    }
}

int exam_q2(int arr[], int n, char c, int x) {
    int left = 0, right = n-1;
    while (right >= left) {
        int middle = (right + left) / 2;
        if (arr[middle] == x) return middle;
        if (compare(x,arr[middle],c)) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}
