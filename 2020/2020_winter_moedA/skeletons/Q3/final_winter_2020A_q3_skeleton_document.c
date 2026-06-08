#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool rearrangeStringToPalindrome(char* str);

// Do not change read_string!!!
char* read_string(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;
    char* str = malloc((*n + 1) * sizeof(char));
    if (!str) return NULL;
    for (int i = 0; i < *n; i++) {
        if (scanf(" %c", str + i) != 1) {
            free(str);
            return NULL;
        }
    }
    str[*n] = '\0';
    return str;
}

// Do not change the judge code!!!
void count_letters(char* str, int n, int count[]) {
    for (int i = 0; i < 26; i++) count[i] = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] < 'a' || str[i] > 'z') continue;
        count[str[i] - 'a']++;
    }
}

// Do not change the judge code!!!
bool same_letters(char* before, char* after, int n) {
    int count_before[26], count_after[26];
    count_letters(before, n, count_before);
    count_letters(after, n, count_after);
    for (int i = 0; i < 26; i++) {
        if (count_before[i] != count_after[i]) return false;
    }
    return after[n] == '\0';
}

// Do not change the judge code!!!
bool is_palindrome(char* str, int n) {
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - 1 - i]) return false;
    }
    return true;
}

// Do not change the judge code!!!
bool can_be_rearranged_to_palindrome(char* str, int n) {
    int count[26];
    int odd = 0;
    count_letters(str, n, count);
    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 != 0) odd++;
    }
    return odd <= 1;
}

// Do not change the judge code!!!
bool judge_answer(char* before, char* after, int n, bool answer) {
    bool expected = can_be_rearranged_to_palindrome(before, n);
    if (answer != expected) return false;
    if (!same_letters(before, after, n)) return false;
    if (answer && !is_palindrome(after, n)) return false;
    return true;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    char* str = read_string(&n);
    if (!str) return 1;
    char* before = malloc((n + 1) * sizeof(char));
    if (!before) {
        free(str);
        return 1;
    }
    for (int i = 0; i <= n; i++) before[i] = str[i];

    bool answer = rearrangeStringToPalindrome(str);
    printf("%d", judge_answer(before, str, n, answer) ? 1 : 0);

    free(before);
    free(str);
    return 0;
}

bool rearrangeStringToPalindrome(char* str) {
    // Write your code here (you can change the next line):
    return false;
}
