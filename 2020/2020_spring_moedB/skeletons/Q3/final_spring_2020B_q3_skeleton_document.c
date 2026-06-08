#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int ShortestSubstring(char *str);

// Do not change read_str!!!
char* read_str(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char* str = malloc((*n + 1) * sizeof(char));
    if (!str) return NULL;
    for (int i = 0; i < *n; ++i) {
        if (scanf(" %c", str + i) != 1) {
            free(str);
            return NULL;
        }
    }
    str[*n] = '\0';
    return str;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    char* str = read_str(&n);
    if (!str) return 1;
    printf("%d", ShortestSubstring(str));
    free(str);
    return 0;
}

int ShortestSubstring(char *str) {
    // Write your code here (you can change the next line):
    return 0;
}
