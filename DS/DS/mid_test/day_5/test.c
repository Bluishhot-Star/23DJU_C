#include <stdio.h>

int f1(int n) {
    if (n<=0){
        return 0;
    }
    else if (n<=2){
        return n;
    }
    else{
        return f1(n-3) + f1(n-2) + f1(n-1);
    }
}

int re(int n){
    if (n<1) {return 2;}
    else {return (2*2*re(n-1)+1);}
}

int sumLoop(int score[], int n){
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += *(score+i);
    }
    return result;
}

int sumRecursive(int score[], int n){
    int result = 0;
    if (n == 0 && n == 1){
        return n;
    }
}

int main(){
    int score[] = {1,2,3,4,5,6,7,8,9,10};
    int a = sumLoop(score, 10);
    printf("반복 : %d\n", a);


    return 0;
}