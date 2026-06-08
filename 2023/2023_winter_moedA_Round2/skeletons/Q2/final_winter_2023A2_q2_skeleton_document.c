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

int exam_A2_q2(int arr[], int n, unsigned int target) {
    // Write your code here (you can change the next line):
    return 0;
}
