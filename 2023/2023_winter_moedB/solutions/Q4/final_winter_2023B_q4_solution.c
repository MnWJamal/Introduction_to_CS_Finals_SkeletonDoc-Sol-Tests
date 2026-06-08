#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOOM "Boom!"
#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_B_q4(char *players[], char *words[], int n, int k);

char* read_string_by_length() {
    int len;
    if (scanf("%d", &len) != 1) {
        return NULL;
    }
    char* s = (char*)malloc((len + 1) * sizeof(char));
    if (s == NULL) {
        return NULL;
    }
    if (scanf("%s", s) != 1) {
        free(s);
        return NULL;
    }
    return s;
}

void free_strings(char** arr, int n) {
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, k;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    char** players = (char**)malloc(n * sizeof(char*));
    if (players == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        players[i] = read_string_by_length();
        if (players[i] == NULL) {
            free_strings(players, i);
            return 1;
        }
    }

    if (scanf("%d", &k) != 1) {
        free_strings(players, n);
        return 1;
    }
    char** words = (char**)malloc(k * sizeof(char*));
    if (words == NULL) {
        free_strings(players, n);
        return 1;
    }
    for (int i = 0; i < k; i++) {
        words[i] = read_string_by_length();
        if (words[i] == NULL) {
            free_strings(players, n);
            free_strings(words, i);
            return 1;
        }
    }

    printf("%d", exam_B_q4(players, words, n, k));

    free_strings(players, n);
    free_strings(words, k);
    return 0;
}

bool boom(char* word){
    return (word[0] && word[0] == BOOM[0] &&
            word[1] && word[1] == BOOM[1] &&
            word[2] && word[2] == BOOM[2] &&
            word[3] && word[3] == BOOM[3] &&
            word[4] && word[4] == BOOM[4] &&
            !word[5]);
}

int get_winner(bool dead[], int n, int i){
    if(i == n){
        return -1;
    }
    if(dead[i])
        return get_winner(dead, n, i+1);
    return i;
}
int q4_aux(char* players[], char* words[], int n, int k, bool dead[], int player, int word, int count){
    if(count == n-1)
        return get_winner(dead, n, 0);
    if(dead[player])
        return q4_aux(players, words, n, k, dead, (player+1)%n, word, count);


    if(boom(words[word])){
        dead[player] = true;
        return q4_aux(players, words, n, k, dead, (player+1)%n, (word+1)%k, count+1);
    }
    return q4_aux(players, words, n, k, dead, (player+1)%n, (word+1)%k, count);
}


int exam_B_q4(char* players[], char* words[], int n, int k) {
    bool* dead = (bool*)malloc(n * sizeof (bool));
    for(int i = 0; i<n; i++){
        dead[i] = false;
    }

    return q4_aux(players, words, n, k, dead, 0, 0, 0);
}

