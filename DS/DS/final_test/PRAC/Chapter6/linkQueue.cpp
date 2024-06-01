#include <stdio.h>
#include <stdlib.h>
typedef int elem;
typedef struct linkQueueNode
{
    elem data;
    struct linkQueueNode* link;
}node;

typedef struct linkQueue
{
    node* front;
    node* rear;
}LQueue;

LQueue* createLQueue()
{
    LQueue* LQ = (LQueue*)malloc(sizeof(LQueue));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

bool LQIsEmpty(LQueue* LQ)
{
    if(LQ->front == NULL)
        return true;
    return false;
}

void EnQueue(LQueue* LQ, elem data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->link = NULL;
    newNode->data = data;
    if(LQIsEmpty(LQ))
    {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else
    {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

elem DeQueue(LQueue* LQ)
{
    int temp = -1;
    if(!(LQIsEmpty(LQ)))
    {
        temp = LQ->front->data;
        node* delNode = LQ->front;
        LQ->front = LQ->front->link;
        free(delNode);
        if(LQIsEmpty(LQ))
            LQ->rear = NULL;
    }
    return temp;
}

void printQueue(LQueue* LQ)
{
    node* idx = LQ->front;
    while(idx != NULL)
    {
        printf("%3d |",idx->data);
        idx = idx->link;
    }
    printf("\n");
}

int main()
{
    LQueue* LQ = createLQueue();
    EnQueue(LQ, 1);
    EnQueue(LQ, 2);
    EnQueue(LQ, 3);
    EnQueue(LQ, 4);
    printf("\n==== Queue ====\n");
    printQueue(LQ);

    printf("\n==== Dequeue ====\n");
    while (!LQIsEmpty(LQ))
    {
        printf("%3d ",DeQueue(LQ));
    }
    printf("\n");
    return 0;
}