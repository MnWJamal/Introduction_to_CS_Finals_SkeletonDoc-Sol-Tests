#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

char* exam_q3(char* s1, char* s2);

char* read_string(void) {
    int n;
    if (scanf("%d", &n) != 1) return NULL;
    char* s = malloc((n + 1) * sizeof(char));
    if (!s) return NULL;
    if (scanf("%s", s) != 1) {
        free(s);
        return NULL;
    }
    return s;
}

int main(void) {
    // printIDontKnow();

    char* s1 = read_string();
    if (!s1) return 1;
    char* s2 = read_string();
    if (!s2) {
        free(s1);
        return 1;
    }
    char* result = exam_q3(s1, s2);
    if (!result) {
        free(s1);
        free(s2);
        return 1;
    }
    printf("%s", result);
    free(result);
    free(s1);
    free(s2);
    return 0;
}

char* exam_q3(char* s1, char* s2) {
    return NULL;
}
