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
int selected_players_aux(int judges[][3], int curr_judge ,int nj, int np,bool decided[], bool chosen[]);

int select_players(int judges[][3], int nj, int np, bool chosen[]) {
    // Write your code here (you can change the next line):
    bool * decided = malloc(np * sizeof(bool));
    if (!decided) return -1;
    for (int i = 0 ; i < np ; i++) {
        decided[i] = false;
        chosen[i] = false;
    }
    int res = selected_players_aux(judges, 0 ,nj,np,decided,chosen);
    free(decided);
    return res;
}

int selected_players_aux(int judges[][3], int curr_judge ,int nj, int np,bool decided[], bool chosen[]) {
    if (curr_judge == nj) {
        int pass = 0;
        for (int i = 0 ; i < np ; i ++) {
            pass += chosen[i];
        }
        return pass;
    }
    bool found_decession = false;
    int legal = -1;
    //try decisions
    for (int des = 0 ; des < 3 ; des++) {
        bool takeout = judges[curr_judge][des] < 0;
        int player = (takeout)? judges[curr_judge][des] * -1 : judges[curr_judge][des];
        player--;
        if (decided[player]) {
            if (chosen[player] == !takeout) //same decession, take it
                //note: no backtracking here, since no changes were made
            {
                int tmp_legal = selected_players_aux(judges,curr_judge+1,nj,np,decided,chosen);
                if (tmp_legal != -1) {
                    legal = tmp_legal;
                    found_decession = true;
                    break;
                } //no need to backtrack, changes are made from other judge
            }
            //other wise, continue
        }
        else {
            decided[player] = true;
            bool tmp = chosen[player]; //incase backtracking needed
            chosen[player] = !takeout;
            int tmp_legal = selected_players_aux(judges,curr_judge+1,nj,np,decided,chosen);
            if (tmp_legal != -1) {
                legal = tmp_legal;
                found_decession = true;
                break;
            }
            else {
                //backtrack
                decided[player] = false;
                chosen[player] = tmp;
            }
        }
    }
    if (!found_decession) return -1;
    return legal;
}