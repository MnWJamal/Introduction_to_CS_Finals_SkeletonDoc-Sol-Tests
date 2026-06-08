#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(int **a, int k, int n, int *r);

// Do not change main!!!
//Uncomment the first line in main if you don't know the answer.
int main() {
    // printIDontKnow();
    int k, n;
    if (scanf("%d %d", &k, &n) != 2) return 1;

    int** a = malloc(k * sizeof(int*));
    int* r = malloc(k * sizeof(int));
    if (!a || !r) {
        free(a);
        free(r);
        return 1;
    }

    for (int i = 0; i < k; i++) {
        a[i] = malloc(n * sizeof(int));
        if (!a[i]) {
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            free(r);
            return 1;
        }
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                for (int z = 0; z <= i; z++) free(a[z]);
                free(a);
                free(r);
                return 1;
            }
        }
    }

    exam_q3(a, k, n, r);

    for (int i = 0; i < k; i++) {
        if (i > 0) printf(" ");
        printf("%d", r[i]);
    }

    for (int i = 0; i < k; i++) free(a[i]);
    free(a);
    free(r);
    return 0;
}

int find_delta_of_increasing_array(int * a, int n) {
    if ( n==1 ) return 0;
    int left = 0 , right = n-1;
    while (right >= left) {
        int middle = (right + left)/2;
        int next = middle + 1;
        next %= n;
        int previous = middle - 1;
        previous += (middle < 0)? n : 0;
        if (a[middle] < a[next] && a[middle] < a[previous]) return middle;
        if (a[middle] < a[right]) {
            right = middle -1;
        }
        else left = middle + 1;
    }
    return 0;
}
void exam_q3(int **a, int k, int n, int *r) {
    if (k < 1) return;
    int first_delta = find_delta_of_increasing_array(a[0],n); //O(logn)
    for (int i = 0; i < k ; i++) {
        int last_element = first_delta + i - 1;
        last_element %= n;
        last_element += (last_element < 0)? n : 0;
        r[i] = a[i][last_element];
    }
}
