#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int identityIndex(int arr[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;

    if (*n == 0) return NULL;

    int* arr = malloc((*n) * sizeof(int));
    if (!arr) return NULL;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

// Do not change is_valid_answer!!!
bool is_valid_answer(int arr[], int n, int answer) {
    bool exists = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == i) {
            exists = true;
            break;
        }
    }

    if (answer == -1) {
        return !exists;
    }

    return 0 <= answer && answer < n && arr[answer] == answer;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* arr = read_arr(&n);
    if (n < 0) return 1;
    if (n > 0 && !arr) return 1;

    int answer = identityIndex(arr, n);
    printf("%d", is_valid_answer(arr, n, answer));

    free(arr);
    return 0;
}

int identityIndex(int arr[], int n)
{
    // Write your code here (you can change the next line):
    return 0;
}
