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
bool CanOpen(int n, int open) {
    return open < n;
}
bool CanClose(int open, int close) {
    return close < open;
}
int CountParenthesesPairs_aux(int n, int open, int close) {
    if (open == close && open == n) return 1;
    int count = 0;
    if (CanOpen(n,open)) {
        open++;
        count += CountParenthesesPairs_aux(n,open,close);
        //backtrack
        open--;
    }
    if (CanClose(open,close)) {
        close++;
        count += CountParenthesesPairs_aux(n,open,close);
        //backtrack
        close--;
    }
    return count;
}
int CountParenthesesPairs(int n) {
    // Write your code here (you can change the next line):
    return CountParenthesesPairs_aux(n,0,0);
}
