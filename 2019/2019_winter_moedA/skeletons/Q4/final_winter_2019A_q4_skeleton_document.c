#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void PrintAllPossibleSubstrings(char *str);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char str[32];
    if (scanf("%31s", str) != 1) return 1;
    PrintAllPossibleSubstrings(str);
    return 0;
}

void PrintAllPossibleSubstrings(char *str) {
    // Write your code here
}
