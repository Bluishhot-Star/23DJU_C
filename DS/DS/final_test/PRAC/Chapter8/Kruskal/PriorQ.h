#ifndef __PRIORQ_H__
#define __PRIORQ_H__
#define Heap_LEN 100

typedef char Hdata;
typedef int PriorityComp(Hdata d1, Hdata d2);
typedef struct _path
{
    char start;
    char end;
    int weight;
}path;
typedef struct _heap
{
    PriorityComp * comp;
    int numOfData;
    path* heapArr[Heap_LEN];
} Heap;

Heap* createHeap(PriorityComp pc);
path* createPath(char start, char end, int weight);
bool HisEmpty(Heap* H);

int GetLChildIDX(int idx);
int GetRChildIDX(int idx);
int GetParentIDX(int idx);
int GetHighPriorChildIDX(Heap* H, int idx);

void HInsert(Heap* H, path* data);
path HDelete(Heap* H);
#endif