#ifndef __ADJM__H__
#define __ADJM__H__
#define MaxArray 10000
#define MaxVertex 6

typedef struct AdjMatrix
{
    unsigned nov;
    unsigned noe;
    int edge[MaxVertex][MaxVertex];
}ArrayGraph;

ArrayGraph* createGraph();

void insertVertex(ArrayGraph* G, char v);

void insertEdge(ArrayGraph* G, char u, char v, int weight);
void printGraph(ArrayGraph* G);

#endif