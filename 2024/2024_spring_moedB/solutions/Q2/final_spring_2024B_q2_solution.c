#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
#define MAX_STRING_LENGTH 1000

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q2(char* arr[], int n, char* str);

// Do not change read_word!!!
char* read_word() {
    char buffer[MAX_STRING_LENGTH + 1];
    if (scanf("%1000s", buffer) != 1) return NULL;
    int len = 0;
    while (buffer[len] != '\0') len++;
    char* word = (char*)malloc((len + 1) * sizeof(char));
    if (!word) return NULL;
    for (int i = 0; i <= len; i++) {
        word[i] = buffer[i];
    }
    return word;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    char** arr = (char**)malloc(n * sizeof(char*));
    if (!arr) return 1;

    for (int i = 0; i < n; i++) {
        arr[i] = read_word();
        if (!arr[i]) {
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return 1;
        }
    }

    char* str = read_word();
    if (!str) {
        for (int i = 0; i < n; i++) free(arr[i]);
        free(arr);
        return 1;
    }

    printf("%d", exam_q2(arr, n, str));

    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    free(str);
    return 0;
}

int StringMagnitude(char * str) {
    //O(m) function
    int magnitude = 0;
    int i = 0;
    while (str[i]) {
        magnitude += str[i];
        i++;
    }
    return magnitude;
}
int exam_q2(char* arr[], int n, char* str) {
    if (n == 0) return -1;

    int left = 0, right = n - 1;
    int str_magna = StringMagnitude(str);
    while (right > left) {
        int middle = (right + left) / 2;
        int middle_magna = StringMagnitude(arr[middle]);
        if (middle_magna >= str_magna) {
            right = middle;
        }
        else left = middle + 1;
    }
    //now right and left are equal and they set on supposive positin in array
    //now we compare the supossive position and the one before it (unless 0 then return);
    if (right == 0) return 0;
    int delta1 = StringMagnitude(arr[right]) - str_magna;
    int delta2 = StringMagnitude(arr[right-1]) - str_magna;
    delta1 = (delta1 < 0)? -1*delta1 : delta1;
    delta2 = (delta2 < 0)? -1*delta2 : delta2;
    if (delta1 < delta2) return right;
    return right-1;
}
