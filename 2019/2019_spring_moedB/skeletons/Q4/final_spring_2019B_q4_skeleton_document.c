#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool IsConstructible(int numbers[], int n, int result);

// Do not change read_arr!!!
int* read_arr(int n) {
    if (n < 0) return NULL;
    int* arr = malloc((n > 0 ? n : 1) * sizeof(int));
    if (!arr) return NULL;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, result;
    if (scanf("%d %d", &n, &result) != 2) return 1;

    int* numbers = read_arr(n);
    if (!numbers) return 1;

    printf("%d", IsConstructible(numbers, n, result) ? 1 : 0);

    free(numbers);
    return 0;
}

bool IsConstructible(int numbers[], int n, int result) {
    // Write your code here (you can change the next line):
    return false;
}
