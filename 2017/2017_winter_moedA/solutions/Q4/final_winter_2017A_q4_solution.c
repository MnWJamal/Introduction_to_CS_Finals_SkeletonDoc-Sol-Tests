#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define M 42
#define MAX_TABLES 42

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool SetTables(int vetoes[][M], int sitting[], int n);

// Do not change read_vetoes!!!
int (*read_vetoes(int* n))[M] {
    if (scanf("%d", n) != 1) return NULL;
    if (*n < 0) return NULL;

    int (*vetoes)[M] = malloc(((*n > 0) ? *n : 1) * sizeof(*vetoes));
    if (!vetoes) return NULL;

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d", &vetoes[i][j]) != 1) {
                free(vetoes);
                return NULL;
            }
        }
    }
    return vetoes;
}

// Do not change is_valid_sitting!!!
bool is_valid_sitting(int vetoes[][M], int sitting[], int n) {
    for (int i = 0; i < n; i++) {
        if (sitting[i] < 0 || sitting[i] >= MAX_TABLES) return false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            int other = vetoes[i][j];
            if (other == -1) continue;
            if (other < 0 || other >= n) return false;
            if (sitting[i] == sitting[other]) return false;
        }
    }
    return true;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    int (*vetoes)[M] = read_vetoes(&n);
    if (!vetoes) return 1;

    int* sitting = malloc(((n > 0) ? n : 1) * sizeof(int));
    if (!sitting) {
        free(vetoes);
        return 1;
    }
    for (int i = 0; i < n; i++) sitting[i] = -1;

    bool result = SetTables(vetoes, sitting, n);
    if (!result) {
        printf("0");
    } else {
        printf("%d", is_valid_sitting(vetoes, sitting, n) ? 1 : 0);
    }

    free(sitting);
    free(vetoes);
    return 0;
}
bool SetTablesAuxil(int vetoes[][M], int sitting[], int n, int current_table, int people_on_table, int people_remaining);

bool SetTables(int vetoes[][M], int sitting[], int n) {
    for (int i = 0 ; i < n ; i++) sitting[i] = -1;
    return SetTablesAuxil(vetoes,sitting,n,0,0,n);
}

bool can_join(int person, int table, int sitting[], int vetoes[][M], int n) {
    for (int i = 0; i < n ; i++) {
        if (sitting[i] == table && i != person) {
            for (int veto = 0 ; veto < M ; veto++) {
                if (vetoes[i][veto] == person || vetoes[person][veto] == i) return false;
            }
        }
    }
    return true;
}
bool SetTablesAuxil(int vetoes[][M], int sitting[], int n, int current_table, int people_on_table, int people_remaining)
{
    if (people_remaining == 0) return (current_table <= 41);
    for (int i = 0 ; i < n ; i++) {
        if (sitting[i] == -1) //not sitting yet
        {
            //can join? try take
            if (can_join(i,current_table,sitting,vetoes,n)) {
                sitting[i] = current_table;
                bool legal = SetTablesAuxil(vetoes,sitting,n,current_table,people_on_table+1,people_remaining-1);
                if (legal) return true; //do NOT backteack if found solution
                //backtrack:
                sitting[i] = -1;
            }
            //or not take him try somone else
        }
    }
    //or not take nobody else (if there is at least one person to not loop inf)
    if (people_on_table > 0) {
        bool legal = SetTablesAuxil(vetoes,sitting,n,current_table+1,0,people_remaining);
        if (legal) return true;
    }
    return false;
}