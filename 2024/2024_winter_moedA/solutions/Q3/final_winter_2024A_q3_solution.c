#include <stdio.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"

void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

void exam_q3(int* arr, int n, int a, int b, int c);

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int* arr = NULL;
    if (n > 0) {
        arr = (int*)malloc(n * sizeof(int));
        if (!arr) return 1;
        for (int i = 0; i < n; i++) {
            if (scanf("%d", arr + i) != 1) {
                free(arr);
                return 1;
            }
        }
    }

    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        free(arr);
        return 1;
    }

    exam_q3(arr, n, a, b, c);

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
    }

    free(arr);
    return 0;
}

void exam_q3(int* arr, int n, int a, int b, int c) {
    if (!arr || n <= 0) return; //validate inputs
    //cases: (linear increase, linear decrease, parabola happy, parabola sad)
    int * transformation = malloc(n*sizeof(int));
    if (!transformation) return;
    for (int i = 0 ; i < n ; i++) {
        transformation[i] = a*arr[i]*arr[i] + b*arr[i] + c;
    }
    if (a == 0) {
        //linear case (a==0):
        if (b >= 0) {
            //constant / increasing line, copy as is:
            for (int i = 0 ; i < n ; i++) arr[i] = transformation[i];
        }
        else {
            //decreasing line:
            for (int i = n - 1 ; i >= 0 ; i--) arr[n - 1 - i] = transformation[i];
        }
    }
    else {
        //parabola:
        double equilibrium = (double)(-1 * b) / (double)(2*a);
        //now we find equilibrium in arr (maybe out of bond)
        int mid = 0;
        while (arr[mid] < equilibrium && mid < n) {
            mid++;
        }
        //mid is first point larger than equilibrium (not equal)
        int from_left = 0, from_right = 0;
        if (a > 0) {
            //happy parabola:
            for (int i = 0 ; i < n ; i++) {
                if (mid - 1 - from_left >= 0 && mid + from_right < n) {
                    if (transformation[mid - 1 - from_left] < transformation[mid + from_right]) {
                        arr[i] = transformation[mid - 1 - from_left];
                        from_left++;
                    }
                    else {
                        arr[i] = transformation[mid + from_right];
                        from_right++;
                    }
                }
                else if (mid + from_right < n) {
                    arr[i] = transformation[mid + from_right];
                    from_right++;
                }
                else {
                    arr[i] = transformation[mid - 1 - from_left];
                    from_left++;
                }
            }
        }
        else {
            //sad parabola
            for (int i = n-1 ; i >= 0 ; i--) {
                if (mid - 1 - from_left >= 0 && mid + from_right < n) {
                    if (transformation[mid - 1 - from_left] > transformation[mid + from_right]) {
                        arr[i] = transformation[mid - 1 - from_left];
                        from_left++;
                    }
                    else {
                        arr[i] = transformation[mid + from_right];
                        from_right++;
                    }
                }
                else if (mid + from_right < n) {
                    arr[i] = transformation[mid + from_right];
                    from_right++;
                }
                else {
                    arr[i] = transformation[mid - 1 - from_left];
                    from_left++;
                }
            }
        }
    }
    free(transformation);
}
