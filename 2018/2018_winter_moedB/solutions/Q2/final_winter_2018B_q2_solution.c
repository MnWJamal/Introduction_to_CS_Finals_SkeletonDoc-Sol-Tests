#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int meeting_point(int a[], int na, int b[], int nb);

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

    int na, nb;
    if (scanf("%d %d", &na, &nb) != 2) return 1;
    if (na < 0 || nb < 0) return 1;

    int* a = read_arr(na);
    if (na > 0 && !a) return 1;

    int* b = read_arr(nb);
    if (nb > 0 && !b) {
        free(a);
        return 1;
    }

    printf("%d", meeting_point(a, na, b, nb));

    free(a);
    free(b);
    return 0;
}

int meeting_point(int a[], int na, int b[], int nb) {
    int left = 0;
    int right = (na > nb)? nb - 1 : na - 1;
    while (right  - left > 1) {
        int middle = (right+left) / 2;
        int delta = a[middle] - b[middle];
        if (delta > 0) {
            left = middle+1;
        }
        else right = middle;
    }
    if (a[left] == b[left]) return left;
    if (a[right] == b[right]) return right; //maybe unnecessary

    //not found
    return -1;
}
