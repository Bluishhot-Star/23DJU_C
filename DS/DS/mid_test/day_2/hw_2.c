#include <stdio.h>
#include <stdlib.h>
// #include <iostream>
#include <time.h>

typedef unsigned long ULONG;

ULONG Fibonacci_Repetition(int N) {
    int i;
    ULONG Result;
    ULONG* FibonacciTable;
    if (N == 0 || N == 1) {
        return N;
    }
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));
    FibonacciTable[0] = 0;
    FibonacciTable[1] = 1;
    for (i = 2; i <= N; i++)
    {
        FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
    }
    Result = FibonacciTable[N];
    free(FibonacciTable);
    return Result;
}

ULONG Fibonacci_Recursion(int N) {
    ULONG Result;
    ULONG* FibonacciTable;
    if (N == 0 || N == 1) {
        return N;
    }
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));
    FibonacciTable[0] = 0;
    FibonacciTable[1] = 1;
    if (N >= 2) {
        FibonacciTable[N] = Fibonacci_Recursion(N - 1) + Fibonacci_Recursion(N - 2);
    }
    Result = FibonacciTable[N];
    free(FibonacciTable);
    return Result;
}

int main() {
    int N = 3;
    ULONG Result;
    clock_t start, stop;
    double duration;
    printf("===============================\n");
    while (N <= 40)
    {
        start = clock();
        Result = Fibonacci_Repetition(N);
        stop = clock();
        duration = ((stop - start)) / (double)CLOCKS_PER_SEC;
        printf("Fibonacci_Repetition(%d) = %lu (time: %lf) \n", N, Result, duration);
        printf("\n");
        N = N + 5;
    }
    printf("===============================\n");
    N = 3;
    while (N <= 40)
    {
        start = clock();
        Result = Fibonacci_Recursion(N);
        stop = clock();
        duration = ((stop - start)) / (double)CLOCKS_PER_SEC;
        printf("Fibonacci_Recursion(%d) = %lu (time: %lf) \n", N, Result, duration);
        printf("\n");
        N = N + 5;
    }
    return 0;
}