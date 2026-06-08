#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOOM "Boom!"
#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_B_q4(char *players[], char *words[], int n, int k);

char* read_string_by_length() {
    int len;
    if (scanf("%d", &len) != 1) {
        return NULL;
    }
    char* s = (char*)malloc((len + 1) * sizeof(char));
    if (s == NULL) {
        return NULL;
    }
    if (scanf("%s", s) != 1) {
        free(s);
        return NULL;
    }
    return s;
}

void free_strings(char** arr, int n) {
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, k;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    char** players = (char**)malloc(n * sizeof(char*));
    if (players == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        players[i] = read_string_by_length();
        if (players[i] == NULL) {
            free_strings(players, i);
            return 1;
        }
    }

    if (scanf("%d", &k) != 1) {
        free_strings(players, n);
        return 1;
    }
    char** words = (char**)malloc(k * sizeof(char*));
    if (words == NULL) {
        free_strings(players, n);
        return 1;
    }
    for (int i = 0; i < k; i++) {
        words[i] = read_string_by_length();
        if (words[i] == NULL) {
            free_strings(players, n);
            free_strings(words, i);
            return 1;
        }
    }

    printf("%d", exam_B_q4(players, words, n, k));

    free_strings(players, n);
    free_strings(words, k);
    return 0;
}

int exam_B_q4(char *players[], char *words[], int n, int k) {
    // Write your code here (you can change the next line):
    return 0;
}
