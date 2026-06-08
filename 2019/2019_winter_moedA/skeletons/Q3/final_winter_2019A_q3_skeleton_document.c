#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindNumX(char *seq);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char seq[300005];
    if (scanf("%300000s", seq) != 1) return 1;
    printf("%d", FindNumX(seq));
    return 0;
}

int FindNumX(char *seq) {
    // Write your code here
    return 0;
}
