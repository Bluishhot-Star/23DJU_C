#include <stdio.h>
#include <stdlib.h>
#include "linkedStack.h"
#include "adjList.h"

void DFS(LinkedGraph* G, int vertex)
{
    Stack* S = createStack();
    GNode* start = searchVertex(G, vertex);
    G->visited[vertex] = 1;
    printf("%3d",vertex);
    SPush(S, vertex);
    int visitV = vertex;
    while (!IsStackEmpty(S))
    {
        GNode* temp = searchVertex(G, visitV);
        AdjNode* linkedEdge = temp->edgeHead;
        int i;
        for(i=0; i<temp->eCnt; i++)
        {
            if(G->visited[linkedEdge->linkedV] == true)
            {
                linkedEdge = linkedEdge->rlink;
            }
            else
            {
                G->visited[linkedEdge->linkedV] = true;
                printf("%3d",linkedEdge->linkedV);
                SPush(S, linkedEdge->linkedV);
                visitV = linkedEdge->linkedV;
                break;
            }
        }
        if(i == temp->eCnt)
        {
            visitV = SPop(S);
        }
    }
}
int main()
{
    LinkedGraph* G = createGraph();
    insertVertex(G, 0);
    insertVertex(G, 1);
    insertVertex(G, 2);
    insertVertex(G, 3);
    insertVertex(G, 4);
    insertVertex(G, 5);
    insertVertex(G, 6);


    insertEdge(G, 0, 1);
    insertEdge(G, 0, 2);
    insertEdge(G, 1, 0);
    insertEdge(G, 1, 3);
    insertEdge(G, 1, 4);
    insertEdge(G, 2, 0);
    insertEdge(G, 2, 4);
    insertEdge(G, 3, 1);
    insertEdge(G, 3, 6);
    insertEdge(G, 4, 1);
    insertEdge(G, 4, 2);
    insertEdge(G, 4, 6);
    insertEdge(G, 5, 6);
    insertEdge(G, 6, 3);
    insertEdge(G, 6, 4);
    insertEdge(G, 6, 5);

    DFS(G, 0); printf("\n");
    return 0;
}