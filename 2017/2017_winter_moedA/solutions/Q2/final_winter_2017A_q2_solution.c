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

int Minim(int num1 , int num2) {
    return (num1 > num2)? num2 : num1;
}

int CalculateWaterVolume(int heights[], int n) {
    if (n <= 2) return 0;
    int * maxfromleft = malloc(n*sizeof(int));
    int * maxfromright = malloc(n*sizeof(int));
    if (!maxfromleft || !maxfromright) return -1;
    int maxleft = heights[0];
    int maxright = heights[n-1];
    for (int offset = 0 ; offset < n ; offset++) {
        maxleft = (heights[offset] > maxleft)? heights[offset] : maxleft;
        maxright = (heights[n-1-offset] > maxright)? heights[n-1-offset] : maxright;
        maxfromleft[offset] = maxleft;
        maxfromright[n-1-offset] = maxright;
    }
    int water = 0;
    for (int block = 0 ; block < n ; block++) {
        int curr = Minim(maxfromleft[block],maxfromright[block]) - heights[block];
        water += curr;
    }
    free(maxfromleft);
    free(maxfromright);
    return water;
}