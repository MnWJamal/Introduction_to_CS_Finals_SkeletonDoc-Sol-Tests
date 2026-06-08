#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int exam_q3(char* s);

int main(void) {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;
    char* s = malloc((n + 1) * sizeof(char));
    if (!s) return 1;
    if (scanf("%s", s) != 1) {
        free(s);
        return 1;
    }
    int changed = exam_q3(s);
    printf("%d\n%s", changed, s);
    free(s);
    return 0;
}

#define ALPHBT ('z' - 'a' + 1)
int DistanceBetweenHistAndString(int Hist[ALPHBT], char *str, bool ASCEND) {
    int distance = 0;
    int p = 0;
    if (ASCEND) {
        for (int i = 0 ; i < ALPHBT ; i++) {
            while (Hist[i]) {
                distance += ((char)(i + 'a') != str[p]);
                Hist[i]--;
                p++;
            }
        }
    }
    else{
        for (int i = ALPHBT - 1 ; i >= 0 ; i--) {
            while (Hist[i]) {
                distance += ((char)(i + 'a') != str[p])? 1 : 0;
                Hist[i]--;
                p++;
            }
        }
    }
    return distance;
}
int exam_q3(char* s) {
    //All are O(1) space:
    int HistAscend[ALPHBT] = {0};
    int HistDescend[ALPHBT] = {0};
    int HistForCopy[ALPHBT] = {0};

    int i = 0;
    while (s[i]) //O(n) time
    {
        HistAscend[s[i] - 'a']++;
        HistDescend[s[i] - 'a']++;
        HistForCopy[s[i] - 'a']++;
        i++;
    }

    int distance_ascend = DistanceBetweenHistAndString(HistAscend,s,true);
    int distance_descend = DistanceBetweenHistAndString(HistDescend,s,false);
    int p = 0;
    if (distance_ascend <= distance_descend) {
        for (int k = 0 ; k < ALPHBT ; k++) {
            while (HistForCopy[k]) {
                s[p] = (char)('a' + k);
                HistForCopy[k]--;
                p++;
            }
        }
        return distance_ascend;
    }
    else
    {
        for (int k = ALPHBT - 1 ; k >= 0 ; k--) {
            while (HistForCopy[k]) {
                s[p] = (char)('a' + k);
                HistForCopy[k]--;
                p++;
            }
        }
        return  distance_descend;
    }
}
