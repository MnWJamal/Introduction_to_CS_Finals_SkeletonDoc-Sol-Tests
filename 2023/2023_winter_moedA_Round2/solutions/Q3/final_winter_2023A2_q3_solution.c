#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_A2_q3(char* str1, char* str2);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char str1[10005];
    char str2[10005];
    if (scanf("%10004s", str1) != 1) return 1;
    if (scanf("%10004s", str2) != 1) return 1;
    printf("%d", exam_A2_q3(str1, str2));
    return 0;
}
#define ALPHBT ('z'-'a'+1)
bool AlmostPermutation(int Hist1[ALPHBT], int Hist2[ALPHBT]) {
    int total_delta = 0;
    for (int i = 0 ; i < ALPHBT ; i++) {
        int delta = Hist1[i] - Hist2[i];
        delta = (delta < 0)? -1 * delta : delta;
        total_delta += delta;
        if (total_delta > 1)
            return false;
    }
    return true;
}
int myLen(char * str) {
    for (int i = 0 ; ; i++) if (!str[i]) return i;
}
int HistifyAndLen(int Hist[ALPHBT], char * str) {
    int i = 0;
    while (str[i]) {
        Hist[str[i] - 'a']++;
        i++;
    }
    return i;
}
int countAlmostPerms(int windowlength, char* str, int hist[ALPHBT]) {
    if (windowlength <= 0) return 0;
    int window[ALPHBT] = {0};
    for (int i = 0 ; i < windowlength ; i++) {
        window[str[i] - 'a']++;
    }
    int count = (AlmostPermutation(window,hist))? 1 : 0;
    int len = myLen(str);
    for (int head = 1 ; head <= len - windowlength ; head++) {
        window[str[head - 1] - 'a']--;
        window[str[head + windowlength - 1] - 'a']++;
        if (AlmostPermutation(window,hist)) count++;
    }
    return count;
}
int exam_A2_q3(char* str1, char* str2) {
    int count = 0;
    int hist2[ALPHBT] = {0};
    int len2 = HistifyAndLen(hist2,str2);
    count += countAlmostPerms(len2 + 1, str1, hist2);

    return count;
}
