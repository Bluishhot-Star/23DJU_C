#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"

void recursiveVertex(LinkedGraph* G, GNode* V)
{
    AdjNode* E = V->edgeHead;
    if(E == NULL) return;
    else{
        searchVertex(G, E->linkedV);
    }
}
void DFS(LinkedGraph* G, int v)
{
    GNode* temp = searchVertex(G, v); //정점 찾기
    temp->visited = true;
    AdjNode* edge = temp->edgeHead;
    printf(" %2d  |", v);
    for (int i = 0; i < temp->eCnt; i++)
    {
        if(searchVertex(G, edge->linkedV)->visited)
        {
            edge = edge->rlink;
        }
        else
        {
            DFS(G, edge->linkedV);
            edge = edge->rlink;
        }
    }
}

int main()
{
    LinkedGraph* G1 = createGraph();
    insertVertex(G1, 0);    insertVertex(G1, 1);
    insertVertex(G1, 2);    insertVertex(G1, 3);
    insertVertex(G1, 4);    insertVertex(G1, 5);
    insertVertex(G1, 6);

    insertEdge(G1, 0, 1);    insertEdge(G1, 0, 2);
    insertEdge(G1, 1, 3);    insertEdge(G1, 1, 4);
    insertEdge(G1, 2, 4);    insertEdge(G1, 3, 6);
    insertEdge(G1, 4, 6);    insertEdge(G1, 5, 6);

    printf("\n*****RESULT*****\n");
    printGraph(G1);


    printf("\n*****DFS*****\n");
    DFS(G1, 0);     printf("\n");
    return 0;
}


