#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int CountParenthesesPairs(int n);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    printf("%d", CountParenthesesPairs(n));

    return 0;
}

int CountParenthesesPairs(int n) {
    // Write your code here (you can change the next line):
    return 0;
}
