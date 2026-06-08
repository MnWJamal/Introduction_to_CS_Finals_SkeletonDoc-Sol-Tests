#include <stdio.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"
#define MAX_STR_LEN 30

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q2(char** a, int n, int k, char* output);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 1;

    char** a = (char**)malloc(n * sizeof(char*));
    if (!a) return 1;

    for (int i = 0; i < n; i++) {
        a[i] = (char*)malloc((MAX_STR_LEN + 1) * sizeof(char));
        if (!a[i]) {
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            return 1;
        }
        if (scanf("%30s", a[i]) != 1) {
            for (int j = 0; j <= i; j++) free(a[j]);
            free(a);
            return 1;
        }
    }

    char* output = (char*)malloc((MAX_STR_LEN * n + 1) * sizeof(char));
    if (!output) {
        for (int i = 0; i < n; i++) free(a[i]);
        free(a);
        return 1;
    }

    exam_q2(a, n, k, output);
    printf("%s", output);

    free(output);
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;
}

void exam_q2(char** a, int n, int k, char* output) {
    // Write your code here:
    output[0] = '\0';
}
