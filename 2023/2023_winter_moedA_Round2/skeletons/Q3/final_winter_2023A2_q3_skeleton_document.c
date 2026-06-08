#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_A2_q3(char* str1, char* str2);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char str1[10005];
    char str2[10005];
    if (scanf("%10004s", str1) != 1) return 1;
    if (scanf("%10004s", str2) != 1) return 1;
    printf("%d", exam_A2_q3(str1, str2));
    return 0;
}

int exam_A2_q3(char* str1, char* str2) {
    // Write your code here (you can change the next line):
    return 0;
}
