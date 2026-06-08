#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

char find_first_unique(char *str);

// Do not change read_string!!!
char* read_string() {
    int capacity = 16;
    int length = 0;
    char* str = malloc(capacity * sizeof(char));
    if (!str) return NULL;

    int ch;
    while ((ch = getchar()) != EOF) {
        if (length + 1 >= capacity) {
            int new_capacity = capacity * 2;
            char* new_str = malloc(new_capacity * sizeof(char));
            if (!new_str) {
                free(str);
                return NULL;
            }
            for (int i = 0; i < length; i++) {
                new_str[i] = str[i];
            }
            free(str);
            str = new_str;
            capacity = new_capacity;
        }
        str[length++] = (char)ch;
    }

    if (length > 0 && str[length - 1] == '\n') {
        length--;
    }
    if (length > 0 && str[length - 1] == '\r') {
        length--;
    }

    str[length] = '\0';
    return str;
}

// Do not change print_result!!!
void print_result(char result) {
    if (result == '\0') {
        printf("\\0");
    } else {
        printf("%c", result);
    }
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char* str = read_string();
    if (!str) return 1;

    print_result(find_first_unique(str));

    free(str);
    return 0;
}

char find_first_unique(char *str) {
    // Write your code here (you can change the next line):
    return '\0';
}
