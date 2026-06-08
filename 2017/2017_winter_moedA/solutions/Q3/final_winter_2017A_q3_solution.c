#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define MAX_INPUT_WORD_LEN 10000

bool IsWord(char mainWord[], char testWord[]);
int WordScore(char *dictionary[], int n, char *word);

// Do not change str_len!!!
int str_len(const char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

// Do not change read_word!!!
char* read_word() {
    char buffer[MAX_INPUT_WORD_LEN + 1];
    if (scanf("%10000s", buffer) != 1) return NULL;

    int len = str_len(buffer);
    char* word = malloc((len + 1) * sizeof(char));
    if (!word) return NULL;

    for (int i = 0; i <= len; i++) {
        word[i] = buffer[i];
    }
    return word;
}

// Do not change free_dictionary!!!
void free_dictionary(char** dictionary, int n) {
    if (!dictionary) return;
    for (int i = 0; i < n; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int mode;
    if (scanf("%d", &mode) != 1) return 1;

    if (mode == 1) {
        char* mainWord = read_word();
        char* testWord = read_word();
        if (!mainWord || !testWord) {
            free(mainWord);
            free(testWord);
            return 1;
        }
        printf("%d", IsWord(mainWord, testWord) ? 1 : 0);
        free(mainWord);
        free(testWord);
        return 0;
    }

    if (mode == 2) {
        int n;
        if (scanf("%d", &n) != 1 || n < 0) return 1;

        char** dictionary = malloc(((n > 0) ? n : 1) * sizeof(char*));
        if (!dictionary) return 1;

        for (int i = 0; i < n; i++) {
            dictionary[i] = read_word();
            if (!dictionary[i]) {
                free_dictionary(dictionary, i);
                return 1;
            }
        }

        char* word = read_word();
        if (!word) {
            free_dictionary(dictionary, n);
            return 1;
        }

        printf("%d", WordScore(dictionary, n, word));
        free(word);
        free_dictionary(dictionary, n);
        return 0;
    }

    return 1;
}
#define ALPHBT ('z' - 'a' + 1)
void Histify(int Hist[ALPHBT], char * word) {
    int i = 0;
    while (word[i]) {
        Hist[word[i] - 'a']++;
        i++;
    }
}
void ResetAndHistify(int Hist[ALPHBT], char * word) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        Hist[i] = 0;
    }
    Histify(Hist,word);
}
bool HistContains(int parent[ALPHBT], int child[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        if (child[i] > parent[i]) return false;
    }
    return true;
}

bool IsWord(char mainWord[], char testWord[]) {
    int parent[ALPHBT] = {0};
    int child[ALPHBT] = {0};
    Histify(parent,mainWord);
    Histify(child,testWord);
    return HistContains(parent,child);
}
bool Equals(char * str1, char * str2) {
    int i = 0;
    while (str1[i] && str2[i]){
        if (str1[i] != str2[i]) return false;
    }
    return str1[i] == str2[i];
}
int WordScore(char *dictionary[], int n, char *word) {
    int parent[ALPHBT] = {0};
    Histify(parent,word); //O(m)
    int child[ALPHBT] = {0};
    int wordscore = 0;
    for (int i = 0 ; i < n ; i++) //O(n) total
    {
        ResetAndHistify(child,dictionary[i]); //O(1) since words are max 20 ch
        wordscore += (HistContains(parent,child) && !Equals(dictionary[i],word)); //O(1) compares histograms
        //also Equals is O(1) since it runs until a word ends basically not gonna run
        //longer than 20 iterations
    }

    return wordscore;
}
