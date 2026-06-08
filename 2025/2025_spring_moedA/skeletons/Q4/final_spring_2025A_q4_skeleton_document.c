#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q4(char *arr[], int n);

// Do not change read_string!!!
char* read_string(int n) {
    char* s = (char*)malloc((n + 1) * sizeof(char));
    if (!s) return NULL;

    int c = getchar();
    while (c == '\n' || c == '\r') {
        c = getchar();
    }
    if (c == EOF) {
        free(s);
        return NULL;
    }
    s[0] = (char)c;

    for (int i = 1; i < n; i++) {
        c = getchar();
        if (c == EOF) {
            free(s);
            return NULL;
        }
        s[i] = (char)c;
    }
    s[n] = '\0';
    return s;
}

// Do not change read_arr!!!
char** read_arr(int n) {
    char** arr = (char**)malloc(n * sizeof(char*));
    if (!arr) return NULL;

    for (int i = 0; i < n; i++) {
        int len;
        if (scanf("%d", &len) != 1) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
        arr[i] = read_string(len);
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
    }
    return arr;
}

// Do not change free_arr!!!
void free_arr(char *arr[], int n) {
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
    if (scanf("%d", &n) != 1) return 1;
    char** arr = read_arr(n);
    if (!arr) return 1;

    exam_q4(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%s", arr[i]);
        if (i < n - 1) printf("\n");
    }

    free_arr(arr, n);
    return 0;
}

void exam_q4(char *arr[], int n) {
    // Write your code here.
}
