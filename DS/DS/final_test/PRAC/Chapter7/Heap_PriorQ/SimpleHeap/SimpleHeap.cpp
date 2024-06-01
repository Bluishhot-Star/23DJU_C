#include <stdio.h>
#include <stdlib.h>
#include "SimpleHeap.h"

Heap* createHeap()
{
    Heap* H = (Heap*)malloc(sizeof(Heap));
    H->numOfData = 0;
    return H;
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
        if (H->heapArr[GetLChildIDX(idx)].pr > H->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else return GetLChildIDX(idx);
    }
}

void HInsert(Heap* H, Hdata data, Priority pr)
{
    int idx = ++H->numOfData;
    HeapElem temp = {pr,data};
    while (idx != 1)
    {
        if (pr < (H->heapArr[GetParentIDX(idx)].pr))
        {
            H->heapArr[idx] = H->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else break;
    }
    H->heapArr[idx] = temp;
}

Hdata HDelete(Heap* H)
{
    Hdata temp = (H->heapArr[1]).data;
    HeapElem lastElem = H->heapArr[H->numOfData];

    int parentIdx = 1; // 위로 옮겼던 마지막 노드를 저장할 인덱스, 가장 위부터 시작
    int childIdx; //그것의 자식 노드 (비교 대상)

    while (childIdx = GetHighPriorChildIDX(H, parentIdx)) //우선순위 높은 값 가져오기 (종료 조건 1. 단말 노드)
    {
        if (lastElem.pr <= H->heapArr[childIdx].pr) //반복 종료 조건 2. 자식의 우선순위가 더 높음 (최소 힙)
            break;
        H->heapArr[parentIdx] = H->heapArr[childIdx]; //아래로 이동
        parentIdx = childIdx;
    }
    H->heapArr[parentIdx] = lastElem;
    H->numOfData--;
    return temp;
}

