#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examB_q2(char **s, int n);

// Do not change read_strings!!!
char **read_strings(int *n) {
    if (scanf("%d", n) != 1) return NULL;

    char **s = malloc((*n) * sizeof(char*));
    if (!s) return NULL;

    for (int i = 0; i < *n; i++) {
        int len;
        if (scanf("%d", &len) != 1) {
            for (int j = 0; j < i; j++) free(s[j]);
            free(s);
            return NULL;
        }

        s[i] = malloc((len + 1) * sizeof(char));
        if (!s[i]) {
            for (int j = 0; j < i; j++) free(s[j]);
            free(s);
            return NULL;
        }

        if (scanf("%s", s[i]) != 1) {
            for (int j = 0; j <= i; j++) free(s[j]);
            free(s);
            return NULL;
        }
    }

    return s;
}

// Do not change free_strings!!!
void free_strings(char **s, int n) {
    if (!s) return;
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    char **s = read_strings(&n);
    if (!s) return 1;

    printf("%d", examB_q2(s, n));

    free_strings(s, n);
    return 0;
}

int examB_q2(char** arr, int n) {
    int lastStr = 0; //The index of the biggest string so far
    int lastShortStr = -1; //The index of the biggest string that's shorter
    //than the current one
    int lastStrLen = strlen(arr[0]);
    for (int i = 1; i < n; i++) {
        int curLen = strlen(arr[i]);
        if(curLen > lastStrLen) {
            lastShortStr = lastStr;
        }
        if(lastShortStr != -1 && strcmp(arr[i], arr[lastShortStr]) < 0) {
            return 0;
        }
        if (strcmp(arr[i], arr[lastStr]) > 0) {
            lastStr = i;
            lastStrLen = curLen;
        }
    }
    return 1;
}