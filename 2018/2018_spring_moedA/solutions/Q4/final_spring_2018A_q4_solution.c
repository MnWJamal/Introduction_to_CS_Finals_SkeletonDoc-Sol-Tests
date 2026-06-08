#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define MAX_WORD_LENGTH 256

bool Scrambleableable(char *cubes[], int n, char* word);

char* read_word() {
    char buffer[MAX_WORD_LENGTH];
    if (scanf("%255s", buffer) != 1) return NULL;

    int len = 0;
    while (buffer[len] != '\0') ++len;

    char* result = (char*)malloc((len + 1) * sizeof(char));
    if (!result) return NULL;
    for (int i = 0; i <= len; ++i) {
        result[i] = buffer[i];
    }
    return result;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    char** cubes = (char**)malloc(n * sizeof(char*));
    if (!cubes && n > 0) return 1;

    for (int i = 0; i < n; ++i) {
        cubes[i] = read_word();
        if (!cubes[i]) return 1;
    }

    char* word = read_word();
    if (!word) return 1;

    printf("%d", Scrambleableable(cubes, n, word) ? 1 : 0);

    for (int i = 0; i < n; ++i) {
        free(cubes[i]);
    }
    free(cubes);
    free(word);
    return 0;
}
bool Scrambleableable_aux(char *cubes[], int n, char* word, bool* used);
bool Scrambleableable(char *cubes[], int n, char* word)
{
    bool * used = malloc(n*sizeof(bool));
    if (!used) return false; //here you can return error ;)
    for (int i = 0 ; i < n ; i++) used[i] = false;
    bool result = Scrambleableable_aux(cubes,n,word,used);
    free(used);
    return result;
}
bool Scrambleableable_aux(char *cubes[], int n, char* word, bool* used) {
    if (!cubes || !word || !used) return false; //error ;)
    if (word[0] == '\0') return true;
    for (int i = 0 ; i < n ; i ++) {
        if (!used[i]) {
            //see if we can find letter:
            int j = 0;
            while (cubes[i][j]) {
                if (cubes[i][j] == word[0]) {
                    //found a cube that fits, lets try it:
                    used[i] = true;
                    bool legal = Scrambleableable_aux(cubes,n,word+1,used);
                    if (legal) return true; //found combo
                    //backtrack here:
                    used[i] = false; //try another cube :(
                }
                j++;
            }
        }
    }
    //no cube found for this subtree => invalid previous choice / DNE
    return false;
}
