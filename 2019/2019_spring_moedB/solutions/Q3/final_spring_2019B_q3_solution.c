#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int CountChars(char * str, int n, char c);
bool AreEqual(char * s1, char * s2, int n);

// Do not change read_small_string!!!
char* read_small_string(int n) {
    if (n < 0) return NULL;
    char* str = malloc((n + 1) * sizeof(char));
    if (!str) return NULL;

    for (int i = 0; i < n; i++) {
        if (scanf(" %c", str + i) != 1) {
            free(str);
            return NULL;
        }
    }
    str[n] = '\0';
    return str;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int mode;
    if (scanf("%d", &mode) != 1) return 1;

    if (mode == 1) {
        int n;
        char c;
        if (scanf("%d %c", &n, &c) != 2) return 1;
        char* str = read_small_string(n);
        if (!str) return 1;
        printf("%d", CountChars(str, n, c));
        free(str);
        return 0;
    }

    if (mode == 2) {
        int n;
        if (scanf("%d", &n) != 1) return 1;
        char* s1 = read_small_string(n);
        char* s2 = read_small_string(n);
        if (!s1 || !s2) {
            free(s1);
            free(s2);
            return 1;
        }
        printf("%d", AreEqual(s1, s2, n) ? 1 : 0);
        free(s1);
        free(s2);
        return 0;
    }

    return 1;
}

int CountChars(char * str, int n, char c) {
    //in this solution str[n] is a letter
    //and str[n+1] is '\0' (to chage aproach change last
    //element from n to n-1;
    int last_element = n;
    int left = 0, right = last_element;
    int first_occurance = -1;
    while (right > left) {
        int middle = (right + left) / 2;
        if (str[middle] >= c) {
            right = middle;
        }
        else left = middle+1;
    }
    if (str[right]  != c) return 0;
    first_occurance = right;
    left = 0, right = last_element;
    int last_occurance = first_occurance;
    while (right - left > 1) {
        int middle = (right + left) / 2;
        if (str[middle] <= c) {
            left = middle;
        }
        else right = middle-1;
    }
    if (str[left] == c) last_occurance = left;
    if (str[right] == c) last_occurance = right;

    return last_occurance - first_occurance + 1;
}

#define ALPHBT ('z'-'a'+1)
void Special_LogN_Histify(int Hist[ALPHBT], char * str, int n) {
    //O(C*logn) = O(logn)
    for (int i = 0 ; i < ALPHBT ; i++) {
        Hist[i] = CountChars(str,n,(char)('a' + i));
    }
}
bool AreEqual(char * s1, char * s2, int n) {
    int Hist1[ALPHBT] = {0};
    int Hist2[ALPHBT] = {0};
    Special_LogN_Histify(Hist1,s1,n); //O(logn)
    Special_LogN_Histify(Hist2,s2,n); //O(logn)
    //sorted => (equal <=> same letter count for all letters)
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist1[i] != Hist2[i]) return false;
    }
    return true;
}
