#include <stdio.h>
#include <stdlib.h>
#define Max 5
typedef int elem;
typedef struct cirQueue
{
    int front;
    int rear;
    elem queArr[Max];
}CQueue;

CQueue* createCQueue()
{
    CQueue* CQ = (CQueue*)malloc(sizeof(CQueue));
    CQ->front = 0;
    CQ->rear = 0;
    return CQ;
}

bool QIsEmpty(CQueue* CQ)
{
    if(CQ)
    {
       if(CQ->front == CQ->rear) return true; //front와 rear이 같음 = EMPTY
       else return false;
    }
    else { printf("잘못된 큐\n"); return NULL;}
}

elem NextPosIdx(elem data) //Max로 나눈 나머지를 이용한 원형 큐 idx 유지
{
    return (data+1)%Max;
}

void Enqueue(CQueue* CQ, elem data)
{
    if (CQ->front == NextPosIdx(CQ->rear)) //rear의 다음 칸이 Front = FULL
    {
        printf("Queue is full\n");
        return;
    }
    CQ->rear = NextPosIdx(CQ->rear); //rear 한 칸 이동 후 삽입
    CQ->queArr[CQ->rear] = data;
}

elem Dequeue(CQueue* CQ)
{
    if(QIsEmpty(CQ)){printf("Queue is empty\n"); return -1;}
    CQ->front = NextPosIdx(CQ->front);
    return CQ->queArr[CQ->front];
}

void printCQueue(CQueue* CQ)
{
    int idx = NextPosIdx(CQ->front);
    printf("++++Queue++++\n");
    while (idx != NextPosIdx(CQ->rear))
    {
        printf("%3d |", CQ->queArr[idx]);
        idx = NextPosIdx(idx);
    }
    printf("\n");
}

int main(void)
{
    CQueue* CQ = createCQueue();
    Enqueue(CQ, 1);
    Enqueue(CQ, 2);
    Enqueue(CQ, 3);
    Enqueue(CQ, 4);
    Enqueue(CQ, 5);
    printCQueue(CQ);
    // Enqueue(CQ, 5);
    printf("\n++++Dequeue++++\n");
    while (!QIsEmpty(CQ))
    {
        printf("%3d |",Dequeue(CQ));
    }
    printf("\n");
    return 0;
}