#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q2(char *s, char *t);

// Do not change read_string!!!
char* read_string(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char* s = malloc((*n + 1) * sizeof(char));
    if (!s) return NULL;
    if (scanf("%s", s) != 1) {
        free(s);
        return NULL;
    }
    return s;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n_s, n_t;
    char* s = read_string(&n_s);
    char* t = read_string(&n_t);
    if (!s || !t) {
        free(s);
        free(t);
        return 1;
    }

    printf("%d", exam_q2(s, t));

    free(s);
    free(t);
    return 0;
}

int exam_q2(char *s, char *t) {
    // Write your code here (you can change the next line):
    return 0;
}
