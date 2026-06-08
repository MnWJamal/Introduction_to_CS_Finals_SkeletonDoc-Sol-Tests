#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow()
{
    printf("%s", DONT_KNOW);
    exit(0);
}

int q4(int array[], int n, int target);

// Do not change read_arr!!!
int *read_arr(int *n)
{
    if (scanf("%d", n) != 1)
        return NULL;
    int *array = malloc((*n) * sizeof(int));
    if (!array)
        return NULL;
    for (int i = 0; i < *n; i++)
    {
        if (scanf("%d", array + i) != 1)
        {
            free(array);
            return NULL;
        }
    }
    return array;
}

// Uncomment the first line in main if you don't know the answer.
// Otherwise, do not change main!!!
int main()
{
    // printIDontKnow();
    int n;
    int *array = read_arr(&n);
    if (!array)
        return 1;
    int target;
    if (scanf("%d", &target) != 1)
    {
        free(array);
        return 1;
    }
    printf("%d", q4(array, n, target));
    free(array);
    return 0;
}

#define ERROR -20
#define NO_GROUP -1
int usedAtLeastOnce(int **used, int n)
{
    for (int i = 0; i < n; ++i)
        if (used[i][0] == NO_GROUP &&
            used[i][2] == NO_GROUP)
            return 0;
    return 1;
}
int aux(int array[], int n, int target, int cur_sum, int **used, int cur_group)
{
    if (cur_sum > target)
        return ERROR;
    if (cur_sum == target && usedAtLeastOnce(used, n))
        return 1 + cur_group;
    if (cur_sum == target)
        return aux(array, n, target, 0,
                   used, cur_group + 1);
    int min = 2 * n + 1;
    for (int i = 0; i < n; i++)
    {
        int index = -1;
        if (used[i][2] != cur_group && (used[i][0] ==
                                            NO_GROUP ||
                                        used[i][0] == cur_group))
            index = 0;
        else if (used[i][0] != cur_group && (used[i][2] ==
                                                 NO_GROUP ||
                                             used[i][2] == cur_group))
            index = 2;
        if (index != -1)
        {
            used[i][index] = cur_group;
            used[i][index + 1]++;

            int k = aux(array, n, target, cur_sum + array[i], used, cur_group);
            min = (k != ERROR && k < min) ? k : min;
            used[i][index + 1]--;
            if (used[i][index + 1] == 0)
                used[i][index] =
                    NO_GROUP;
        }
    }
    return min == 2 * n + 1 ? ERROR : min;
}
int q4(int array[], int n, int target)
{
    int **used = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i)
    {
        used[i] = (int *)malloc(sizeof(int) * 4);
        used[i][0] = NO_GROUP;
        used[i][1] = 0;
        used[i][2] = NO_GROUP;
        used[i][3] = 0;
    }
    int answer = aux(array, n, target, 0, used, 0);
    for (int i = 0; i < n; ++i)
        free(used[i]);
    free(used);
    return answer;
}
