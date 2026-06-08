#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examA_q2(char** arr, int n, int m);

char** read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char** arr = malloc((*n) * sizeof(char*));
    if (!arr) return NULL;

    for (int i = 0; i < *n; i++) {
        int len;
        if (scanf("%d", &len) != 1) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }

        arr[i] = malloc((len + 1) * sizeof(char));
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }

        if (scanf("%s", arr[i]) != 1) {
            for (int j = 0; j <= i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
    }

    return arr;
}

void free_arr(char** arr, int n) {
    if (!arr) return;
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    char** arr = read_arr(&n);
    if (!arr) return 1;

    int m;
    if (scanf("%d", &m) != 1) {
        free_arr(arr, n);
        return 1;
    }

    printf("%d", examA_q2(arr, n, m));
    free_arr(arr, n);
    return 0;
}

int examA_q2(char** arr, int n, int m) {
    // Write your code here (you can change the next line):
    return 0;
}
