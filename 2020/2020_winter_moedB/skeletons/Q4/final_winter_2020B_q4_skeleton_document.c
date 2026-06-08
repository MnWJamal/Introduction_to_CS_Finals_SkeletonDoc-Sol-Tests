#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int shortest_path(int dist[N][N], bool red_ones[N], int k);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int dist[N][N];
    bool red_ones[N];
    int k;
    int value;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &dist[i][j]) != 1) return 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &value) != 1) return 1;
        red_ones[i] = (value != 0);
    }

    if (scanf("%d", &k) != 1) return 1;

    printf("%d", shortest_path(dist, red_ones, k));
    return 0;
}

int shortest_path(int dist[N][N], bool red_ones[N], int k) {
    // Write your code here (you can change the next line):
    return -1;
}
