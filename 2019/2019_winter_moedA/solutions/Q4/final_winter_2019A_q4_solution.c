#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void PrintAllPossibleSubstrings(char *str);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char str[32];
    if (scanf("%31s", str) != 1) return 1;
    PrintAllPossibleSubstrings(str);
    return 0;
}
#define ALPHBT ('Z' - 'A' + 1)
void PrintAllPossibleSubstrings_aux(int Hist[ALPHBT], int letters, char * str, int len) {
    if (letters == 0) {
        return;
    }
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist[i] > 0) {
            Hist[i]--;
            letters--;
            str[len] = 'A'+i;
            str[len + 1] = 0;
            len++;
            printf("%s\n",str);
            PrintAllPossibleSubstrings_aux(Hist,letters,str,len);
            //backtrack:
            len--;
            str[len] = 0;
            letters++;
            Hist[i]++;
        }
    }
}
void PrintAllPossibleSubstrings(char *str) {
    int Hist[ALPHBT] = {0};
    int len = 0;
    while (str[len]) {
        Hist[str[len] - 'A']++;
        len++;
    }
    if (len == 0) return;
    char * str_help = malloc(len*sizeof(char));
    if (!str_help) return;
    str_help[0] = 0;
    PrintAllPossibleSubstrings_aux(Hist,len,str_help,0);
}
