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

#define DIGITS 10
int compareHists(int hist1[DIGITS], int hist2[DIGITS]) {
    for (int i = 0; i < DIGITS; ++i) {
        if (hist1[i] != hist2[i]) {
            return 0;
        }
    }
    return 1;
}

int examB_q3(int num, int pattern) {
    if (pattern > num * 10) {
        //The pattern is longer than the number
        return 0;
    }

    int patternHist[DIGITS] = {0};
    int patLen = 0;
    while (pattern > 0) {
        patternHist[pattern % 10]++;
        pattern /= 10;
        patLen++;
    }

    int digitsToAdd = num, digitsToRemove = num, initialize = patLen, count = 0;
    int hist[DIGITS] = {0};
    while (digitsToAdd > 0) {
        hist[digitsToAdd % 10]++;
        digitsToAdd /= 10;
        if (initialize > 0) {
            initialize--;
        } else {
            hist[digitsToRemove % 10]--;
            digitsToRemove /= 10;
        }
        count += compareHists(hist, patternHist);
    }
    return count;
}