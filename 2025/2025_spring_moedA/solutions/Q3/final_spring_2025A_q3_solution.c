#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(char *s);

// Do not change read_string!!!
char* read_string(int n) {
    char* s = (char*)malloc((n + 1) * sizeof(char));
    if (!s) return NULL;

    int c = getchar();
    while (c == '\n' || c == '\r') {
        c = getchar();
    }
    if (c == EOF) {
        free(s);
        return NULL;
    }
    s[0] = (char)c;

    for (int i = 1; i < n; i++) {
        c = getchar();
        if (c == EOF) {
            free(s);
            return NULL;
        }
        s[i] = (char)c;
    }
    s[n] = '\0';
    return s;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    char* s = read_string(n);
    if (!s) return 1;

    exam_q3(s);
    printf("%s", s);
    free(s);
    return 0;
}

void swap(char * u,char * v) {
    char tmp = *u;
    *u = *v;
    *v = tmp;
}
int my_len(char * s) {
    int i = 0 ;
    while (s[i]) i++;
    return i;
}
void exam_q3(char *s) {
    int word_length = 0;
    int dollars = 0;
    int offset = 0;
    int len = my_len(s);
    for (int i = 0; i < len - offset ; i++) {
        swap(s+i,s+i+offset);
        if (s[i] == '$') {
            int j = i;
            while (s[j+offset] == '$') {
                j++;
            }
            dollars = j - i;
            if (dollars >= 2) {
                if (dollars > word_length) {
                    s[i] = '+';
                }
                else {
                    s[i] = '*';
                }
            }
            word_length = 0;
            offset += (dollars - 1);
        }
        else word_length++;
    }
    for (int j = len - offset ; j <= len ; j++) {
        s[j] = '\0';
    }
}