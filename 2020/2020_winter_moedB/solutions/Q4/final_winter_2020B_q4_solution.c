#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int shortest_path(int dist[N][N], bool red_ones[N], int k);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int dist[N][N];
    bool red_ones[N];
    int k;
    int value;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &dist[i][j]) != 1) return 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &value) != 1) return 1;
        red_ones[i] = (value != 0);
    }

    if (scanf("%d", &k) != 1) return 1;

    printf("%d", shortest_path(dist, red_ones, k));
    return 0;
}
bool VisitedAll(bool visited[N]) {
    for (int i = 0 ; i < N ;i++) {
        if (!visited[i]) return false;
    }
    return true;
}
int shortest_path_aux(int dist[N][N], bool red_ones[N],bool visited[N] , int reds_so_far, int curr, int k) {
    if (VisitedAll(visited)) return 0;
    int min_path = 0;
    bool found_path = false;

    for (int to = 0 ; to < N ; to++) {
        if (!visited[to] && dist[curr][to] != -1 &&
            reds_so_far + red_ones[to] <= k) {
            int give_red_so_far = (red_ones[to])? reds_so_far + 1 : 0;
            visited[to] = true;
            int path = shortest_path_aux(dist,red_ones,visited,give_red_so_far,to,k);
            if (path != -1) {
                path += dist[curr][to];
                if (!found_path) {
                    min_path = path;
                    found_path = true;
                }
                else {
                    min_path = (path < min_path)? path : min_path;
                }
            }
            //backtracking:
            visited[to] = false;
        }
    }
    if (!found_path) return -1;
    return min_path;
}

int shortest_path(int dist[N][N], bool red_ones[N], int k) {
    bool visited[N];
    for (int i = 0 ; i < N ; i++) visited[i] = false;
    int min_path = 0;
    bool found_path = false;
    for (int i = 0 ; i < N ; i++) {
        if (red_ones[i] <= k)
        {
            visited[i] = true;
            int start_path_from_i =
                shortest_path_aux(dist,red_ones,visited,red_ones[i],i,k);
            visited[i] = false;
            if (start_path_from_i != -1) {
                if (!found_path) {
                    min_path = start_path_from_i;
                    found_path = true;
                }
                else {
                    min_path = (start_path_from_i < min_path)?
                        start_path_from_i : min_path;
                }
            }
        }
    }
    if (!found_path) return -1;
    return min_path;
}
