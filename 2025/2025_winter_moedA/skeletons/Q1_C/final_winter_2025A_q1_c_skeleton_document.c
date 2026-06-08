#include <stdio.h>
#include <stdlib.h>

#define DONT_KNOW "I_dont_know"
void printIDontKnow() {
    printf("%s", DONT_KNOW);
    exit(0);
}

long long CountDivisors(long long n);
void Divisors(long long n, long long* arr, long long size);

int main(){
    // uncomment next line if you don't know the answer
    // printIDontKnow();

    long long n;
    printf("Enter number:\n");
    scanf("%lld", &n);
    long long size = CountDivisors(n);
    long long* arr = (long long*) malloc(sizeof(long long)*size);
    Divisors(n,arr,size);
    printf("Here are the divisors of %lld:\n", n);
    for (long long i = 0; i < size; i++) {
        printf("%lld ", arr[i]);
    }
    free(arr);
    return 0;
}

long long CountDivisors(long long n){
    long long count = 0;
    int i = 1;
    while(i*i < n){
        if(n % i == 0){
            count += 2;
            i++;
        }
    }
    return count;
}

void Divisors(long long n, long long* arr, long long size){
    int i = 1;
    int j = 0;
    int k = size;
    while(i*i < n){
        if(n % i == 0){
            arr[j++] = i;
            arr[k--] = n/i;
        }
        i++;
    }
}