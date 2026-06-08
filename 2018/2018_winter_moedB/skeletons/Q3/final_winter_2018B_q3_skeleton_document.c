#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int length_of_longest_stunning_substr(char *str);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char str[4096];
    if (scanf("%4095s", str) != 1) return 1;

    printf("%d", length_of_longest_stunning_substr(str));
    return 0;
}

int length_of_longest_stunning_substr(char *str) {
    // Write your code here (you can change the next line):
    return 0;
}
