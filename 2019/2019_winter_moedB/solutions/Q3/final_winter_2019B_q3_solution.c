#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DONT_KNOW "I_dont_know"
#define MAX_WORD 10000

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int CountPermutations(char* s1, char* s2);

// Do not change read_word!!!
char* read_word() {
    char* str = malloc((MAX_WORD + 1) * sizeof(char));
    if (!str) return NULL;

    if (scanf("%10000s", str) != 1) {
        free(str);
        return NULL;
    }

    return str;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char* s1 = read_word();
    char* s2 = read_word();

    if (!s1 || !s2) {
        free(s1);
        free(s2);
        return 1;
    }

    printf("%d", CountPermutations(s1, s2));

    free(s1);
    free(s2);
    return 0;
}
#define ALPHBT ('z'-'a'+1)
int HistifyAndGetLen(int Hist[ALPHBT], char * str)
{
    int i = 0;
    while (str[i]) {
        Hist[str[i]-'a']++;
        i++;
    }
    return i;
}
int my_strlen(char * str) {
    int i = 0;
    while (str[i]) i++;
    return i;
}
bool EqualHists(int Hist1[ALPHBT], int Hist2[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist1[i] != Hist2[i]) return false;
    }
    return true;
}
int CountPermutations(char* s1, char* s2) {
    int Hist2[ALPHBT] = {0};
    int len1 = my_strlen(s1);
    int len2 = HistifyAndGetLen(Hist2,s2);

    if (len1 < len2) return 0;

    int window[ALPHBT] = {0};
    for (int i = 0 ; i < len2 ; i++) {
        window[s1[i] - 'a']++;
    }

    int perms = (EqualHists(window,Hist2)? 1 : 0);
    for (int head = 1 ; head <= len1 - len2 ; head++) {
        window[s1[head-1]-'a']--;
        window[s1[head+len2-1] - 'a']++;
        perms += (EqualHists(window,Hist2)? 1 : 0);
    }

    return perms;
}
