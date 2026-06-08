#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STR_LEN 10000

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int GetKShortSubstring(char *str, int k);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int k;
    char* str = malloc((MAX_STR_LEN + 1) * sizeof(char));
    if (!str) return 1;

    if (scanf("%d", &k) != 1) {
        free(str);
        return 1;
    }
    if (scanf("%10000s", str) != 1) {
        free(str);
        return 1;
    }

    printf("%d", GetKShortSubstring(str, k));

    free(str);
    return 0;
}

int GetKShortSubstring(char *str, int k)
{
    // Write your code here (you can change the next line):
    return 0;
}
