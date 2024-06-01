#include <stdio.h>

// 함수
// Factorial

int Factorial(int num){
    int iValue = 1;
    for (int i = 0; i < num -1 ; i++)
    {
        iValue *= i + 2;
    }

    return iValue;
}
// 재귀함수(Recursion)
// 가독성, 구현의 용이
// stack overflow의 위험? 오류 잡아내면 됨!

int Factorial_Re(int num){
    if (num == 1){
        return 1;
    }
    return num * Factorial_Re(num-1);
}

// 피보나치 수열
// 1 1 2 3 5 8 ...
int Fibonacci(int num){
    if(1 == num || 2 == num){
        return 1;
    }
    int num1, num2 = 1;
    int temp = 0;
    for (int i = 0; i < num-2; i++)
    {
        temp = num1+num2;
        num1 = num2;
        num2 = temp;
    }
    return temp;
}

int Fibonacci_Re(int num){
    if(1 == num || 2 == num){
        return 1;
    }
    return Fibonacci_Re(num-1) + Fibonacci_Re(num-2);
}



int main() {
    int a = Fibonacci(10);
    int b = Fibonacci_Re(10);
    printf("%d\n", b);
}
