#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindMaxSlimSubstring(char* str1, char* str2);

char* read_string_by_length(int n) {
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

    int n1, n2;
    if (scanf("%d %d", &n1, &n2) != 2) return 1;
    char* str1 = read_string_by_length(n1);
    if (!str1) return 1;
    char* str2 = read_string_by_length(n2);
    if (!str2) {
        free(str1);
        return 1;
    }

    printf("%d", FindMaxSlimSubstring(str1, str2));
    free(str1);
    free(str2);
    return 0;
}

#define ALPHBT ('z' - 'a' + 1)
void ToHist(int Hist[ALPHBT], char * str) {
    int i = 0 ;
    while (str[i]) {
        Hist[str[i] - 'a']++;
        i++;
    }
}
int my_strlen(char * str) {
    int i = 0;
    while (str[i]) i++;
    return i;
}
bool HistsIntersect(int Hist1[ALPHBT], int Hist2[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist1[i] && Hist2[i]) return true;
    }
    return false;
}
int FindMaxSlimSubstring(char* str1, char* str2) {
    int Hist2[ALPHBT] = {0};
    int window[ALPHBT] = {0};
    ToHist(Hist2,str2);
    int length1 = my_strlen(str1);
    int left = 0, right = -1;
    int maxlen = 0;
    while (right < length1) {
        if (!HistsIntersect(Hist2,window)) {
            //they don't intersect, try more ;)
            int currlen = right - left + 1;
            maxlen = (currlen > maxlen)? currlen : maxlen;
            right++;
            if (right < length1) window[str1[right] - 'a']++;
        }
        else {
            window[str1[left] - 'a']--;
            left++;
        }
    }
    return maxlen;
}
