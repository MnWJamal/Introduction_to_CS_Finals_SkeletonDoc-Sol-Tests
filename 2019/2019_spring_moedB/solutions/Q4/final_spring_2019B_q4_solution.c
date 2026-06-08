#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool IsConstructible(int numbers[], int n, int result);

// Do not change read_arr!!!
int* read_arr(int n) {
    if (n < 0) return NULL;
    int* arr = malloc((n > 0 ? n : 1) * sizeof(int));
    if (!arr) return NULL;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", arr + i) != 1) {
            free(arr);
            return NULL;
        }
    }
    return arr;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, result;
    if (scanf("%d %d", &n, &result) != 2) return 1;

    int* numbers = read_arr(n);
    if (!numbers) return 1;

    printf("%d", IsConstructible(numbers, n, result) ? 1 : 0);

    free(numbers);
    return 0;
}


//a function to print operations (bored during exam soooo :) )
void printLog(int numbers[], int used[], int n, int result) {
    printf("\n------------------------------------\n");
    int number_so_far = 0;
    for (int i = 0 ; i < n ; i++) {
        if (used[i]) {
            if (number_so_far == 0) {
                if (used[i] == -1) printf("- ");
                printf("%d ",numbers[i]);
            }
            else {
                if (used[i] == -1) {
                    printf("-");
                }
                else printf("+");
                if (numbers[i] < 0) {
                    printf(" (%d) ",numbers[i]);
                }
                else {
                    printf(" %d ",numbers[i]);
                }
            }
            number_so_far++;
        }
    }
    printf("= %d",result);
    printf("\n------------------------------------\n\n");
}
bool IsConstructible_aux(int numbers[], int n, int result, int used[], int current){
    if (current == result) return true;
    for (int i = 0 ; i < n ; i++) {
        if (!used[i]) {
            if ((current > result && numbers[i] >= 0) || (current < result && numbers[i] < 0) ) {
                //try substract i:
                used[i] = -1;
                if (IsConstructible_aux(numbers,n,result,used,current-numbers[i]))
                    return true;
                //backtrack:
                used[i] = 0;
            }
            else {
                //try add i:
                used[i] = 1;
                if (IsConstructible_aux(numbers,n,result,used,current + numbers[i]))
                    return true;
                //backtrack:
                used[i] = 0;
            }
        }
    }
    return false;
}

bool IsConstructible(int numbers[], int n, int result) {
    int * used = malloc(n*sizeof(int));
    if (!used) return false;
    for (int i = 0 ; i < n ; i++) used[i] = 0;
    bool flag = false;
    for (int i = 0 ; i < n ; i++) {
        if (!used[i]) {
            //try substract i:
            used[i] = -1;
            if (IsConstructible_aux(numbers,n,result,used,-1 * numbers[i])) {
                flag = true;
                break;
            }
            //backtrack:
            used[i] = 0;

            //try add i:
            used[i] = 1;
            if (IsConstructible_aux(numbers,n,result,used, numbers[i])) {
                flag = true;
                break;
            }
            //backtrack:
            used[i] = 0;

        }
    }

    // if (flag) {
    //     //print operation ;)
    //     printLog(numbers,used,n,result);
    // }
    free(used);
    return flag;
}
