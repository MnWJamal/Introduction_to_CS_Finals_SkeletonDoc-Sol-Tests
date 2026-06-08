#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool exam_q4(char *word1, char *word2);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 1;

    char* word1 = malloc((n + 1) * sizeof(char));
    char* word2 = malloc((m + 1) * sizeof(char));
    if (!word1 || !word2) {
        free(word1);
        free(word2);
        return 1;
    }

    if (scanf("%s", word1) != 1 || scanf("%s", word2) != 1) {
        free(word1);
        free(word2);
        return 1;
    }

    printf("%s", exam_q4(word1, word2) ? "true" : "false");
    free(word1);
    free(word2);
    return 0;
}

bool exam_q4(char *word1, char *word2) {
    // Write your code here (you can change the next line):
    return false;
}
