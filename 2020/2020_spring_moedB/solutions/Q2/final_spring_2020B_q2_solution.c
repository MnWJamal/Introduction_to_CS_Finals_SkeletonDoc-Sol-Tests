#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int LongestSequence(int a[], int n, int k);

// Do not change read_arr!!!
int* read_arr(int n) {
    if (n <= 0) return NULL;
    int* arr = malloc(n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
void seperate_and_print(int arr[], int n);
int main() {
    // printIDontKnow();
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 1;
    int* arr = read_arr(n);
    if (n > 0 && !arr) return 1;
    printf("%d", LongestSequence(arr, n, k));
    free(arr);
    return 0;
}

int LongestSequence(int a[], int n, int k) {
    int Hist[2] = {0};
    int left = 0, right = -1;
    if (k < 0) k = 0;
    int max_length = 0;
    while (right < n) {
        if (Hist[0] <= k) {
            int len = right-left+1;
            max_length = (len > max_length)? len : max_length;
            right++;
            if (right < n) Hist[a[right]]++;
        }
        else {
            Hist[a[left]]--;
            left++;
        }
    }
    right--;
    while (left < n) {
        if (Hist[0] <= k) {
            int len = right-left+1;
            max_length = (len > max_length)? len : max_length;
        }
        Hist[a[left]]--;
        left++;
    }
    return max_length;
}