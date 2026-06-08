#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool Scramble(char *cubes[], int n, int colors[], char* target);

// Do not change read_word!!!
char* read_word(void) {
    char buffer[1024];
    if (scanf("%1023s", buffer) != 1) return NULL;
    int len = 0;
    while (buffer[len] != '\0') ++len;
    char* word = malloc((len + 1) * sizeof(char));
    if (!word) return NULL;
    for (int i = 0; i <= len; ++i) word[i] = buffer[i];
    return word;
}

// Do not change read_target!!!
char* read_target(void) {
    int len;
    if (scanf("%d", &len) != 1) return NULL;
    char* target = malloc((len + 1) * sizeof(char));
    if (!target) return NULL;
    for (int i = 0; i < len; ++i) {
        if (scanf(" %c", target + i) != 1) {
            free(target);
            return NULL;
        }
    }
    target[len] = '\0';
    return target;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    char** cubes = NULL;
    int* colors = NULL;
    if (n > 0) {
        cubes = malloc(n * sizeof(char*));
        colors = malloc(n * sizeof(int));
        if (!cubes || !colors) {
            free(cubes);
            free(colors);
            return 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cubes[i] = read_word();
        if (!cubes[i] || scanf("%d", colors + i) != 1) {
            for (int j = 0; j <= i; ++j) free(cubes[j]);
            free(cubes);
            free(colors);
            return 1;
        }
    }

    char* target = read_target();
    if (!target) {
        for (int i = 0; i < n; ++i) free(cubes[i]);
        free(cubes);
        free(colors);
        return 1;
    }

    printf("%s", Scramble(cubes, n, colors, target) ? "true" : "false");

    for (int i = 0; i < n; ++i) free(cubes[i]);
    free(cubes);
    free(colors);
    free(target);
    return 0;
}
bool contains(char * str, char letter) {
    while (*str) {
        if (*str == letter) return true;
        str++;
    }
    return false;
}
bool Scramble_aux(char *cubes[], int n, int colors[],bool used[], bool color_used[], char* target) {
    if (!*target) return true;
    for (int i = 0 ; i < n ; i++) {
        if (!used[i] && !color_used[colors[i]]
            && contains(cubes[i],*target))
        {
            //not used, color unique, and has letter:
            used[i] = true;
            color_used[colors[i]] = true;
            if (Scramble_aux(cubes,n,colors,used,color_used,target+1))
                return  true; //word made
            //backtrack (bad choice):
            used[i] = false;
            color_used[colors[i]] = false;
        }
    }
    //no subtree with word / didn't find letter:
    return false;
}


bool Scramble(char *cubes[], int n, int colors[], char* target) {
    bool * used = malloc(sizeof(int)*n);
    bool * color_used = malloc(sizeof(bool)*n);
    if (!used || !color_used) {
        if (used) free(used);
        if (color_used) free(color_used);
        return false;
    }
    for (int i = 0 ; i < n ; i++) {
        used[i] = false;
        color_used[i] = false;
    }
    bool result = Scramble_aux(cubes,n,colors,used,color_used,target);
    free(used);
    free(color_used);
    return result;
}
