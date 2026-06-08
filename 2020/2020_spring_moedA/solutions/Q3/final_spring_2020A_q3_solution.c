#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void reverse_words(char *str);

// Do not change read_str!!!
char* read_str(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;
    getchar();
    char* str = malloc(((*n) + 1) * sizeof(char));
    if (!str) return NULL;
    for (int i = 0; i < *n; i++) {
        int c = getchar();
        if (c == EOF) {
            free(str);
            return NULL;
        }
        str[i] = (char)c;
    }
    str[*n] = '\0';
    return str;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    char* str = read_str(&n);
    if (!str) return 1;
    reverse_words(str);
    printf("%s", str);
    free(str);
    return 0;
}

void Swap(char * lt1, char * lt2) {
    char tmp = *lt1;
    *lt1 = *lt2;
    *lt2 = tmp;
}
void Reverse(char * str, int n) {
    for (int i = 0 ; i < n/2 ; i++) {
        Swap(str+i, str + n - 1 - i);
    }
}
int my_strlen(char * str) {
    int length = 0;
    while (str[length]) length++;
    return length;
}
void reverse_words(char *str) {
    int len = my_strlen(str);
    Reverse(str,len);
    int begin = 0, end = 0;
    while (end < len) {
        //NOTE: iterates over array once,
        //despite while in while nested loops decrease original loop
        begin = end;
        while (str[begin] == ' ') begin++;
        end = begin;
        while (str[end] != ' ' && str[end]) end++;
        Reverse(str+begin, end - begin);
    }
}
