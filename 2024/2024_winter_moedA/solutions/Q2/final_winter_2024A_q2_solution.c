#include <stdio.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"
#define MAX_STR_LEN 30

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q2(char** a, int n, int k, char* output);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 1;

    char** a = (char**)malloc(n * sizeof(char*));
    if (!a) return 1;

    for (int i = 0; i < n; i++) {
        a[i] = (char*)malloc((MAX_STR_LEN + 1) * sizeof(char));
        if (!a[i]) {
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            return 1;
        }
        if (scanf("%30s", a[i]) != 1) {
            for (int j = 0; j <= i; j++) free(a[j]);
            free(a);
            return 1;
        }
    }

    char* output = (char*)malloc((MAX_STR_LEN * n + 1) * sizeof(char));
    if (!output) {
        for (int i = 0; i < n; i++) free(a[i]);
        free(a);
        return 1;
    }

    exam_q2(a, n, k, output);
    printf("%s", output);

    free(output);
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    return 0;
}
int my_strlen(char * s) {
    int i = 0;
    while (s[i]) i++;
    return i;
}
int compare_prefix(char * a, char * prefix, int k) {
    int i = 0;
    while (a[i] && i < k) {
        if (a[i] > prefix[i]) return 1;
        if (a[i] < prefix[i]) return -1;

        i++;
    }
    //prefix done return 0:
    if (i == k) return 0; //matches prefix
    return -1; //a isn't enough, so smaller (for binsearch to do: m = l + 1)
}

int BinarySearch(char ** a, int * used, int n, char * prefix, int k){
    int left = 0, right = n - 1;
    while (right >= left) {
        int middle = (right + left)/2;
        int comp = compare_prefix(a[middle], prefix,k);
        if (comp == 0 && !used[middle]) return middle;
        if (comp >= 0) {
            right = middle - 1;
        }
        else left = middle + 1;
    }
    return -1;
}
void exam_q2(char** a, int n, int k, char* output) {
    if (n <= 0 || k <= 0) return;
    int output_ends = 0;
    int last_string = 0;
    int * used = malloc(n*sizeof(int));
    if (!used) return;
    for (int i = 1 ; i < n ; i++) used[i] = 0;
    used[0] = 1; //not necessary
    int curr_length = my_strlen(a[0]);
    for (int i = 0 ; i < curr_length ; i++) output[i] = a[0][i];
    output_ends = curr_length;
    output[output_ends] = '\0';
    while (1) {
        if (curr_length < k) break;
        char * suffix = a[last_string] + curr_length - k;
        int matches = BinarySearch(a+1,used+1,n-1,suffix,k);
        //Binary search (compares logn times with complexity of compare: k)
        //so: O(k*logn)
        //NOTE: this while iterates maximum n times (because of used array)
        if (matches != -1) {
            //found a string with prefix = suffix?
            //use it, and copy it;
            used[1 + matches] = 1;
            char * copy = a[1 + matches];
            curr_length = my_strlen(copy);
            last_string = 1 + matches;
            for (int i = k ; i < curr_length ; i++) {
                output[output_ends] = copy[i];
                output_ends++;
            }
            output[output_ends] = '\0';
        }
        else {
            break;
        }
    }

    free(used);
}
