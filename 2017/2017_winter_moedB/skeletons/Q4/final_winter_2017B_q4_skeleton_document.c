#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindMinimumNumDressColors(int color_map[N][N]);

// Do not change read_color_map!!!
bool read_color_map(int color_map[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &color_map[i][j]) != 1) {
                return false;
            }
        }
    }
    return true;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int color_map[N][N];
    if (!read_color_map(color_map)) return 1;

    printf("%d", FindMinimumNumDressColors(color_map));

    return 0;
}

int FindMinimumNumDressColors(int color_map[N][N])
{
    // Write your code here (you can change the next line):
    return 0;
}
