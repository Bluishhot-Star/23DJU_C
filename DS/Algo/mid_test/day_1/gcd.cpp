#include <stdio.h>

void swap(int* x, int* y){
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
int gcd(int x, int y){
    if (x<y)
    {
        swap(&x, &y);
    }
    if(y ==0)
    {
        return x;
    }
    return gcd(y, (x%y)); //재귀호출, modula 전달하여 y=0 이되면 return
}
int main(){
    int a = 15, b = 24;
    printf("gcd(%d, %d) = %d\n",a,b,gcd(a,b));
    return 0;
}