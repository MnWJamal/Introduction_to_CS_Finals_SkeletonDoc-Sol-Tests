#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int select_players(int judges[][3], int nj, int np, bool chosen[]);

// Do not change count_chosen!!!
int count_chosen(bool chosen[], int np) {
    int count = 0;
    for (int i = 0; i < np; i++) {
        if (chosen[i]) {
            count++;
        }
    }
    return count;
}

// Do not change is_vote_satisfied!!!
bool is_vote_satisfied(int vote, bool chosen[]) {
    int player = vote > 0 ? vote : -vote;
    if (vote > 0) {
        return chosen[player - 1];
    }
    return !chosen[player - 1];
}

// Do not change is_solution_valid!!!
bool is_solution_valid(int judges[][3], int nj, bool chosen[]) {
    for (int i = 0; i < nj; i++) {
        bool judge_is_satisfied = false;
        for (int j = 0; j < 3; j++) {
            if (is_vote_satisfied(judges[i][j], chosen)) {
                judge_is_satisfied = true;
            }
        }
        if (!judge_is_satisfied) {
            return false;
        }
    }
    return true;
}

// Do not change main!!!
// Uncomment the first line in main if you don't know the answer.
int main() {
    // printIDontKnow();

    int nj, np, expected_exists;
    if (scanf("%d %d %d", &nj, &np, &expected_exists) != 3) {
        return 1;
    }

    int (*judges)[3] = NULL;
    if (nj > 0) {
        judges = malloc(nj * sizeof(*judges));
        if (!judges) {
            return 1;
        }
    }

    for (int i = 0; i < nj; i++) {
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &judges[i][j]) != 1) {
                free(judges);
                return 1;
            }
        }
    }

    bool* chosen = calloc(np, sizeof(bool));
    if (!chosen) {
        free(judges);
        return 1;
    }

    int result = select_players(judges, nj, np, chosen);

    bool accepted = false;
    if (result == -1) {
        accepted = (expected_exists == 0);
    } else if (expected_exists == 1 && result >= 0 && result <= np) {
        accepted = (result == count_chosen(chosen, np)) &&
                   is_solution_valid(judges, nj, chosen);
    }

    printf("%d", accepted ? 1 : 0);

    free(chosen);
    free(judges);
    return 0;
}

int select_players(int judges[][3], int nj, int np, bool chosen[]) {
    // Write your code here (you can change the next line):
    (void)judges;
    (void)nj;
    (void)np;
    (void)chosen;
    return -1;
}
