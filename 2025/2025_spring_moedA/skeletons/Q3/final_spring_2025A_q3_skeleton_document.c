#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(char *s);

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

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    char* s = read_string(n);
    if (!s) return 1;

    exam_q3(s);
    printf("%s", s);
    free(s);
    return 0;
}

void exam_q3(char *s) {
    // Write your code here.
}
