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

int exam_q3(char* s) {
    return 0;
}
