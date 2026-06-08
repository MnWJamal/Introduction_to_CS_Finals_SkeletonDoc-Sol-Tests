#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3
#define M 10

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int assign_boats(int A[][N], int weights[]);

// Do not change read_input!!!
bool read_input(int A[][N], int weights[]) {
    for (int i = 0; i < N; i++) {
        if (scanf("%d", weights + i) != 1) {
            return false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
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

    int A[N][N];
    int weights[N];

    if (!read_input(A, weights)) return 1;

    printf("%d", assign_boats(A, weights));

    return 0;
}

int assign_boats(int A[][N], int weights[])
{
    // Write your code here (you can change the next line):
    return 0;
}
