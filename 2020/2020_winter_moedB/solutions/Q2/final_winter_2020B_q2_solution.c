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

int compare(int A, int B, bool interval)
{
    if (A == B) return 0;
    if (A > B) return interval? 1 : -1;
    return interval? -1 : 1;
}
int BinarySearch(int arr[], int n, int x, bool interval){
    int right = n-1, left = 0;
    while (right >= left) {
        int middle = (right + left) / 2;
        int comp = compare(arr[middle],x,interval);
        if (comp == 0) return middle;
        if (comp == -1) {
            left = middle + 1;
        }
        else right = middle - 1;
    }
    return -1;

}
int FindInTelescope(int arr[], int n, int x) {
    bool interval = (n >= 4)?
    ((arr[n-1] - arr[n-2]) > 0)? true : false
    : true; //doesnt really matter
    if (n == 0) return -1;
    if (arr[0] == x) return 0; //because on len = 0, we dont check
    for (int len = n/2 ; len > 0 ; len /= 2) {
        int idx = BinarySearch(arr+len,len,x,interval);
        if (idx != -1) return len + idx;
        interval = !interval;
    }
    return -1;
}
