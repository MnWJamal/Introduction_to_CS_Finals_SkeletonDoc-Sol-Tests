#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examB_q3(int num, int pattern);

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int num, pattern;
    if (scanf("%d %d", &num, &pattern) != 2) return 1;

    printf("%d", examB_q3(num, pattern));
    return 0;
}

int examB_q3(int num, int pattern) {
    // Write your code here (you can change the next line):
    return 0;
}
