#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int length_of_longest_stunning_substr(char *str);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char str[4096];
    if (scanf("%4095s", str) != 1) return 1;

    printf("%d", length_of_longest_stunning_substr(str));
    return 0;
}

#define ALPHBT ('z'-'a'+1)

bool fantasic(int Hist[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist[i] > 1) return false;
    }
    return true;
}
int length_of_longest_stunning_substr(char *str) {
    if (!*str) return 0;
    int left = 0 , right = 0, max_fanta = 1;
    int Hist[ALPHBT] = {0};
    Hist[str[0] - 'a']++;
    while (str[right]) {
        int len = right - left + 1;
        if (fantasic(Hist)) {
            max_fanta =  (len > max_fanta)? len : max_fanta;
            right++;
            if (str[right])
                Hist[str[right] - 'a']++;
        }
        else {
            Hist[str[left] - 'a']--;
            left++;
        }
    }
    right--;
    while (str[left])
    {
        int len = right - left + 1;
        if (fantasic(Hist)) {
            max_fanta =  (len > max_fanta)? len : max_fanta;
        }
        Hist[str[left] - 'a']--;
        left++;
    }
    return max_fanta;
}