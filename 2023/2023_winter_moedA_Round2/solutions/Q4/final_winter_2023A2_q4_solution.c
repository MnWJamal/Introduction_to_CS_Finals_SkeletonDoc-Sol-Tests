#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_A2_q4(int arr[], int n, int d, int target);

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
    int d, target;
    if (scanf("%d%d", &d, &target) != 2) {
        free(arr);
        return 1;
    }
    printf("%d", exam_A2_q4(arr, n, d, target));
    free(arr);
    return 0;
}


int sum_digits(int num, int d){
    if (num == 0) return 0;
    return num %d + sum_digits(num/d, d);
}


int exam_A2_q4(int arr[], int n, int d, int target){
    if (n < 0) return -1;
    if (sum_digits(arr[0], d) == target) return 0;
    int res = exam_A2_q4(arr+1, n-1, d, target);
    if (res == -1) return -1;
    return 1 + res;
}
