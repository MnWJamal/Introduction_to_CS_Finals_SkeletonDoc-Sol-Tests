#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool IsKSplittable(int arr[], int n, int k);

// Do not change read_arr!!!
int* read_arr(int* n, int* k) {
    if (scanf("%d %d", n, k) != 2) return NULL;
    if (*n < 0) return NULL;
    int* arr = malloc(((*n) > 0 ? (*n) : 1) * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < *n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, k;
    int* arr = read_arr(&n, &k);
    if (!arr) return 1;
    printf("%d", IsKSplittable(arr, n, k) ? 1 : 0);
    free(arr);
    return 0;
}

bool valid(long long sums[], int k) {
    long long sum = sums[0];
    for (int i = 0 ; i < k ; i++) {
        if (sums[i] != sum) return false;
    }
    return true;
}
bool IsKSplittable_aux(int arr[], int n, int k, long long sums[], int curr_idx) {
    if (curr_idx >= n) return valid(sums,k);
    for (int group = 0 ; group < k ; group++) {
        //try taking curr_number to group:
        sums[group] += arr[curr_idx];
        if (IsKSplittable_aux(arr,n,k,sums,curr_idx+1))
            return true;
        //bad choice, backtrack:
        sums[group] -= arr[curr_idx];
    }

    /*
    Didn't return? well:
    in this tree, no matter which group you out the number in,
    none will be valid :(
    */
    return false;
}

bool IsKSplittable(int arr[], int n, int k) {
    if(k <= 0) return true;
    long long * sums = malloc(k*sizeof(long long));
    if (!sums) {
        return false;
    }
    for (int i = 0 ; i < k ; i++) {
        sums[i] = 0;
    }
    bool IsKsptbl = IsKSplittable_aux(arr,n,k,sums,0);
    free(sums);
    return IsKsptbl;
}
