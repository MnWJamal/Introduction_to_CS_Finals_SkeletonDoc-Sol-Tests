#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_A2_q2(int arr[], int n, unsigned int target);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    int* arr = NULL;
    if (n > 0) {
        arr = (int*)malloc(n * sizeof(int));
        if (!arr) return 1;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }
    unsigned int target;
    if (scanf("%u", &target) != 1) {
        free(arr);
        return 1;
    }
    printf("%d", exam_A2_q2(arr, n, target));
    free(arr);
    return 0;
}

unsigned int SumK(int arr[], int n, int k) {
    unsigned int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += (arr[i] > k)? k : arr[i];
    }
    return sum;
}
int ArrayMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 0 ; i < n ; i++)
        max = (arr[i] > max)? arr[i] : max;
    return max;
}
int exam_A2_q2(int arr[], int n, unsigned int target) {
    if (n <= 0) return -1;
    int max = ArrayMax(arr,n);
    int left = 0 , right = max;
    while (right > left + 1) {
        int middle = (right + left) / 2;
        unsigned int sum = SumK(arr,n,middle);
        if (sum >= target) {
            right = middle;
        }
        else left = middle;
    }
    unsigned int left_sum = SumK(arr,n,left);
    unsigned int right_sum = SumK(arr,n,right);

    if (right_sum > target) return left;

    unsigned int delta_left = (target > left_sum)? target - left_sum : left_sum - target;
    unsigned int delta_right = (target > right_sum)? target - right_sum : right_sum - target;

    if (delta_left > delta_right) return right;
    return left;

}
