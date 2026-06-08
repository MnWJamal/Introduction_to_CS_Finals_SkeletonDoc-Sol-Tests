#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FAILURE -1
#define SUCCESS 0

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void merge(int a[], int na, int b[], int nb, int out[]) {
    int ia = 0, ib = 0, io = 0;
    while (ia < na && ib < nb) {
        if (a[ia] <= b[ib]) {
            out[io++] = a[ia++];
        } else {
            out[io++] = b[ib++];
        }
    }
    while (ia < na) {
        out[io++] = a[ia++];
    }
    while (ib < nb) {
        out[io++] = b[ib++];
    }
}

int merge_sort(int ar[], int n);

// Do not change read_arr!!!
int* read_arr(int n) {
    if (n <= 0) return NULL;
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

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;

    int* arr = read_arr(n);
    if (n > 0 && !arr) return 1;

    int status = merge_sort(arr, n);
    printf("%d", status);
    for (int i = 0; i < n; i++) {
        printf("%c%d", (i == 0 ? '\n' : ' '), arr[i]);
    }

    free(arr);
    return 0;
}
void copyArray(int * dest, int * src, int n) {
    for (int i = 0 ; i < n ; i++) {
        dest[i] = src[i];
    }
}
int merge_sort(int ar[], int n)
{
    int len;
    int *temp_array;
    temp_array = (int*) malloc(sizeof(int)*n);
    if (temp_array == NULL)
    {
        printf("Dynamic Allocation Error in merge_sort");
        return FAILURE;
    }
    int curr_destination = 0; //0 for base, 1 for tmp_arr
    for (len = 1; len < n; len *= 2)
    {
        curr_destination ++;
        curr_destination %= 2;
        for (int base = 0; base < n; base += 2 * len) {
            int * in = (curr_destination)? ar + base : temp_array + base;
            int * out = (curr_destination)? temp_array + base : ar + base;
            merge(in, len, in + len, len, out);
        }
    }
    if (curr_destination) copyArray(ar,temp_array,n);
    free(temp_array);
    return SUCCESS;
}
