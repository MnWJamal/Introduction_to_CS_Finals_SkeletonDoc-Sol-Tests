#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int CountChars(char * str, int n, char c);
bool AreEqual(char * s1, char * s2, int n);

// Do not change read_small_string!!!
char* read_small_string(int n) {
    if (n < 0) return NULL;
    char* str = malloc((n + 1) * sizeof(char));
    if (!str) return NULL;

    for (int i = 0; i < n; i++) {
        if (scanf(" %c", str + i) != 1) {
            free(str);
            return NULL;
        }
    }
    str[n] = '\0';
    return str;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int mode;
    if (scanf("%d", &mode) != 1) return 1;

    if (mode == 1) {
        int n;
        char c;
        if (scanf("%d %c", &n, &c) != 2) return 1;
        char* str = read_small_string(n);
        if (!str) return 1;
        printf("%d", CountChars(str, n, c));
        free(str);
        return 0;
    }

    if (mode == 2) {
        int n;
        if (scanf("%d", &n) != 1) return 1;
        char* s1 = read_small_string(n);
        char* s2 = read_small_string(n);
        if (!s1 || !s2) {
            free(s1);
            free(s2);
            return 1;
        }
        printf("%d", AreEqual(s1, s2, n) ? 1 : 0);
        free(s1);
        free(s2);
        return 0;
    }

    return 1;
}

int CountChars(char * str, int n, char c) {
    // Write your code here (you can change the next line):
    return 0;
}

bool AreEqual(char * s1, char * s2, int n) {
    // Write your code here (you can change the next line):
    return false;
}
