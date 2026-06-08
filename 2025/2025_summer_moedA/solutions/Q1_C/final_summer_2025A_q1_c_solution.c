#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

#define N 10
bool read_arrays(char*** ids, double** grades, int* n);
void free_arrays(char** ids, double* grades, int n);

int main(void) {
    // printIDontKnow();

    int n;
    char** ids;
    double* grades;
    if (!read_arrays(&ids, &grades, &n)) return 1;
    for (int i = 0; i < n; i++) printf("%s %.2f\n", ids[i], grades[i]);
    free_arrays(ids, grades, n);
    return 0;
}

bool read_arrays(char*** ids, double** grades, int* n){
    if (!ids || !grades || !n) return false;
    if (scanf("%d", n) != 1) return NULL;
    *ids = malloc(*n * sizeof(char*));
    if (!*ids) return false; //corrected !ids => !*ids , return NULL => false
    for (int i = 0; i < *n; i++) (*ids)[i] = NULL;
    *grades = malloc(*n * sizeof(double)); //corrected sizeof(int) => sizeof(double)
    if (!(*grades)) {
        free_arrays((*ids), (*grades), *n);
        return false;
    }
    for (int i = 0; i < *n; i++) {
        char * id = malloc(N*sizeof(char)); //changed from id[N] (block memory) to dynamic allocation
        if (!id) //added malloc success check
        {
            free_arrays((*ids), (*grades), *n);
            return false;
        }
        (*ids)[i] = id;
        if (scanf("%9s%lf", (*ids)[i], *grades + i) != 2) //made %s => %9s to prevent overflow
        {
            free_arrays((*ids), (*grades), *n);
            return false;
        }
    }
    return true;
}

void free_arrays(char** ids, double* grades, int n) {
    //function not changed: all correct
    if (ids) {
        for (int i = 0; i < n; i++) {
            if (ids[i]) free(ids[i]);
        }
        free(ids);
    }
    if (grades) free(grades);
}
