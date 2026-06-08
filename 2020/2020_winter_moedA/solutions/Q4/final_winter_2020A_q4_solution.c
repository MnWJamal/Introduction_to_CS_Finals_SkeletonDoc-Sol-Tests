#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool is_partition_possible(int arr[], int n);

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

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int* arr = read_arr(&n);
    if (!arr) return 1;
    printf("%d", is_partition_possible(arr, n) ? 1 : 0);
    free(arr);
    return 0;
}


bool valid_add(int arr[], int i, int sums[] , int in_triplet, int curr_triplet) {
    if (curr_triplet == 0 || in_triplet <= 1) return true;
    return (sums[curr_triplet - 1] == (sums[curr_triplet] + arr[i]));
}
bool is_partition_possible_aux(int arr[], bool used[], int sums[] ,int n, int in_triplet, int curr_triplet) {
    if (curr_triplet == (n/3))
        return true;

    for (int i = 0 ; i < n ; i++) {
        if (!used[i] &&
            valid_add(arr,i,sums,in_triplet,curr_triplet))
        {
            //try take to curr group:
            used[i] = true;
            sums[curr_triplet] += arr[i];

            bool result = false;
            if (in_triplet == 2 )
                result = is_partition_possible_aux(arr,used,sums,n,0,curr_triplet+1);
            else
                result = is_partition_possible_aux(arr,used,sums,n,in_triplet+1,curr_triplet);
            if (result) {
                return true;
            }
            //backtrack: (bad choice)
            used[i] = false;
            sums[curr_triplet] -= arr[i];
        }
    }
    //no result? bad tree:
    return false;
}
bool is_partition_possible(int arr[], int n) {
    bool * used = malloc(n*sizeof(bool));
    int * sums = malloc((n/3)*sizeof(int));
    if (!used || !sums) {
        if (used) free(used);
        if (sums) free(sums);
        return false;
    }

    for (int i = 0 ; i < n ; i++) {
        used[i] = false;
    }

    for (int i = 0 ; i <( n / 3 ); i++) {
        sums[i] = 0;
    }

    bool result = is_partition_possible_aux(arr,used,sums,n,0,0);
    free(used);
    free(sums);
    return result;
}
