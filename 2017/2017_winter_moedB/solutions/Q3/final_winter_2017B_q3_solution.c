#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STR_LEN 10000

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int GetKShortSubstring(char *str, int k);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int k;
    char* str = malloc((MAX_STR_LEN + 1) * sizeof(char));
    if (!str) return 1;

    if (scanf("%d", &k) != 1) {
        free(str);
        return 1;
    }
    if (scanf("%10000s", str) != 1) {
        free(str);
        return 1;
    }

    printf("%d", GetKShortSubstring(str, k));

    free(str);
    return 0;
}

#define ALPHBT ('z' - 'a' + 1)

bool IsKVital(int Hist[ALPHBT], int k) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist[i] >= k) return true;
    }
    return false;
}


int GetKShortSubstring(char *str, int k)
{
    if (k <= 1) return 0;
    int len = 0;
    while (str[len]) len++;
    if (len == 0) return 0;
    int right = 0, left = 0;
    int Hist[ALPHBT] = {0};
    int max_kshort = 0;
    Hist[str[0]-'a']++;
    while (right < len) {
        bool isKvital = IsKVital(Hist,k);
        bool isKM1vital = IsKVital(Hist,k-1);
        if (!isKvital && isKM1vital) {
            int currlength = right - left + 1;
            max_kshort = (currlength > max_kshort)? currlength : max_kshort;
        }
        //window steps:
        if (isKvital) //to many letters:
        {
            Hist[str[left] - 'a']--;
            left++;
        }
        else //not enought letters
        {
            right++;
            if (right < len) Hist[str[right] - 'a']++;
        }
    }
    right = len-1;
    while (left < len) {
        bool isKvital = IsKVital(Hist,k);
        bool isKM1vital = IsKVital(Hist,k-1);
        if (!isKvital && isKM1vital) {
            int currlength = right-left + 1;
            max_kshort = (currlength > max_kshort)? currlength : max_kshort;
        }
        Hist[str[left] - 'a']--;
        left++;
    }
    return max_kshort;
}
