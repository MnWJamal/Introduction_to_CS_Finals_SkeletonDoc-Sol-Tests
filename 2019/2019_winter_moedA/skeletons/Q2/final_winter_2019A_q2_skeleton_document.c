#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void AlternatingArrange(int arr[], int n);

int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;
    if (*n == 0) return malloc(sizeof(int));
    int* arr = malloc((*n) * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < *n; ++i) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

bool same_multiset(int a[], int b[], int n) {
    bool* used = malloc(n * sizeof(bool));
    if (!used && n > 0) return false;
    for (int i = 0; i < n; ++i) used[i] = false;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && a[i] == b[j]) {
                used[j] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            free(used);
            return false;
        }
    }
    free(used);
    return true;
}

bool fits_sign(int value, int sign) {
    if (value > 0) return sign == 1;
    if (value < 0) return sign == -1;
    return true;
}

bool check_pattern(int arr[], int n, int total_pos, int start_sign) {
    int total_neg = n - total_pos;
    for (int i = 0; i < n; ++i) {
        int expected;
        if (total_pos > total_neg) {
            int alt_len = 2 * total_neg;
            if (i < alt_len) expected = (i % 2 == 0) ? start_sign : -start_sign;
            else expected = 1;
        } else if (total_neg > total_pos) {
            int extra = total_neg - total_pos;
            if (i < extra) expected = -1;
            else expected = ((i - extra) % 2 == 0) ? start_sign : -start_sign;
        } else {
            expected = (i % 2 == 0) ? start_sign : -start_sign;
        }
        if (!fits_sign(arr[i], expected)) return false;
    }
    return true;
}

bool valid_arrangement(int original[], int arr[], int n) {
    if (!same_multiset(original, arr, n)) return false;
    int positive = 0, zero = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) ++positive;
        else if (arr[i] == 0) ++zero;
    }
    for (int total_pos = positive; total_pos <= positive + zero; ++total_pos) {
        if (check_pattern(arr, n, total_pos, 1)) return true;
        if (check_pattern(arr, n, total_pos, -1)) return true;
    }
    return n == 0;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* arr = read_arr(&n);
    if (!arr) return 1;
    int* original = malloc((n > 0 ? n : 1) * sizeof(int));
    if (!original) {
        free(arr);
        return 1;
    }
    for (int i = 0; i < n; ++i) original[i] = arr[i];

    AlternatingArrange(arr, n);
    printf("%d", valid_arrangement(original, arr, n) ? 1 : 0);

    free(original);
    free(arr);
    return 0;
}

void AlternatingArrange(int arr[], int n) {
    // Write your code here
}
