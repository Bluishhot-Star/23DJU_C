#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__
#define Heap_LEN 100

typedef char Hdata;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr;
    Hdata data;
} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[Heap_LEN];
} Heap;

Heap* createHeap();
bool HisEmpty(Heap* H);

int GetLChildIDX(int idx);
int GetRChildIDX(int idx);
int GetParentIDX(int idx);
int GetHighPriorChildIDX(Heap* H, int idx);

void HInsert(Heap* H, Hdata data, Priority pr);
Hdata HDelete(Heap* H);
#endif