#include <stdio.h>
#include <iostream>
#define Stack_Size 5
typedef int eType;
typedef struct ArrayStack
{
    int top;
    eType stack[Stack_Size];
    
}ArrayStack;
ArrayStack* createArrayStack(){
    ArrayStack* S = (ArrayStack*)malloc(sizeof(ArrayStack));
    if (S != NULL) S->top= -1;
    return S;
}
void push(ArrayStack* S, eType item){
    if (S->top == Stack_Size - 1)
    {
        printf("Stack Full\n"); return;
    }
    S->stack[++(S->top)]=item;
}
eType pop(ArrayStack* S){
    if (S->top == -1)
    {
        printf("Stack empty\n"); return -1;
    }
    return S->stack[(S->top)--];
}
void printArrayStack(ArrayStack* S){
    if (S->top == -1) return;
    for (int i = 0; i < S->top+1; i++)
    {
        printf("%3d ", S->stack[i]);
    }
    printf("\n");
}

int main(){
    ArrayStack* S = createArrayStack();
    eType item;
    push(S, 1);     printArrayStack(S);
    push(S, 2);     printArrayStack(S);
    push(S, 3);     printArrayStack(S);
    push(S, 4);     printArrayStack(S);
    push(S, 5);     printArrayStack(S);
    push(S, 6);     printArrayStack(S);
    item = pop(S);  printArrayStack(S);
    item = pop(S);  printArrayStack(S);
    item = pop(S);  printArrayStack(S);
    item = pop(S);  printArrayStack(S);
    item = pop(S);  printArrayStack(S);
    item = pop(S);  printArrayStack(S);
    return 0;
}