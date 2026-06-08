#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define MAX_LINE 1005

char annoying(char* str);
void unAnnoy(char *arr[], int n);

void consume_rest_of_line() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void remove_line_ending(char s[]) {
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n' && s[i] != '\r') {
        ++i;
    }
    s[i] = '\0';
}

char* duplicate_line(char s[]) {
    int len = 0;
    while (s[len] != '\0') ++len;

    char* result = (char*)malloc((len + 1) * sizeof(char));
    if (!result) return NULL;
    for (int i = 0; i <= len; ++i) {
        result[i] = s[i];
    }
    return result;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();
    int mode;
    if (scanf("%d", &mode) != 1) return 1;
    consume_rest_of_line();

    if (mode == 1) {
        char str[MAX_LINE];
        if (!fgets(str, MAX_LINE, stdin)) str[0] = '\0';
        remove_line_ending(str);
        printf("%d", (int)(unsigned char)annoying(str));
        return 0;
    }

    if (mode == 2) {
        int n;
        if (scanf("%d", &n) != 1) return 1;
        consume_rest_of_line();

        char** arr = (char**)malloc(n * sizeof(char*));
        if (!arr && n > 0) return 1;

        char buffer[MAX_LINE];
        for (int i = 0; i < n; ++i) {
            if (!fgets(buffer, MAX_LINE, stdin)) buffer[0] = '\0';
            remove_line_ending(buffer);
            arr[i] = duplicate_line(buffer);
            if (!arr[i]) return 1;
        }

        unAnnoy(arr, n);

        for (int i = 0; i < n; ++i) {
            printf("[%s]", arr[i]);
            if (i + 1 < n) printf("\n");
            free(arr[i]);
        }
        free(arr);
        return 0;
    }

    return 1;
}

char annoying(char* str) {
    int Hist[128] = {0};
    int len = 0;
    while (str[len]) {
        Hist[(int)str[len]]++;
        len++;
    }
    int cmax = 0;
    char chmax = '\0';
    for (int idx = 0 ; idx < 127 ; idx++) {
        if (Hist[idx] > cmax) {
            cmax = Hist[idx];
            chmax = idx;
        }
    }
    return chmax;
}

void removeLetter(char * str, char letter) {
    //must be O(m) when m is lenght of str
    int i = 0;
    int offset = 0;
    while (str[i]) {
        while(str[i+offset] == letter) offset++;
        str[i] = str[i+offset];
        i++;
    }
}

void unAnnoy(char *arr[], int n) {
    // Write your code here
    for (int i = 0 ; i < n ; i ++) {
        removeLetter(arr[i],annoying(arr[i]));
    }
}
