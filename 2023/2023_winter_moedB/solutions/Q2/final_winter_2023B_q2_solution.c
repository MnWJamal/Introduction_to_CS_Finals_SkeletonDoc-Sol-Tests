#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int pow2(int k) {
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= 2;
    }
    return result;
}

int exam_B_q2(int arr[], int n, int x);

int* read_arr(int n) {
    if (n <= 0) {
        return NULL;
    }
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int GetPow2OfNum(int num);
int main() {
    // printIDontKnow();
    int n, x;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    int* arr = read_arr(n);
    if (n > 0 && arr == NULL) {
        return 1;
    }
    if (scanf("%d", &x) != 1) {
        free(arr);
        return 1;
    }
    printf("%d", exam_B_q2(arr, n, x));
    free(arr);
    return 0;
}


int GetPow2OfNum(int num) {
    //this is log of max k (notice how k *= 2)
    if (num % 2) return 0;
    int k = 1;
    double test_for_fraction;
    while (1)
    {
        test_for_fraction = (double)(num) / pow2(k);
        if (!(test_for_fraction - (int)(test_for_fraction) == 0 && test_for_fraction != 0)) break;
        k *= 2;
    }
    int left = 0 , right = k;
    while (right >= left) {
        int middle = (right + left) / 2;
        double divisor = (double)(num) / pow2(middle);
        if (divisor == (double)((int)(divisor))) {
            int div = (int)(divisor);
            if (div % 2 == 1) return middle;
            else left = middle + 1;
        }
        else{
            right = middle - 1;
        }

    }

    //never happens but:
    return 0;
}
int firstOccuranceOf2POWK(int arr[], int n, int k) {
    int left = 0, right = n - 1;
    while (right > left) {
        int middle = (right + left) / 2;
        int pow2middle = GetPow2OfNum(arr[middle]);
        if (pow2middle >= k) {
            right = middle;
        }
        else left = middle + 1;
    }
    if (GetPow2OfNum(arr[right]) == k) return right;
    if (k == 0) return -1;
    return (right == n - 1)? n : right;


}
int exam_B_q2(int arr[], int n, int x) {
    if (n == 0) return -1;
    int k_of_x = GetPow2OfNum(x);
    int first_app = firstOccuranceOf2POWK(arr,n,k_of_x);
    if (first_app == -1 || first_app == n) return -1;
    int last_app = firstOccuranceOf2POWK(arr,n,k_of_x+1) - 1;
    int left = first_app, right = last_app;
    while (right >= left) {
        int middle = (right + left) / 2;
        if (arr[middle] == x) return middle;
        if (arr[middle] > x) {
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    return -1;
}
