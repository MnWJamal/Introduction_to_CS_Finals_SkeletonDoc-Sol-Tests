#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindInTelescope(int arr[], int n, int x);

int* read_arr(int n) {
    int* arr = malloc(n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

bool contains_value(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return true;
    }
    return false;
}

bool is_valid_answer(int arr[], int n, int x, int index) {
    if (index == -1) return !contains_value(arr, n, x);
    return index >= 0 && index < n && arr[index] == x;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, x;
    if (scanf("%d", &n) != 1) return 1;
    int* arr = read_arr(n);
    if (!arr) return 1;
    if (scanf("%d", &x) != 1) {
        free(arr);
        return 1;
    }

    int answer = FindInTelescope(arr, n, x);
    printf("%d", is_valid_answer(arr, n, x, answer) ? 1 : 0);
    free(arr);
    return 0;
}

int FindInTelescope(int arr[], int n, int x) {
    // Write your code here (you can change the next line):
    return -1;
}
