#include <stdio.h>
#include <stdlib.h>
#include "linkedStack.h"

Stack* createStack()
{
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->head = NULL;
    return S;
}
void SPush(Stack* S, elem* e)
{
    if(S){
        SNode* nNode = (SNode*)malloc(sizeof(SNode));
        nNode->data = e;
        if (S->head == NULL)
        {
            nNode->link = NULL;
            S->head = nNode;
        }
        else
        {
            nNode->link = S->head;
            S->head = nNode;
        }
    }
}

elem* SPop(Stack* S)
{
    elem* data =  NULL;
    if(S){
        if(!IsStackEmpty(S))
        {
            data = S->head->data;
            SNode* delNode = S->head;
            S->head = S->head->link;
            free(delNode);
        }
    }
    return data;
}
bool IsStackEmpty(Stack* S)
{
    if (S->head == NULL)
    {
        return true;
    }
    return false;
}

// void printStack(Stack* S)
// {
//     if(S){
//         SNode* temp = S->head;
//         while (temp != NULL)
//         {
//             printf("%c ", temp->data->data);
//             temp = temp->link;
//         }
//         printf("\n");
//     }
// }