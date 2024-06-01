#include <stdio.h>
#include <stdlib.h>
#include "PriorQ.h"

Heap* createHeap(PriorityComp pc)
{
    Heap* H = (Heap*)malloc(sizeof(Heap));
    H->numOfData = 0;
    H->comp = pc;
    return H;
}
path* createPath(char start, char end, int weight)
{
    path* P = (path*)malloc(sizeof(path));
    P->start = start;
    P->end = end;
    P->weight = weight;
    return P;
}
bool HisEmpty(Heap* H)
{
    if(H->numOfData != 0) return false;
    return true;
}

int GetLChildIDX(int idx) {return idx*2;}
int GetRChildIDX(int idx) {return idx*2 + 1;}
int GetParentIDX(int idx) {return idx/2;}

int GetHighPriorChildIDX(Heap* H, int idx)
{
    if (GetLChildIDX(idx) > H->numOfData) // 현재 노드가 단말 노드일 경우 
        return 0; //-> 자식 노드의 인덱스가 저장 데이터 인덱스의 범위를 벗어남
    else if(GetLChildIDX(idx) == H->numOfData) // 왼쪽 자식만 존재할 경우
        return GetLChildIDX(idx); //완전 이진트리이므로 하나만 있는 경우는 왼쪽자식 뿐이다!
    else
    {
        // 왼쪽 오른쪽 우선순위 비교 후 더 높은 것 반환 (최소 힙)
        if (H->comp(H->heapArr[GetLChildIDX(idx)]->weight, H->heapArr[GetRChildIDX(idx)]->weight) < 0)
            return GetRChildIDX(idx);
        else return GetLChildIDX(idx);
    }
}

void HInsert(Heap* H, path* data)
{
    int idx = ++(H->numOfData);
    while (idx != 1)
    {
        if ( H->comp(data->weight, (H->heapArr[GetParentIDX(idx)])->weight) > 0) // data의 우선순위가 높다면
        {
            H->heapArr[idx] = H->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else break;
    }
    H->heapArr[idx] = data;
}

path HDelete(Heap* H)
{
    path temp = *(H->heapArr[1]);
    path* lastElem = H->heapArr[H->numOfData];

    int parentIdx = 1; // 위로 옮겼던 마지막 노드를 저장할 인덱스, 가장 위부터 시작
    int childIdx; //그것의 자식 노드 (비교 대상)

    while (childIdx = GetHighPriorChildIDX(H, parentIdx)) //우선순위 높은 값 가져오기 (종료 조건 1. 단말 노드)
    {
        if (H->comp(lastElem->weight, H->heapArr[childIdx]->weight) >= 0) //반복 종료 조건 2. 자식의 우선순위가 더 높음 (최소 힙)
            break;
        H->heapArr[parentIdx] = H->heapArr[childIdx]; //아래로 이동
        parentIdx = childIdx;
    }
    H->heapArr[parentIdx] = lastElem;
    H->numOfData--;
    // delete(H->heapArr[1]);
    return temp;
}

