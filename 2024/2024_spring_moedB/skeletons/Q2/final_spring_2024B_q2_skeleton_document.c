#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
#define MAX_STRING_LENGTH 1000

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q2(char* arr[], int n, char* str);

// Do not change read_word!!!
char* read_word() {
    char buffer[MAX_STRING_LENGTH + 1];
    if (scanf("%1000s", buffer) != 1) return NULL;
    int len = 0;
    while (buffer[len] != '\0') len++;
    char* word = (char*)malloc((len + 1) * sizeof(char));
    if (!word) return NULL;
    for (int i = 0; i <= len; i++) {
        word[i] = buffer[i];
    }
    return word;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    char** arr = (char**)malloc(n * sizeof(char*));
    if (!arr) return 1;

    for (int i = 0; i < n; i++) {
        arr[i] = read_word();
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return 1;
        }
    }

    char* str = read_word();
    if (!str) {
        for (int i = 0; i < n; i++) free(arr[i]);
        free(arr);
        return 1;
    }

    printf("%d", exam_q2(arr, n, str));

    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    free(str);
    return 0;
}

int exam_q2(char* arr[], int n, char* str) {
    // Write your code here (you can change the next line):
    return 0;
}
