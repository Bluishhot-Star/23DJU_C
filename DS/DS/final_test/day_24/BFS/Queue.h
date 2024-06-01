#ifndef __QUEUE__H__
#define __QUEUE__H__

typedef int element;
typedef struct  LinkedQueueNode
{
    element data;
    struct LinkedQueueNode* link;
}Node;

typedef struct LinekedQueue
{
    Node* front, * rear;
}Queue;

Queue* createQueue(void);
void enQueue(Queue* LQ, element item);
element deQueue(Queue* LQ);
#endif