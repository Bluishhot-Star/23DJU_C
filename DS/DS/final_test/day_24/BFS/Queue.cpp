#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue* createQueue(void){
    Queue* LQ = (Queue*)malloc(sizeof(Queue));
    if (LQ != NULL) {LQ->front = NULL; LQ->rear = NULL;}
    return LQ;
}
void enQueue(Queue* LQ, element item){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) { newNode->data = item, newNode->link = NULL;}
    if (LQ->front == NULL) { LQ->front = newNode; LQ->rear = newNode;}
    else
    {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}
element deQueue(Queue* LQ)
{
    Node* tmp = LQ->front;
    element item;
    if (LQ->front == NULL) return NULL;
    else {
        item = tmp->data;
        LQ->front = LQ->front->link;
        if (LQ->front == NULL) LQ->rear = NULL;
        free(tmp);
        return item;
    }
}