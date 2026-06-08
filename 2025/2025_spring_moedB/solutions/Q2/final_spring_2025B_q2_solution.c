#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q2(char *s, char *t);

// Do not change read_string!!!
char* read_string(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char* s = malloc((*n + 1) * sizeof(char));
    if (!s) return NULL;
    if (scanf("%s", s) != 1) {
        free(s);
        return NULL;
    }
    return s;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n_s, n_t;
    char* s = read_string(&n_s);
    char* t = read_string(&n_t);
    if (!s || !t) {
        free(s);
        free(t);
        return 1;
    }

    printf("%d", exam_q2(s, t));

    free(s);
    free(t);
    return 0;
}
int my_len(char * str) {
    int i = 0;
    while (str[i]) i++;
    return i;
}
#define ALPHBT ('z' - 'a' + 1)
bool equal_hists(int Hist1[ALPHBT], int Hist2[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (Hist1[i] != Hist2[i]) return false;
    }
    return true;
}
int exam_q2(char *s, char *t) {
    // Write your code here (you can change the next line):
    int len_s = my_len(s);
    int len_t = my_len(t);
    if (len_t > len_s) return 0;
    int Hist_t[ALPHBT] = {0};
    int Hist_window[ALPHBT] = {0};
    for (int i = 0 ; i < len_t ; i++) {
        Hist_t[t[i] - 'a']++;
        Hist_window[s[i] - 'a']++;
    }
    int count_anagrams = (equal_hists(Hist_t,Hist_window))? 1 : 0;
    for (int window_head = 1; window_head <= len_s - len_t ; window_head++) {
        Hist_window[s[window_head-1] - 'a']--;
        Hist_window[s[window_head+len_t - 1] - 'a']++;
        count_anagrams += (equal_hists(Hist_t,Hist_window))? 1 : 0;
    }
    return count_anagrams;
}
