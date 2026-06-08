#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int build_bridges(char roads[], int n, int bridges[]);

static bool validate_bridges(char roads[], int n, int bridges[], int result) {
    if (result < 0 || result > n / 2) return false;
    if (result == 0) return true;

    int* first = malloc(result * sizeof(int));
    int* second = malloc(result * sizeof(int));
    int* count = malloc(result * sizeof(int));
    if (!first || !second || !count) {
        free(first);
        free(second);
        free(count);
        return false;
    }

    for (int i = 0; i < result; i++) {
        first[i] = -1;
        second[i] = -1;
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int label = bridges[i];
        if (label == -1) continue;
        if (label < 0 || label >= result) {
            free(first);
            free(second);
            free(count);
            return false;
        }
        if (count[label] == 0) {
            first[label] = i;
        } else if (count[label] == 1) {
            second[label] = i;
        } else {
            free(first);
            free(second);
            free(count);
            return false;
        }
        count[label]++;
    }

    for (int label = 0; label < result; label++) {
        if (count[label] != 2) {
            free(first);
            free(second);
            free(count);
            return false;
        }
        if (roads[first[label]] != roads[second[label]]) {
            free(first);
            free(second);
            free(count);
            return false;
        }
    }

    for (int a = 0; a < result; a++) {
        for (int b = a + 1; b < result; b++) {
            int a1 = first[a], a2 = second[a];
            int b1 = first[b], b2 = second[b];

            if ((a1 < b1 && b1 < a2 && a2 < b2) ||
                (b1 < a1 && a1 < b2 && b2 < a2)) {
                free(first);
                free(second);
                free(count);
                return false;
            }
        }
    }

    free(first);
    free(second);
    free(count);
    return true;
}

// Do not change read_roads!!!
char* read_roads(int n) {
    if (n <= 0) return NULL;
    char* roads = malloc(n * sizeof(char));
    if (!roads) return NULL;
    for (int i = 0; i < n; i++) {
        if (scanf(" %c", roads + i) != 1) {
            free(roads);
            return NULL;
        }
    }
    return roads;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;

    char* roads = read_roads(n);
    if (n > 0 && !roads) return 1;

    int* bridges = malloc((n > 0 ? n : 1) * sizeof(int));
    if (!bridges) {
        free(roads);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        bridges[i] = -1;
    }

    int result = build_bridges(roads, n, bridges);
    printf("%d %d", result, validate_bridges(roads, n, bridges, result) ? 1 : 0);

    free(bridges);
    free(roads);
    return 0;
}

int build_bridges(char roads[], int n, int bridges[]) {
    // Write your code here (you can change the next line):
    return 0;
}
