#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindMaxSlimSubstring(char* str1, char* str2);

char* read_string_by_length(int n) {
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

    int n1, n2;
    if (scanf("%d %d", &n1, &n2) != 2) return 1;
    char* str1 = read_string_by_length(n1);
    if (!str1) return 1;
    char* str2 = read_string_by_length(n2);
    if (!str2) {
        free(str1);
        return 1;
    }

    printf("%d", FindMaxSlimSubstring(str1, str2));
    free(str1);
    free(str2);
    return 0;
}

int FindMaxSlimSubstring(char* str1, char* str2) {
    // Write your code here (you can change the next line):
    return 0;
}
