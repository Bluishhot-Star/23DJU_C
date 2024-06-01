#include <stdio.h>
#include <stdlib.h>
#define Stack_Size 10
typedef char element;
typedef struct ArrayQueue
{
    int front, rear;
    element stack[Stack_Size];
}ArrayQueue;
ArrayQueue* createArrayQueue()
{
    ArrayQueue* S = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if(S) {S->front = 0, S->rear = 0;}
    return S;
}
bool isEmpty(ArrayQueue* AQ)
{
    if (AQ->front == AQ->rear) return true;
    return false;
}
void enque(ArrayQueue* AQ, element item)
{
    AQ->stack[AQ->rear % Stack_Size] = item;
}
element deque(ArrayQueue* AQ)
{
    if(isEmpty(AQ))
    {
        printf("Empty Queue");
    }
    else
    {
    AQ->front = AQ->front % Stack_Size;
    element temp = AQ->stack[AQ->front];
    AQ->stack[AQ->front] = '\0';
    }
}

void printArrayQueue(ArrayQueue* AQ)
{
    int idx = AQ->front + 1;
    while (idx == AQ->front)
    {
        printf("%c ",AQ->stack[idx++%Stack_Size]);
    }
    printf("\n");
}

int main()
{
    ArrayQueue* S = createArrayQueue();
    element item;
    enque(S, 'A');     printArrayQueue(S);
    enque(S, 'B');     printArrayQueue(S);
    enque(S, 'C');     printArrayQueue(S);
    enque(S, 'D');     printArrayQueue(S);
    enque(S, 'E');     printArrayQueue(S);
    enque(S, 'F');     printArrayQueue(S);
    item = deque(S);  printArrayQueue(S);
    item = deque(S);  printArrayQueue(S);
    item = deque(S);  printArrayQueue(S);
    item = deque(S);  printArrayQueue(S);
    item = deque(S);  printArrayQueue(S);
    item = deque(S);  printArrayQueue(S);
    return 0;
}