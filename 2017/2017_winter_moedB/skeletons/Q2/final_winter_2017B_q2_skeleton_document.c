#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindDuplicate(int a[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    int* a = malloc((*n) * sizeof(int));
    if (!a) return NULL;
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", a + i) != 1) {
            free(a);
            return NULL;
        }
    }
    return a;
}

// Do not change appears_twice!!!
bool appears_twice(int a[], int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            count++;
        }
    }
    return count >= 2;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* a = read_arr(&n);
    if (!a) return 1;

    int* original = malloc(n * sizeof(int));
    if (!original) {
        free(a);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        original[i] = a[i];
    }

    int result = FindDuplicate(a, n);
    printf("%s", appears_twice(original, n, result) ? "OK" : "WRONG");

    free(original);
    free(a);
    return 0;
}

int FindDuplicate(int a[], int n)
{
    // Write your code here (you can change the next line):
    return 0;
}
