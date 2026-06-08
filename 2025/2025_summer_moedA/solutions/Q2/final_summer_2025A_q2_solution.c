#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q2(int arr[], int n);

int main(void) {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    int* arr = malloc(n * sizeof(int));
    if (!arr) return 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }
    printf("%d", exam_q2(arr, n));
    free(arr);
    return 0;
}
int Min(int a, int b) {
    return (b < a)? b : a;
}
int exam_q2(int arr[], int n) {
    int max_Water = 0;
    for (int i = 1; i < n ; i++) {
        int water = Min(arr[i],arr[0])*i;
        max_Water = (water > max_Water)? water : max_Water;
    }
    return max_Water;
}