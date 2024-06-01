#include <stdio.h>
#include "function.h"
#include "common.h"

static int st_var = 1;

int Add(int a, int b){
    printf("snum의 값은 %d\n",snum);
    printf("exnum의 값은 %d\n",exnum);

    return a + b;
}
int Sub(int a, int b){
    return a - b;
}
int Mul(int a, int b){
    return a*b;
}
int Div(int a, int b){
    return a/b;
}