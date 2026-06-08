#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define N 3

int exam_q4(int routes[N][N]);

int main(void) {
    // printIDontKnow();

    int routes[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &routes[i][j]) != 1) return 1;
        }
    }
    printf("%d", exam_q4(routes));
    return 0;
}

bool VisitedAll(bool visited[N]) {
    for (int i = 0 ; i < N ; i++) {
        if (!visited[i]) return false;
    }
    return true;
}
#define NO_PATH (-1) //NOTE: NUMBER MUST NOT BE >= 0
#define NO_PATH_RETURNED_VALUE 0 //any number you like
int exam_q4_aux(int routes[N][N], bool visited[N], int location) {
    if (VisitedAll(visited)) return 0;
    int min_price = NO_PATH;
    bool found_price = false;
    for (int i = 0 ; i < N ; i++) {
        if (!visited[i] && routes[location][i] != 0) {
            visited[i] = true;
            int price = exam_q4_aux(routes,visited,i);
            if (price != NO_PATH) {
                price += routes[location][i];
                if (!found_price) {
                    found_price = true;
                    min_price = price;
                }
                else {
                    min_price = (price < min_price)? price : min_price;
                }
            }
            //backtrack
            visited[i] = false;
        }
    }
    return min_price; //min or NO_PATH if DNE
}
int exam_q4(int routes[N][N]) {
    bool visited[N];
    for (int i =  0 ; i < N ; i++) visited[i] = false;
    int min_price = NO_PATH;
    bool found_price = false;
    for (int location = 0 ; location < N ; location++) {
        visited[location] = true;
        int price = exam_q4_aux(routes,visited,location);
        if (price != NO_PATH) {
            if (!found_price) {
                found_price = true;
                min_price = price;
            }
            else {
                min_price = (price < min_price)? price : min_price;
            }
        }
        //backtrack
        visited[location] = false;
    }
    if (!found_price) return NO_PATH_RETURNED_VALUE;
    return min_price;
}
