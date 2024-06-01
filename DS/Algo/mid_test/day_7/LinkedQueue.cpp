#include <stdio.h>
#include <stdlib.h>
typedef char element;
typedef struct LinkedNode
{
    element data;
    struct LinkedNode *link;
} Node;
typedef struct LinkedQueue
{
    struct LinkedNode* front;
    struct LinkedNode* rear;
} Queue;
void enQueue(Queue *Q, element data){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->link = NULL;
    if (Q->front == NULL)
    {
        Q->front = n;
        Q->rear = n;
        return;
    }
    Q->rear->link = n;
    Q->rear = n;
}
element deQueue(Queue *Q){
    Node *p = Q->front;
    element pData = p->data;
    if (Q->front == NULL)
    {
        printf("empty\n");
        return (element)NULL;
    }
    Q->front = p->link;
    free(p);
    return pData;
}
void printQueue(Queue *Q){
    Node *p = Q->front;
    if (p == NULL)
    {
        printf("empty\n");
        return;
    }
    printf("Queue: [");
    while (p)
    {
        printf("%c ",p->data);
        p = p->link;
    }
    printf("]\n");
}

int main(){
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->front = NULL;    Q->rear = NULL;
    enQueue(Q, 'A');    enQueue(Q, 'B');    enQueue(Q, 'C');    enQueue(Q, 'D');
    printQueue(Q);
    printf("%c\n", deQueue(Q)); printQueue(Q);
    printf("%c\n", deQueue(Q)); printQueue(Q);
    printf("%c\n", deQueue(Q)); printQueue(Q);
    printf("%c\n", deQueue(Q)); printQueue(Q);
    getchar();
    return 0;
}