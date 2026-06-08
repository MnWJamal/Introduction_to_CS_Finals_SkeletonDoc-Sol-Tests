#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DONT_KNOW "I_dont_know"
#define MAX_WORD 10000

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int CountPermutations(char* s1, char* s2);

// Do not change read_word!!!
char* read_word() {
    char* str = malloc((MAX_WORD + 1) * sizeof(char));
    if (!str) return NULL;

    if (scanf("%10000s", str) != 1) {
        free(str);
        return NULL;
    }

    return str;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char* s1 = read_word();
    char* s2 = read_word();

    if (!s1 || !s2) {
        free(s1);
        free(s2);
        return 1;
    }

    printf("%d", CountPermutations(s1, s2));

    free(s1);
    free(s2);
    return 0;
}

int CountPermutations(char* s1, char* s2) {
    // Write your code here (you can change the next line):
    return 0;
}
