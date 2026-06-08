#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

char* exam_q3(char* s1, char* s2);

char* read_string(void) {
    int n;
    if (scanf("%d", &n) != 1) return NULL;
    char* s = malloc((n + 1) * sizeof(char));
    if (!s) return NULL;
    if (scanf("%s", s) != 1) {
        free(s);
        return NULL;
    }
    return s;
}

int main(void) {
    // printIDontKnow();

    char* s1 = read_string();
    if (!s1) return 1;
    char* s2 = read_string();
    if (!s2) {
        free(s1);
        return 1;
    }
    char* result = exam_q3(s1, s2);
    if (!result) {
        free(s1);
        free(s2);
        return 1;
    }
    printf("%s", result);
    free(result);
    free(s1);
    free(s2);
    return 0;
}

int my_strlen(char * str) {
    int i = 0;
    while (str[i]) i++;
    return i;
}
int my_max(int a, int b){return (a > b)? a : b;}
int my_min(int a, int b){return (a > b)? b : a;}

char* exam_q3(char* s1, char* s2) {
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int max_len = my_max(len1,len2);
    int min_len = my_min(len1,len2);
    char * str_max = (len1 == max_len)? s1 : s2;
    char * str_min = (str_max == s1)? s2 : s1;
    char * result = malloc((max_len+1)*sizeof(char));
    if (!result) return NULL;
    result[max_len] = '\0';
    int carry = 0;
    for (int digit = 0; digit < min_len ; digit++) {
        int dg1 = str_max[max_len - 1 - digit] - '0';
        int dg2 = str_min[min_len - 1 - digit] - '0';
        int dg_res = dg2 + dg1 + carry;
        carry = dg_res / 10;
        dg_res %= 10;
        result[max_len - 1 - digit] = (char)(dg_res + '0');
    }
    int curr_digit = min_len;
    while (curr_digit < max_len) {
        int dg1 = str_max[max_len - 1 - curr_digit] - '0';
        int dg_res = dg1 + carry;
        carry = dg_res / 10;
        dg_res %= 10;
        result[max_len - 1 - curr_digit] = (char)(dg_res + '0');
        curr_digit++;
    }
    if (carry) {
        char * result2 = malloc((max_len+2)*sizeof(char));
        if (!result2) return NULL;
        for (int i = 0 ; i <= max_len ; i++) {
            result2[i+1] = result[i];
        }
        free(result);
        result2[0] = '1';
        return result2;
    }
    return result;
}
