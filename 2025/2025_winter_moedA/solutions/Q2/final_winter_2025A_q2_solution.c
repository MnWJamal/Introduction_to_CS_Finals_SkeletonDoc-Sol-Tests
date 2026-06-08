#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examA_q2(char** arr, int n, int m);

char** read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char** arr = malloc((*n) * sizeof(char*));
    if (!arr) return NULL;

    for (int i = 0; i < *n; i++) {
        int len;
        if (scanf("%d", &len) != 1) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }

        arr[i] = malloc((len + 1) * sizeof(char));
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }

        if (scanf("%s", arr[i]) != 1) {
            for (int j = 0; j <= i; j++) free(arr[j]);
            free(arr);
            return NULL;
        }
    }

    return arr;
}

void free_arr(char** arr, int n) {
    if (!arr) return;
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    char** arr = read_arr(&n);
    if (!arr) return 1;

    int m;
    if (scanf("%d", &m) != 1) {
        free_arr(arr, n);
        return 1;
    }

    printf("%d", examA_q2(arr, n, m));
    free_arr(arr, n);
    return 0;
}





bool can_be_max(char ** arr, int n, int m, int max)
{
    //O(n)

    int in_line = 0;
    int lines_so_far = 1;

    for (int i = 0 ; i < n ; i++) {
        int length_off_i = (int)strlen(arr[i]);
        if (length_off_i > max) return false;
        if (in_line + length_off_i <= max) {
            in_line += length_off_i;
        }
        else {
            lines_so_far++;
            in_line = length_off_i;
        }

        if (lines_so_far > m) return false;
    }
    return true;
}

int absolute_max_length(char ** arr, int n) {
    int length = 0;
    for (int i = 0 ; i < n ; i++) {
        length += (int)strlen(arr[i]);
    }
    return length;
}
#define ERROR_INVALID_M (-1)
#define ERROR_EMPTY_ARRAY (-2)
int examA_q2(char** arr, int n, int m) {
    if (m <= 0) return ERROR_INVALID_M;
    if (n <= 0 || !arr) return ERROR_EMPTY_ARRAY;
    int left = 0 , right = absolute_max_length(arr,n);
    while (right > left) {
        int middle = (right + left) / 2;
        if (can_be_max(arr,n,m,middle)) {
            //try smaller max: (still could be the only answer so we do: r = m;
            right = middle;
        }
        else {
            //cant be max, surely larger:
            left = middle + 1;
        }
    }
    return right;
}
