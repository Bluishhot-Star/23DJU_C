#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct MaxPriorityQueue
{
    int elem[MAX_ELEMENT];
    int size;
}MaxPQueue;

MaxPQueue* createMaxPQueue(void)
{
    MaxPQueue* P = (MaxPQueue*)malloc(sizeof(MaxPQueue));
    P->size = 0;
    return P;
}

void insertMaxPQueue(MaxPQueue* PQ, int val)
{
    if (PQ)
    {
        int i = 0;
        ++(PQ->size);
        i = PQ->size; // 밑부터 비교시작
        while ((i != 1) && (val > PQ->elem[i/2])){ // 첫번째 항이 아니고 부모노드값보다 item이 더 큰 경우
            if(PQ->elem[i / 2])
            PQ->elem[i] = PQ->elem[i / 2]; // 부모노드를 아래로 이동
            i /= 2;
        }
        PQ->elem[i] = val;
    }
}

int removeMaxPQueue(MaxPQueue* PQ)
{
    int temp, item, parent, child;
    item = PQ->elem[1];
    temp = PQ->elem[PQ->size--];
    parent = 1; child = 2;
    while (child <= PQ->size)
    {
        if ((child < PQ->size)&&(PQ->elem[child] < PQ->elem[child+1])) // 자식 노드 중 더 큰 값 (오른쪽 노드가 더 큰 경우)
        {
            child++; // 오른쪽 노드 선택
        }
        if(PQ->elem[child] <= temp) break; // 현재 노드보다 마지막 노드였던 값이 더 큰 경우 반복종료
        else{ // 현재 노드보다 마지막 노드였던 값이 더 작은 경우
            PQ->elem[parent] = PQ->elem[child];
            parent = child;
            child *= 2;
        }
    }
    PQ->elem[parent] = temp;
    return item;
}

int findMaxPQueue(MaxPQueue* PQ)
{
    return PQ->elem[1];
}

void displayMaxPQueue(MaxPQueue* PQ)
{
    int i;
    printf("MaxPQueue : ");
    if(PQ->size == 0)
    {
        printf("Empty MaxPQueue\n");
    }
    else{
        for ( i = 1; i <= PQ->size; i++)
        {
            printf("[%d] ", PQ->elem[i]);
        }
        printf("\n");
    }
}

int main(){
    MaxPQueue* PQ = createMaxPQueue();
    int item;
    insertMaxPQueue(PQ, 10);    insertMaxPQueue(PQ, 19);
    insertMaxPQueue(PQ, 17);    insertMaxPQueue(PQ, 20);
    insertMaxPQueue(PQ, 25);    insertMaxPQueue(PQ, 47);
    insertMaxPQueue(PQ, 10);    insertMaxPQueue(PQ, 11);
    displayMaxPQueue(PQ);
    item = findMaxPQueue(PQ);   printf("MaxP: [%d]\n", item);
    printf("\n------- Remove elem From PQueue -----\n");
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    printf("Remove : [%d]\n", removeMaxPQueue(PQ));    displayMaxPQueue(PQ);
    return 0;
}