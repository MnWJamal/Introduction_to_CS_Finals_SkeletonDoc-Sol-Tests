#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int CalculateWaterVolume(int heights[], int n);

// Do not change read_heights!!!
int* read_heights(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;

    int* heights = malloc(((*n > 0) ? *n : 1) * sizeof(int));
    if (!heights) return NULL;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", heights + i) != 1) {
            free(heights);
            return NULL;
        }
    }
    return heights;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* heights = read_heights(&n);
    if (!heights) return 1;
    printf("%d", CalculateWaterVolume(heights, n));
    free(heights);
    return 0;
}

int CalculateWaterVolume(int heights[], int n) {
    // Write your code here (you can change the next line):
    return 0;
}
