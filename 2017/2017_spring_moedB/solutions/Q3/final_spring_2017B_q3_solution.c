#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int count_balance(char* str);

// Do not change read_str!!!
char* read_str() {
    int n;
    if (scanf("%d", &n) != 1) return NULL;
    if (n < 0) return NULL;

    char* str = malloc((n + 1) * sizeof(char));
    if (!str) return NULL;

    for (int i = 0; i < n; i++) {
        if (scanf(" %c", str + i) != 1) {
            free(str);
            return NULL;
        }
    }
    str[n] = '\0';
    return str;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char* str = read_str();
    if (!str) return 1;

    printf("%d", count_balance(str));

    free(str);
    return 0;
}

#define ALPHBT ('z' - 'a' + 1)
bool compareHistNorms(int hist1[ALPHBT], int hist2[ALPHBT]) {
    for (int i = 0 ; i < ALPHBT ; i++) {
        int normal1 = hist1[i] > 0;
        int normal2 = hist2[i] > 0;
        if (normal1 != normal2) return false;
    }
    return true;
}
int my_strlen(char * str) {
    int i = 0;
    while (str[i]) i++;
    return i;
}

int count_balance(char* str)
{
    int counter = 0;

    int len = my_strlen(str);
    if (len <= 1) return 0;

    int rightHist[ALPHBT] = {0};
    int leftHist[ALPHBT] = {0};

    for (int i = 0 ; i < len ; i++) {
        rightHist[str[i] - 'a']++;
    }

    int point_of_balance = 0;
    while (point_of_balance < len) {
        leftHist[str[point_of_balance] - 'a']++;
        rightHist[str[point_of_balance] - 'a']--;

        if (compareHistNorms(leftHist,rightHist)) {
            counter++;
        }

        point_of_balance++;
    }

    return counter;
}
