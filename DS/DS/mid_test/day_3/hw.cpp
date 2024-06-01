#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long ULONG;

ULONG Fibonacci_Repetition(int N) {
    int count = 0; //Noncounting
    int i;  count++;
    ULONG Result;   count++;
    ULONG* FibonacciTable; count++;
    if (N == 0 || N == 1) {
        count++;    //if(ture) count
        count++;    //return N;
        return count;
    }
    count++; //if(false) count
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1)); count++;
    FibonacciTable[0] = 0;  count++;
    FibonacciTable[1] = 1;  count++;
    for (i = 2; i <= N; i++)
    {
        count++;    //반복문
        FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
        count++;    //연산
    }
    Result = FibonacciTable[N]; count++; //alloc count
    free(FibonacciTable); count++;
    count++; //return count
    return count;
}

ULONG Fibonacci_Recursion(int N) {
    static int count = 0; //Noncounting
    ULONG Result;   count++;
    ULONG* FibonacciTable;  count++;
    if (N == 0 || N == 1) {
        count++;    //if(true) count
        count++;    //return count
        return count;
    }
    count++;    //if(false) count
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1)); count++;
    FibonacciTable[0] = 0;  count++;
    FibonacciTable[1] = 1;  count++;
    if (N >= 2) {
        count++;    //if(true) count
        FibonacciTable[N] = Fibonacci_Recursion(N - 1) + Fibonacci_Recursion(N - 2);
        count++;    //호출 count;
        count++;    //호출 count;
        count++;    //alloc count;
    }
    count++;    //if(false) count
    Result = FibonacciTable[N]; count++;//alloc count
    free(FibonacciTable); count++;
    count++;    //return count
    return count;
}


int main() {
    int N = 0;
    ULONG sum;
    printf("===============================\n");
    while (N <= 10)
    {
        sum = Fibonacci_Repetition(N);
        printf("F(%d) : sum: %lu\n",N, sum);
        N = N + 1;
    }
    printf("===============================\n");
    N = 0;
    while (N <= 40)
    {
        sum = Fibonacci_Recursion(N);
        printf("F(%d) : sum: %lu\n",N, sum);
        N = N + 1;
    }
    return 0;
}