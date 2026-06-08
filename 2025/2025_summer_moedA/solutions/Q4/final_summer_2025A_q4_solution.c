#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define N 2
#define K 6

int exam_q4(int mat1[N * 5][3], int mat2[K][K]);

int main(void) {
    // printIDontKnow();

    int mat1[N * 5][3];
    int mat2[K][K];
    for (int i = 0; i < N * 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &mat1[i][j]) != 1) return 1;
        }
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (scanf("%d", &mat2[i][j]) != 1) return 1;
        }
    }
    printf("%d", exam_q4(mat1, mat2));
    return 0;
}
int count_meals(int meals[K]) {
    int ct = 0;
    for (int i = 0 ; i < K ; i++) {
        ct += (meals[i] != 0)? 1 : 0;
    }
    return ct;
}
bool can_have_it(int mat[K][K], int ordered[N*5], int current, int meal) {
    int first_on_table = (int)(current / 5);
    first_on_table *= 5;
    for (int person = first_on_table ; person < current ; person++)
    {
        if (!mat[ordered[person]][meal]) return false;
    }
    return true;
}
int exam_q4_aux(int mat1[N * 5][3], int mat2[K][K], int ordered[N*5], int current, int meals[K]) {
    if (current == N*5) return count_meals(meals);
    int found_meals = false;
    int min_meals = -1;
    for (int meal = 0 ; meal < 3 ; meal++) {
        if (can_have_it(mat2,ordered,current,mat1[current][meal])) {
            //try take it ;)
            ordered[current] = mat1[current][meal];
            meals[mat1[current][meal]]++;
            int choice_meals = exam_q4_aux(mat1,mat2,ordered,current+1,meals);
            if (choice_meals != -1) {
                if (!found_meals) {
                    found_meals = true;
                    min_meals = choice_meals;
                }
                else {
                    min_meals = (choice_meals < min_meals)? choice_meals : min_meals;
                }
            }

            //backtracking:
            ordered[current] = -1;
            meals[mat1[current][meal]]--;
        }
    }

    return min_meals; //DNE => -1
}
int exam_q4(int mat1[N * 5][3], int mat2[K][K]) {
    int ordered[N*5];
    for (int i = 0 ; i < N*5; i++) {
        ordered[i] = -1;
    }
    int meals[K] = {0};
    int min_meals = exam_q4_aux(mat1,mat2,ordered,0,meals);
    //if it was dynamic alloc we free he ;)
    return min_meals;
}
