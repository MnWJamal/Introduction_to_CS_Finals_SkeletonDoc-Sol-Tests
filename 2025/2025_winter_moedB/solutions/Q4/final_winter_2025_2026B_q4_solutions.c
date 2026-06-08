#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
#define N 5

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int examB_q4(char mat[N][N]);

// Do not change read_mat!!!
bool read_mat(char mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf(" %c", &mat[i][j]) != 1) return false;
        }
    }
    return true;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    char mat[N][N];
    if (!read_mat(mat)) return 1;

    printf("%d", examB_q4(mat));
    return 0;
}


void get_next_location(int i, int j, int* next_i, int* next_j, char direction) {
    switch(direction) {
        case 'R':
            *next_i = i;
        *next_j = j + 1;
        break;
        case 'L':
            *next_i = i;
        *next_j = j - 1;
        break;
        case 'U':
            *next_i = i - 1;
            *next_j = j;
            break;
        case 'D':
            *next_i = i + 1;
            *next_j = j;
            break;
    }
}

#define DIRECTIONS 4

int find_sol_rec(char mat[N][N], int cur_i, int cur_j, char cur_dir) {
    if (cur_i == N - 1 && cur_j == N - 1) {
        return 0;
    }
    if (cur_i < 0 || cur_i >= N || cur_j < 0 || cur_j >= N) {
        return -1;
    }
    if (mat[cur_i][cur_j] == 'E') {
        int next_i, next_j;
        get_next_location(cur_i, cur_j, &next_i, &next_j, cur_dir);
        return find_sol_rec(mat, next_i, next_j, cur_dir);
    }
    if(mat[cur_i][cur_j] == 'X') {
        //This checks that we don't go over the same crane twice
        //to avoid infinite loops
        return -1;
    }
    int res = -1;
    char og_dir = mat[cur_i][cur_j];
    mat[cur_i][cur_j] = 'X';
    char options[DIRECTIONS] = {'R', 'L', 'U', 'D'};
    for(int i = 0; i < DIRECTIONS; ++i) {
        int next_i, next_j;
        get_next_location(cur_i, cur_j, &next_i, &next_j, options[i]);
        int cur_res = find_sol_rec(mat, next_i, next_j, options[i]);
        if(cur_res == -1) {
            continue;
        }
        //add 1 if we reprogrammed the current crane
        cur_res += (options[i] != og_dir);

        if(res == -1 || cur_res < res) {
            res = cur_res;
        }
    }
    mat[cur_i][cur_j] = og_dir;
    return res;
}

int examB_q4(char mat[N][N]) {
    return find_sol_rec(mat, 0, 0, mat[0][0]);
}