#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DONT_KNOW "I_dont_know"
#define MAX_STRING_LENGTH 30
#define EXTRA_EMPTY_CELLS 4096

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q2(char** arr, char* src, char* dst);

int str_len_for_input(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* alloc_and_copy(char* s) {
    int len = str_len_for_input(s);
    char* res = (char*)malloc((len + 1) * sizeof(char));
    if (!res) return NULL;
    for (int i = 0; i <= len; i++) {
        res[i] = s[i];
    }
    return res;
}

char* read_string() {
    char buffer[MAX_STRING_LENGTH + 1];
    if (scanf("%30s", buffer) != 1) return NULL;
    return alloc_and_copy(buffer);
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int capacity = n + EXTRA_EMPTY_CELLS + 1;
    char** arr = (char**)malloc(capacity * sizeof(char*));
    if (!arr) return 1;

    for (int i = 0; i < n; i++) {
        arr[i] = read_string();
        if (!arr[i]) return 1;
    }
    for (int i = n; i < capacity; i++) {
        arr[i] = alloc_and_copy("");
        if (!arr[i]) return 1;
    }

    char* src = read_string();
    char* dst = read_string();
    if (!src || !dst) return 1;

    exam_q2(arr, src, dst);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%s", arr[i]);
    }

    return 0;
}
int mycompare(char * a, char * b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return (a[i] - b[i] > 0)? 1 : -1;
        i++;
    }
    if (!a[i] && !b[i]) return 0;
    return (a[i] - b[i] > 0)? 1 : -1;
}
int mylen(char * src) {
    for (int i = 0 ; ; i++) if (!src[i]) return i;
}
void replace(char ** dest, char * src) {
    free(*dest);
    int len = mylen(src);
    *dest = malloc((len+1)*sizeof(char));
    if (!*dest) return;
    for (int i = 0 ; i <= len ; i++) {
        (*dest)[i] = src[i];
    }
}
void exam_q2(char** arr, char* src, char* dst) {
    int end = 1;
    while (*arr[end]) end*=2;
    int left = 0 , right = end;
    while (right > left) {
        int middle = (right + left) / 2;
        if (!*arr[middle]) {
            right = middle - 1;
            continue;
        }
        int comp = mycompare(arr[middle],src);
        if (comp >= 0) {
            right = middle;
        }
        else left = middle + 1;
    }
    int exists = !mycompare(arr[right],src);
    if (!exists) return;
    int rewrite = right;
    while (!mycompare(arr[rewrite],src)) {
        replace(arr+rewrite,dst);
        rewrite++;
    }
}