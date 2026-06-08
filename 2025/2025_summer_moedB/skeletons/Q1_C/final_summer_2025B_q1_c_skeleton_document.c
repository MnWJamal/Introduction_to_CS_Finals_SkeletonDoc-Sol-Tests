#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define MAX_LEN 10

bool read_names(char*** names, int* n);
void free_names(char** names, int n);

int main(void) {
    // printIDontKnow();

    int n;
    char** names;
    if (!read_names(&names, &n)) return 1;
    for (int i = 0; i < n; i++) printf("%s\n", names[i]);
    free_names(names, n);
    return 0;
}

bool read_names(char*** names, int* n) {
    if (!names || !n) return false;
    if (scanf("%d", n) != 1) return NULL;
    *names = malloc(*n * sizeof(char*));
    if (!names) return NULL;
    char* name = malloc(MAX_LEN);
    for (int i = 0; i < *n; i++) (*names)[i] = NULL;

    for (int i = 0; i < *n; i++) {
        (*names)[i] = name;
        if (scanf("%s", (*names)[i]) != 1) {
            free_names((*names), *n);
            return false;
        }
    }
    return true;
}

void free_names(char** names, int n) {
    if (names) {
        for (int i = 0; i < n; i++) {
            if (names[i]) free(names[i]);
        }
    }
    if (names) free(names);
}
