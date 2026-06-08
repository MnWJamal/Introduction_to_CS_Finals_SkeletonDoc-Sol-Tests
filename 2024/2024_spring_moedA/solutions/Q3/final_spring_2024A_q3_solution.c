#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(char arr[], int n);

// Do not change word_len_for_main!!!
int word_len_for_main(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

// Do not change read_arr!!!
char* read_arr(int* n) {
    if (scanf("%d", n) != 1) return NULL;
    char* arr = malloc((*n) * sizeof(char));
    if (!arr) return NULL;

    int used = 0;
    while (used < *n) {
        if (scanf("%s", arr + used) != 1) {
            free(arr);
            return NULL;
        }
        used += word_len_for_main(arr + used) + 1;
    }
    return arr;
}

// Do not change print_arr!!!
void print_arr(char arr[], int n) {
    int i = 0;
    while (i < n) {
        printf("%s", arr + i);
        i += word_len_for_main(arr + i) + 1;
        if (i < n) {
            printf(" ");
        }
    }
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    char* arr = read_arr(&n);
    if (!arr) return 1;
    exam_q3(arr, n);
    print_arr(arr, n);
    free(arr);
    return 0;
}


//THIS QUESTION IS A KNOCKOFF OF A HARDER QUESTION I SOLVED
//SO I JUST PASTED THE OFFICIAL SOLUTION HERE

void reverse(char s[], int n){
    if(n < 1)
        return;
    int left = 0;
    int right = n-1;
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
void exam_q3(char arr[], int n) {
    // reverse the entire string
    reverse(arr, n);
    int loc = 1, curr_len = 1;
    while(loc < n){
        if(arr[loc] == '\0'){
            reverse(arr+loc-curr_len, curr_len);
            curr_len = 1;
        } else {
            curr_len++;
        }
        loc++;
    }
    if(arr[n-1] != '\0'){
        reverse(arr + loc - curr_len, curr_len);
    }
}