#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define N 3

int exam_q4(int routes[N][N]);

int main(void) {
    // printIDontKnow();

    int routes[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &routes[i][j]) != 1) return 1;
        }
    }
    printf("%d", exam_q4(routes));
    return 0;
}

int exam_q4(int routes[N][N]) {
    return 0;
}
