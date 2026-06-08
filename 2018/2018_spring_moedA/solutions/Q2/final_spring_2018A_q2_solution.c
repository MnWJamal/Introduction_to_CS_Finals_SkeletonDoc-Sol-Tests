#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

bool is_high_factor_in_range(int n, int low, int high);
void find_factors(int n, int *p, int *q);

bool is_high_factor_in_range(int n, int low, int high) {
    if (low > high) return false;

    int high_factor = -1;
    for (int i = 2; (long long)i * i <= n; ++i) {
        if (n % i == 0) {
            int other = n / i;
            high_factor = (other > i) ? other : i;
            break;
        }
    }

    if (high_factor == -1) return false;
    return low <= high_factor && high_factor <= high;
}

bool judge_is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; (long long)i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

bool judge_valid_answer(int n, int p, int q) {
    return judge_is_prime(p) && judge_is_prime(q) && (long long)p * q == n;
}

//Uncomment the first line in main if you don't know the answer.
//Otherwise, do not change main!!!
int main() {
    // printIDontKnow();

    int n;
    if (scanf("%d", &n) != 1) return 1;

    int p = -1, q = -1;
    find_factors(n, &p, &q);

    printf("%d", judge_valid_answer(n, p, q));
    return 0;
}

void find_factors(int n, int *p, int *q)
{
    int left = 0, right = n;
    int high = 0;
    while (right >= left) {
        int middle = (right+left) / 2;
        if (n%middle == 0 && (n/middle) <= middle)
        {
            high = middle;
            break;
        }
        if (is_high_factor_in_range(n,middle,right)) {
            left = middle+1;
        }
        else {
            right = middle - 1;
        }
    }
    if (high == 0) return; //error
    *q = high;
    *p = n/high;
}
