#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3
#define M 10

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int assign_boats(int A[][N], int weights[]);

// Do not change read_input!!!
bool read_input(int A[][N], int weights[]) {
    for (int i = 0; i < N; i++) {
        if (scanf("%d", weights + i) != 1) {
            return false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                return false;
            }
        }
    }

    return true;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int A[N][N];
    int weights[N];

    if (!read_input(A, weights)) return 1;

    printf("%d", assign_boats(A, weights));

    return 0;
}

bool IsFriendsWithGroup(int A[][N], int animal, int to_boat, int boat[]) {
    for (int i = 0 ; i < N ; i++) {
        if (boat[i] != to_boat || i == animal) continue; //not relevant
        if (!A[i][animal]) return false;
    }
    return true;
}
int assign_boats_auxil( int A[][N], int weights[], int boat[], int current_boat, int current_weight, int animals_left)
{
    if (animals_left <= 0) {
        return current_boat+1;
    }
    int minboats = N;
    for (int i = 0; i < N ; i++) {
        //for each animal, try take on boat and try leaving:
        if (boat[i] == -1) {
            if (current_weight + weights[i] <= M && IsFriendsWithGroup(A,i,current_boat,boat)) {
                boat[i] = current_boat;
                current_weight += weights[i];
                int boats = assign_boats_auxil(A,weights,boat,current_boat,current_weight,animals_left-1);
                //backtrcking:
                boat[i] = -1;
                current_weight -= weights[i];
                minboats = (boats < minboats)? boats : minboats;
            }
        }
    }
    //or (only if weight is not 0) take no one and try open new boat
    if (current_weight != 0) {
        int boats = assign_boats_auxil(A,weights,boat,current_boat+1,0,animals_left);
        minboats = (boats < minboats)? boats : minboats;
    }

    return minboats;
}
int assign_boats(int A[][N], int weights[])
{
    int boat[N] = {0};
    for (int i = 0 ; i < N ; i++) boat[i] = -1;

    return assign_boats_auxil(A,weights,boat,0,0,N);
}

