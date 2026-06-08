#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool Proportionalable(int arr[], int n);

// Do not change is_valid_arrangement!!!
bool is_valid_arrangement(int arr[], int n) {
    if (n <= 0) return false;

    int* first = malloc((n + 1) * sizeof(int));
    int* count = malloc((n + 1) * sizeof(int));
    if (!first || !count) {
        free(first);
        free(count);
        return false;
    }

    for (int i = 0; i <= n; i++) {
        first[i] = -1;
        count[i] = 0;
    }

    bool valid = true;
    for (int i = 0; i < 2 * n && valid; i++) {
        int value = arr[i];
        if (value < 1 || value > n) {
            valid = false;
            break;
        }

        count[value]++;
        if (count[value] == 1) {
            first[value] = i;
        } else if (count[value] == 2) {
            if (i - first[value] - 1 != value) {
                valid = false;
            }
        } else {
            valid = false;
        }
    }

    for (int value = 1; value <= n && valid; value++) {
        if (count[value] != 2) {
            valid = false;
        }
    }

    free(first);
    free(count);
    return valid;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int expected_int;
    if (scanf("%d %d", &n, &expected_int) != 2) return 1;
    if (n <= 0) return 1;

    int* arr = malloc((2 * n) * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < 2 * n; i++) {
        arr[i] = 0;
    }

    bool expected = (expected_int != 0);
    bool result = Proportionalable(arr, n);

    bool ok = (result == expected);
    if (ok && result) {
        ok = is_valid_arrangement(arr, n);
    }

    printf("%d", ok ? 1 : 0);

    free(arr);
    return 0;
}

bool Proportionalable(int arr[], int n) {
    // Write your code here (you can change the next line):
    return false;
}
