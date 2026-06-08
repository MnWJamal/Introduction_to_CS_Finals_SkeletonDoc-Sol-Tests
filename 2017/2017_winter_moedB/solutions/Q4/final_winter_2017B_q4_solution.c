#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

int FindMinimumNumDressColors(int color_map[N][N]);

// Do not change read_color_map!!!
bool read_color_map(int color_map[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &color_map[i][j]) != 1) {
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

    int color_map[N][N];
    if (!read_color_map(color_map)) return 1;

    printf("%d", FindMinimumNumDressColors(color_map));

    return 0;
}
int FMNDC_aux(int color_map[N][N], int choices[N] ,int current_color, int pickers ,int remaining_pickers);
int FindMinimumNumDressColors(int color_map[N][N])
{
    int choices[N];
    for (int i = 0 ; i < N ; i++) {
        choices[i] = -1;
    }
    return FMNDC_aux(color_map,choices,0,0,N);
}

bool CanPickColor(int person, int color,int color_map[N][N], int choices[N]) {
    //diagnal coflict
    if (color_map[person][person] == -1) return false;
    //algorithm
    for (int i = 0 ; i < N ; i++) {
        //one of 2, either:
        //1) same color but must be diffrent => false:
        if (choices[i] == color && (color_map[i][person] == -1 || color_map[person][i] == -1)) return false;
        //2) diffrent color (that is also not -1) but must be same
        if (choices[i] != -1 && choices[i] != color
            && (color_map[i][person] == 1 || color_map[person][i] == 1)) return false;
    }
    return true;
}

int FMNDC_aux(int color_map[N][N], int choices[N] ,int current_color, int pickers ,int remaining_pickers)
{
    if (remaining_pickers == 0) return current_color+1;
    bool found_picks = false;
    int min_colors = N;
    //loop over people for color x:
    for (int i = 0; i < N ; i++) {
        if (choices[i] == -1)
        {
            if (CanPickColor(i,current_color,color_map,choices)) {
                choices[i] = current_color;
                int colors = FMNDC_aux(color_map,choices,current_color,pickers+1,remaining_pickers-1);
                if (colors != -1) {
                    found_picks = true;
                    min_colors = (colors < min_colors)? colors : min_colors;
                }
                //backtrack
                choices[i] = -1;
            }

        }
    }
    //maybe enoght people on color x (requires pickers > 0)
    if (pickers > 0) {
        int colors = FMNDC_aux(color_map,choices,current_color+1,0,remaining_pickers);
        if (colors != -1) {
            found_picks = true;
            min_colors = (colors < min_colors)? colors : min_colors;
        }
    }
    if (found_picks) return min_colors;
    return -1;
}
