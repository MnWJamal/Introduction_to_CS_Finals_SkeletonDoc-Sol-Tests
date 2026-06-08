#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool AreAnagrams(char * s1, char * s2);

// Do not change strip_newline!!!
void strip_newline(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n' || str[i] == '\r') {
            str[i] = '\0';
            return;
        }
        i++;
    }
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char s1[4096];
    char s2[4096];

    if (fgets(s1, sizeof(s1), stdin) == NULL) return 1;
    if (fgets(s2, sizeof(s2), stdin) == NULL) return 1;

    strip_newline(s1);
    strip_newline(s2);

    printf("%d", AreAnagrams(s1, s2) ? 1 : 0);
    return 0;
}

#define ALPHBT ('z'-'a'+1)
#define ToLowerAddOn ('a' - 'A')
void Histify(int Hist[ALPHBT], char * str) {
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            int addOn = (str[i] >= 'A' && str[i] <= 'Z')? ToLowerAddOn : 0;
            Hist[(str[i] + addOn) - 'a']++;
        }
        i++;
    }
}
bool EqualHists(int Hist1[ALPHBT],int Hist2[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist1[i] != Hist2[i]) return false;
    }
    return true;
}
bool AreAnagrams(char * s1, char * s2) {
    int Hist1[ALPHBT] = {0};
    int Hist2[ALPHBT] = {0};
    Histify(Hist1,s1);
    Histify(Hist2,s2);
    return EqualHists(Hist1,Hist2);
}
