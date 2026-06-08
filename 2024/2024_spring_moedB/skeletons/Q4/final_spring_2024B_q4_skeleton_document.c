#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool exam_q4(int n, int k);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, k;
    if (scanf("%d%d", &n, &k) != 2) return 1;
    printf("%s", exam_q4(n, k) ? "true" : "false");
    return 0;
}

bool exam_q4(int n, int k) {
    // Write your code here (you can change the next line):
    return false;
}
