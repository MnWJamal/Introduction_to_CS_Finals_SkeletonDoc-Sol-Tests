#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int find_single(char *str_arr[], int n);

// Do not change read_line!!!
char* read_line() {
    int capacity = 16;
    int length = 0;
    char* str = malloc(capacity * sizeof(char));
    if (!str) {
        return NULL;
    }

    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (c == '\r') {
            continue;
        }
        if (length + 1 >= capacity) {
            capacity *= 2;
            char* tmp = realloc(str, capacity * sizeof(char));
            if (!tmp) {
                free(str);
                return NULL;
            }
            str = tmp;
        }
        str[length++] = (char)c;
    }

    str[length] = '\0';
    return str;
}

// Do not change read_arr!!!
char** read_arr(int* n) {
    if (scanf("%d", n) != 1) {
        return NULL;
    }

    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        // consume the rest of the first line
    }

    char** arr = malloc((*n) * sizeof(char*));
    if (!arr) {
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        arr[i] = read_line();
        if (!arr[i]) {
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
    }

    return arr;
}

// Do not change free_arr!!!
void free_arr(char** arr, int n) {
    if (!arr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Do not change main!!!
// Uncomment the first line in main if you don't know the answer.
int main() {
    // printIDontKnow();

    int n;
    char** str_arr = read_arr(&n);
    if (!str_arr) {
        return 1;
    }

    printf("%d", find_single(str_arr, n));

    free_arr(str_arr, n);
    return 0;
}

bool equals(char * str1, char * str2) {
    int i = 0;
    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i]) return false;
        i++;
    }
    return str1[i] == str2[i];
}
int find_single(char *str_arr[], int n) {
    int left = 0, right = n-1;
    while (right >= left) {
        int middle = (right + left)/2;
        bool equals_left = ((middle > 0) && equals(str_arr[middle-1],str_arr[middle]));
        bool equals_right = ((middle < n-1) && equals(str_arr[middle+1], str_arr[middle]));
        if (!equals_right && !equals_left) return middle;
        if ( (middle % 2 == 0 && equals_right) || (middle % 2 == 1 && equals_left))
        {
            //order is normal => word is yet to appear:
            left = middle + 1;

        }
        //order is distored, word has been passed
        else right = middle - 1;
    }
    return 0;
}
