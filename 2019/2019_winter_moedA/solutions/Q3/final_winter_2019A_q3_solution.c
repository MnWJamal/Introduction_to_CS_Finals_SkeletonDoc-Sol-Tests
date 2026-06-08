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
    if (*seq != 'X') return 0;
    int y_appeared = 1;
    while (seq[y_appeared] != 'Y')
        //we know y_ct >= x_ct (so *= 2 will either land on X or Y)
    {
        y_appeared *= 2;
    } //this is a log(n) loop
    //now binary search:
    int left = 0, right = y_appeared;
    while (right - left > 1) {
        int middle = (right+left) / 2;
        if (seq[middle] == 'Y') {
            right = middle - 1;
        }
        else left = middle;
    }
    if (seq[right] == 'X') return right+1;

    return left+1;
}
