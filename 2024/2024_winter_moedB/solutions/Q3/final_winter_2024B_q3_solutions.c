#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q3(int arr[][2], int n, int* output);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int (*arr)[2] = NULL;
    if (n > 0) {
        arr = malloc(n * sizeof(*arr));
        if (!arr) return 1;
    }

    int output_capacity = 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &arr[i][0], &arr[i][1]) != 2) return 1;
        output_capacity += arr[i][1] - arr[i][0] + 1;
    }

    int* output = (int*)malloc(output_capacity * sizeof(int));
    if (!output) return 1;

    int len = exam_q3(arr, n, output);
    printf("%d", len);
    if (len > 0) {
        printf("\n");
        for (int i = 0; i < len; i++) {
            if (i > 0) printf(" ");
            printf("%d", output[i]);
        }
    }

    free(arr);
    free(output);
    return 0;
}

void Merge(int arr1[][2], int n1, int arr2[][2], int n2, int tmp[][2]) {
    int itmp = 0, i1 = 0 , i2 = 0;
    while (i1 < n1 && i2 < n2) {
        if (arr2[i2][0] > arr1[i1][0]) {
            tmp[itmp][0] = arr1[i1][0];
            tmp[itmp][1] = arr1[i1][1];
            itmp++;
            i1++;
        }
        else {
            tmp[itmp][0] = arr2[i2][0];
            tmp[itmp][1] = arr2[i2][1];
            itmp++;
            i2++;
        }
    }
    while (i1 < n1) {
        tmp[itmp][0] = arr1[i1][0];
        tmp[itmp][1] = arr1[i1][1];
        itmp++;
        i1++;
    }
    while (i2 < n2) {
        tmp[itmp][0] = arr2[i2][0];
        tmp[itmp][1] = arr2[i2][1];
        itmp++;
        i2++;
    }
}
void MergeSort(int arr[][2], int n) {
    if (n <= 1) return;
    MergeSort(arr, n/2);
    MergeSort(arr + (n/2), (n - (n/2)));
    int (*tmp)[2] = malloc(n * sizeof(int*));
    if (!tmp) return;
    Merge(arr,n/2, arr + (n/2), n - (n/2),tmp);
    for (int i = 0 ; i < n ; i++) {
        arr[i][0] = tmp[i][0];
        arr[i][1] = tmp[i][1];
    }
    free(tmp);
}
int exam_q3(int arr[][2], int n, int* output) {
    if (!arr || !output) return 0;
    MergeSort(arr,n);

    int last_number = 0;
    for (int i = 0 ; i < n ; i++) {
        int startfrom = (last_number != 0)?
        (output[last_number - 1] + 1 > arr[i][0])? output[last_number - 1] + 1 : arr[i][0]
        : arr[i][0];
        while (startfrom <= arr[i][1]) {
            output[last_number] = startfrom;
            startfrom++;
            last_number++;
        }
    }
    return last_number;
}
