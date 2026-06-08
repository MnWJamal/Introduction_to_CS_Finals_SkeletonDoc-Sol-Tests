#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int ShortestSubstring(char *str);

// Do not change read_str!!!
char* read_str(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char* str = malloc((*n + 1) * sizeof(char));
    if (!str) return NULL;
    for (int i = 0; i < *n; ++i) {
        if (scanf(" %c", str + i) != 1) {
            free(str);
            return NULL;
        }
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
    printf("%d", ShortestSubstring(str));
    free(str);
    return 0;
}
#define ALPHBT ('z' - 'a' + 1)
int point_colect_and_getlen(int collection[ALPHBT], char * str) {
    int i = 0;
    while (str[i]) {
        collection[str[i] - 'a']++;
        i++;
    }
    return i;
}
bool sameCollection(int collection1[ALPHBT], int collection2[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if ((collection1[i] && !collection2[i]) || (!collection1[i] && collection2[i]))
            return false; //basicly "NOT XOR" ;)
    }
    return true;
}
int ShortestSubstring(char *str) {
    int collection[ALPHBT] = {0};
    int len = point_colect_and_getlen(collection,str);
    if (len == 0) return 0;
    int left = 0, right = -1;
    int window[ALPHBT] = {0};
    int min_len = len;
    while (right < len) {
        if (sameCollection(window,collection)) {
            int len = right - left + 1;
            min_len = (len < min_len)? len : min_len;
            window[str[left] - 'a']--;
            left++;
        }
        else {
            right++;
            if (right < len) window[str[right] - 'a']++;
        }
    }
    return min_len;
}
