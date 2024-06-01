#ifndef __LINKED_STACK__H__
#define __LINKED_STACK__H__
typedef int elem;
typedef struct StackNode
{
    elem data;
    struct StackNode* link;
}SNode;
typedef struct linkedStack
{
    SNode* head;
}Stack;
Stack* createStack();
void SPush(Stack* S, elem e);
elem SPop(Stack* S);
bool IsStackEmpty(Stack* S);
elem SPeek(Stack* S);
void printStack(Stack* S);

#endif