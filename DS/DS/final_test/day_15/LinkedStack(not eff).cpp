#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int eType;
typedef struct LinkedNode{ //노드 구조체
    eType item;
    struct LinkedNode* link;
}LinkedNode;
typedef struct LinkedStack //LinkedStack 구조체
{
    LinkedNode* top;
}LinkedStack;
LinkedStack* createLinkedStack(){ //LinkedStack 생성
    LinkedStack* S = (LinkedStack*)malloc(sizeof(LinkedStack));
    if (S!=NULL)S->top = NULL;
    return S;
}
void push(LinkedStack* S, eType item){ //LinkedStack 항 추가
    if (S != NULL)
    {
        LinkedNode* newNode = (LinkedNode*)malloc(sizeof(LinkedNode));
        newNode->item = item;
        
        if (S->top == NULL) //항이 0개일 때
        {
            newNode->link = S->top;
            S->top = newNode;
        }
        else //항이 1개 이상일 때
        {
            LinkedNode* pNode = S->top;
            while(pNode->link != NULL)
            {
                pNode = pNode->link;
            }
            newNode->link = pNode->link;
            pNode->link = newNode;
        }
    }
}
eType pop(LinkedStack* S){ //LinkedStack LIFO
    if (S != NULL)
    {
        LinkedNode* curNode = S->top;
        LinkedNode* preNode = curNode;
        eType temp = -1;
        if (S->top != NULL) //항이 0개가 아닐 경우
        {
            while(curNode->link != NULL) //마지막 노드로 이동
            {
                preNode = curNode;
                curNode = curNode->link;
            }
            if(curNode == S->top) //항이 1개인 경우
            {
                temp = curNode->item;
                S->top = NULL;
            }
            else //항이 2개 이상인 경우
            {
                preNode->link = NULL;
                temp = curNode->item;
            }
            free(curNode);
        }
        return temp;
    }
}
void printLinkedStack(LinkedStack* S) //LinkedStack 출력
{
    if (S != NULL)
    {
        if (S->top == NULL) cout<<"Empty Stack"<<endl; //빈 상태의 경우
        else //항이 존재할 경우
        {
            LinkedNode* pNode = S->top; 
            while(pNode != NULL)
            {
                cout<< pNode->item << ' ';
                pNode = pNode->link;
            }
            cout<< endl;
        }
    }
}
int main()
{
    LinkedStack* S = createLinkedStack();
    eType item;
    push(S, 1);     printLinkedStack(S);
    push(S, 2);     printLinkedStack(S);
    push(S, 3);     printLinkedStack(S);
    push(S, 4);     printLinkedStack(S);
    push(S, 5);     printLinkedStack(S);
    push(S, 6);     printLinkedStack(S);
    item = pop(S);  printLinkedStack(S);
    item = pop(S);  printLinkedStack(S);
    item = pop(S);  printLinkedStack(S);
    item = pop(S);  printLinkedStack(S);
    item = pop(S);  printLinkedStack(S);
    item = pop(S);  printLinkedStack(S);

    return 0;
}