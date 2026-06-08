#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examA_q3(int a[], int n, int m, int b[]);

int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    int* arr = malloc((*n) * sizeof(int));
    if (!arr) return NULL;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
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
    int* a = read_arr(&n);
    if (!a) return 1;

    int m;
    if (scanf("%d", &m) != 1) {
        free(a);
        return 1;
    }

    int* b = malloc(n * sizeof(int));
    if (!b) {
        free(a);
        return 1;
    }

    int result = examA_q3(a, n, m, b);
    printf("%d\n", result);
    for (int i = 0; i < result; i++) {
        printf("%d ", b[i]);
    }

    free(a);
    free(b);
    return 0;
}


#define ERROR_IN_MALLOC (-1)
#define UNASSIGNED_FREQUENCY (-1)
void SetDefault(int * arr, int n, int value) {
    if (!arr) return;
    for (int i = 0 ; i < n ; i++) arr[i] = value;
}
int examA_q3(int a[], int n, int m, int b[]) {
    int * Hist = malloc((m+1)*sizeof(int));
    int * Frequencies = malloc((n+1)*sizeof(int));
    if (!Hist || !Frequencies) {
        if (Frequencies) free(Frequencies);
        if (Hist) free(Hist);
        return ERROR_IN_MALLOC;
    }
    SetDefault(Hist,m+1,0);
    SetDefault(Frequencies,n+1,UNASSIGNED_FREQUENCY);
    for (int i = 0 ; i < n ; i++) {
        Hist[a[i]]++;
    }
    for (int i = 0 ; i <= m ; i++) {
        if (Hist[i] > 0) {
            Frequencies[Hist[i]] = i;
        }
    }
    int p = 0;
    for (int i = 0 ; i < n+1 ; i++) {
        if (Frequencies[i] != UNASSIGNED_FREQUENCY) {
            b[p] = Frequencies[i];
            p++;
        }
    }
    free(Hist);
    free(Frequencies);
    return p;
}
