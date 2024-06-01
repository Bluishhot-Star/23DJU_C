#ifndef __GOOD_HEAP_H__
#define __GOOD_HEAP_H__
#define Heap_LEN 100

typedef char Hdata;
typedef int PriorityComp(Hdata d1, Hdata d2);
typedef struct _heap
{
    PriorityComp * comp;
    int numOfData;
    Hdata heapArr[Heap_LEN];
} Heap;

Heap* createHeap(PriorityComp pc);
bool HisEmpty(Heap* H);

int GetLChildIDX(int idx);
int GetRChildIDX(int idx);
int GetParentIDX(int idx);
int GetHighPriorChildIDX(Heap* H, int idx);

void HInsert(Heap* H, Hdata data);
Hdata HDelete(Heap* H);
#endif