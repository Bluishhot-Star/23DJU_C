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
        return N;
    }
    count++; //if(false) count
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1));
    FibonacciTable[0] = 0;  count++;
    FibonacciTable[1] = 1;  count++;
    for (i = 2; i <= N; i++)
    {
        count++;    //반복문
        FibonacciTable[i] = FibonacciTable[i - 1] + FibonacciTable[i - 2];
        count++;    //연산
    }
    Result = FibonacciTable[N]; count++; //alloc count
    free(FibonacciTable);
    count++; //return count
    return Result;
}

ULONG Fibonacci_Recursion(int N) {
    static int count = 0;
    ULONG Result;   count++;
    ULONG* FibonacciTable;  count++;
    if (N == 0 || N == 1) {
        count++;    //if(true) count
        count++;    //return count
        return N;
    }
    count++;    //if(false) count
    FibonacciTable = (ULONG*)malloc(sizeof(ULONG) * (N + 1)); count++;
    FibonacciTable[0] = 0;  count++;
    FibonacciTable[1] = 1;  count++;
    if (N >= 2) {
        count++;    //if(true) count
        FibonacciTable[N] = Fibonacci_Recursion(N - 1) + Fibonacci_Recursion(N - 2);
        count++;    //연산 count;
    }
    count++;    //if(false) count
    Result = FibonacciTable[N]; //alloc count
    free(FibonacciTable);
    count++;    //return count
    return Result;
}


int main() {
    int N = 3;
    ULONG sum;
    printf("===============================\n");
    while (N <= 40)
    {
        sum = Fibonacci_Repetition(N);
        printf("sum: %lu\n",sum);
        N = N + 5;
    }
    printf("===============================\n");
    N = 3;
    while (N <= 40)
    {
        sum = Fibonacci_Recursion(N);
        printf("sum: %lu\n",sum);
        N = N + 5;
    }
    return 0;
}
