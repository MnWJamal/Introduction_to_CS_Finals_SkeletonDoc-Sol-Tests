#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int index_of_equal_sum_left_right(int a[], int n);

// Do not change read_arr!!!
int* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;
    if (*n == 0) return malloc(sizeof(int));
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

// Do not change the judge code!!!
bool is_equal_sum_index(int a[], int n, int index) {
    if (index < 0 || index >= n) return false;
    long long left = 0, right = 0;
    for (int i = 0; i < index; i++) left += a[i];
    for (int i = index + 1; i < n; i++) right += a[i];
    return left == right;
}

// Do not change the judge code!!!
bool has_equal_sum_index(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (is_equal_sum_index(a, n, i)) return true;
    }
    return false;
}

// Do not change the judge code!!!
bool judge_answer(int a[], int n, int answer) {
    if (answer == -1) return !has_equal_sum_index(a, n);
    return is_equal_sum_index(a, n, answer);
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* arr = read_arr(&n);
    if (!arr) return 1;
    int answer = index_of_equal_sum_left_right(arr, n);
    printf("%d", judge_answer(arr, n, answer) ? 1 : 0);
    free(arr);
    return 0;
}

int index_of_equal_sum_left_right(int a[], int n) {
    if(n <= 0) return -1;
    int sum_from_left  = 0;
    int sum_from_right = 0;
    for (int i = n - 1 ; i > 0 ; i--) {
        sum_from_right += a[i];
    }
    if (sum_from_right == 0) return 0;
    for (int tested_point = 1 ; tested_point <= n-1 ; tested_point++) {
        sum_from_left += a[tested_point-1];
        sum_from_right -= a[tested_point];
        if (sum_from_right == sum_from_left) return tested_point;
    }
    return -1;
}
