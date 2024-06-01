#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedStackNode
{
    int data;
    struct LinkedStackNode* link;
} StackNode;

typedef struct LinkedStack
{
    StackNode* top;
} Stack;

Stack* createStackInstance(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top = NULL;
    return S;
}

void push(Stack* S, int data){
    StackNode* N = (StackNode*)malloc(sizeof(StackNode));
    N->data = data;
    if(S->top == NULL){
        S->top = N;
        return;
    }
    N->link = S->top;
    S->top = N;
}

int pop(Stack* S){
    if(S->top == NULL){ printf("스택 원소 없음"); return -1;}
    int result = S->top->data;
    StackNode* temp = S->top->link;
    free(S->top);
    S->top = temp;
    return result;
}

void printStack(Stack* S){
    StackNode* temp = S->top;
    printf("Stack :");
    while (temp)
    {
        printf("%3d",temp->data);
        temp = temp->link;
    }
    printf("\n");
}
typedef struct LinkedQueueNode
{
    int data;
    struct LinkedQueueNode* llink;
    struct LinkedQueueNode* rlink;
} QueueNode;

typedef struct LinkedQueue
{
    LinkedQueueNode* front;
    LinkedQueueNode* rear;
} Queue;

Queue* createQueueInstance(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

void enQueue(Queue* Q, int data){
    QueueNode* N = (QueueNode*)malloc(sizeof(QueueNode));
    N->data = data;
    if(Q->front == NULL){
        Q->front = N;
        Q->rear = N;
        return;
    }
    Q->rear->rlink = N;
    N->llink = Q->rear;
    Q->rear = N;
}

int deQueue(Queue* Q){
    if(Q->front == NULL && Q->rear == NULL){printf("큐 원소 없음\n"); return -1;}
    int result = Q->front->data;
    if(Q->front == Q->rear){free(Q->front); return result;}
    Q->front = Q->front->rlink;
    free(Q->front->llink);
    Q->front->llink = NULL;
    return result;
}

void printQueue(Queue* Q){
    QueueNode* temp = Q->front;
    printf("Queue :");
    while (temp)
    {
        printf("%3d",temp->data);
        temp = temp->rlink;
    }
    printf("\n");
    
}

int main(){
    Stack* S = createStackInstance();
    push(S, 1); printStack(S);
    push(S, 0); printStack(S);
    push(S, 2); printStack(S);
    push(S, 3); printStack(S);
    pop(S); printStack(S); pop(S); printStack(S);

    Queue* Q = createQueueInstance();
    enQueue(Q, 1); printQueue(Q);
    enQueue(Q, 0); printQueue(Q);
    enQueue(Q, 2); printQueue(Q);
    enQueue(Q, 3); printQueue(Q);
    deQueue(Q); printQueue(Q); deQueue(Q); printQueue(Q);

    return 0;
}