#include <stdio.h>
#include <stdlib.h>
typedef char element;
typedef struct LinkedDequeNode
{
    element data;
    struct LinkedDequeNode* llink, *rlink;
}DQNode;
typedef struct LinkedDeque
{
    DQNode* front, *rear;
}Deque;

Deque* createLinkedDeque(void) 
{
    LinkedDeque* LDQ = (LinkedDeque*)malloc(sizeof(LinkedDeque));
    if(LDQ!=NULL){LDQ->front = NULL; LDQ->rear=NULL; return LDQ;}
}
void insertFront(LinkedDeque* LDQ, element item)
{
    if (LDQ!=NULL)
    {
        LinkedDequeNode* newNode = (LinkedDequeNode*)malloc(sizeof(LinkedDequeNode));
        newNode->data = item;
        newNode->llink = NULL;
        if (LDQ->front == NULL && LDQ->rear==NULL) //empty deque
        {
            LDQ->front = newNode;
            LDQ->rear = newNode;
            newNode->rlink = NULL;
        }
        else //not empty deque
        {
            newNode->rlink = LDQ->front;
            LDQ->front->llink = newNode;
            LDQ->front = newNode;
        }
    }
    
}
void insertRear(LinkedDeque* LDQ, element item)
{
    LinkedDequeNode* newNode = (LinkedDequeNode*)malloc(sizeof(LinkedDequeNode));
        newNode->data = item;
        newNode->rlink = NULL;
        if (LDQ->front==NULL && LDQ->rear==NULL) //empty deque
        {
            LDQ->front = newNode;
            LDQ->rear = newNode;
            newNode->llink = NULL;
        }
        else //not empty deque
        {
            newNode->llink = LDQ->rear;    
            LDQ->rear->rlink = newNode;
            LDQ->rear = newNode;
        }
}
element deleteFront(LinkedDeque* LDQ)
{
    if(LDQ != NULL)
    {
        element temp = '\0';
        if(LDQ->front!=NULL)
        {
            LinkedDequeNode* pNode = LDQ->front->rlink;
            pNode->llink = NULL;
            temp = LDQ->front->data;
            free(LDQ->front);
            LDQ->front = pNode;
            if(LDQ->front == NULL) // empty deque
            {
                LDQ->rear = NULL;
            }
        }
        else
        {
            printf("항이 존재하지 않음\n");
        }
        temp = '\0';
        return temp;
    }
}
element deleteRear(LinkedDeque* LDQ)
{
    if(LDQ != NULL)
    {
        element temp = '\0';
        if(LDQ->rear!=NULL)
        {
            LinkedDequeNode* pNode = LDQ->rear->llink;
            pNode->rlink = NULL;
            temp = LDQ->rear->data;
            free(LDQ->rear);
            LDQ->rear = pNode;
            if(LDQ->rear == NULL) // empty deque
            {
                LDQ->front = NULL;
            }
        }
        else
        {
            printf("항이 존재하지 않음\n");
        }
        temp = '\0';
        return temp;
    }
}

void printDeque(LinkedDeque* LDQ)
{
    LinkedDequeNode* pNode = LDQ->front;
    while (pNode != NULL)
    {
        printf("%c ", pNode->data);
        pNode = pNode->rlink;
    }
    printf("\n");
}

int main(void)
{
    Deque* LDQ = createLinkedDeque();
    element data;
    insertFront(LDQ, 'A');  printDeque(LDQ);
    insertFront(LDQ, 'B');  printDeque(LDQ);
    insertRear(LDQ, 'C');  printDeque(LDQ);
    data = deleteFront(LDQ);    printDeque(LDQ);
    data = deleteRear(LDQ);    printDeque(LDQ);
    insertRear(LDQ, 'D');  printDeque(LDQ);
    insertFront(LDQ, 'E');  printDeque(LDQ);
    insertFront(LDQ, 'F');  printDeque(LDQ);
    return 0;
}

