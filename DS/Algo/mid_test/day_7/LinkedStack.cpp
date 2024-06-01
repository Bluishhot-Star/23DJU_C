#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
typedef struct LinkedNode
{
    element data;
    struct LinkedNode *link;
} Node;
typedef struct LinkedStack
{
    struct LinkedNode *top;
} Stack;
void push(Stack* S, element data){
    Node *p = S->top;
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->link = NULL;
    if (p == NULL)
    {
        S->top = n;
        return;
    }
    n->link = S->top;
    S->top = n;
}
element pop(Stack* S){
    Node* p = S->top;
    if(p == NULL){
        printf("empty Stack\n");
        return (element)NULL;
    }
    element pData = S->top->data;
    S->top = p->link;
    free(p);
    return pData;
}
void printStack(Stack *S){
    Node *p = S->top;
    if (p == NULL){
        printf("empty Stack\n");
        return;
    }
    printf("Stack : [ ");
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->link;
    }
    printf("]\n");
}

int main(){
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->top = NULL;
    push(S, 'A');
    push(S, 'B');
    push(S, 'C');
    push(S, 'D');
    printStack(S);

    printf("%c\n", pop(S)); printStack(S);
    printf("%c\n", pop(S)); printStack(S);
    printf("%c\n", pop(S)); printStack(S);
    printf("%c\n", pop(S));
    
    getchar();
    
    return 0;
}


