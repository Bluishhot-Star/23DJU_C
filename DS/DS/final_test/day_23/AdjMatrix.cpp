#include <stdio.h>
#include <stdlib.h>
#define MaxArray 30
#define MaxVertex 5

typedef struct AdjMatrix
{
    unsigned nov;
    unsigned noe;
    int edge[MaxVertex][MaxVertex];
}ArrayGraph;

ArrayGraph* createGraph() {
    ArrayGraph* G = (ArrayGraph*)malloc(sizeof(ArrayGraph));
    G->nov = 0;
    G->noe = 0;
    return G;
}

void insertVertex(ArrayGraph* G, int v) {
    if ((G->nov) + 1 > MaxVertex)
    {
        printf("정점 개수 초과\n"); return;
    }
    if (v < (G->nov)) return;
    (G->nov)++;
}

void insertEdge(ArrayGraph* G, int u, int v){
    if (u > (G->nov) - 1 || v > (G->nov) - 1) {
        printf("정점 번호 없음\n"); return;
    }
    G->edge[u][v] = 1;
    (G->noe)++;
}
void printGraph(ArrayGraph* G){
    int i, j;
    printf("그래프(정점갯수: %2d, 간선갯수: %2d)\n\n", G->nov, G->noe);
    printf("인접 행렬:\n\n");
    for ( i = 0; i < G->nov; i++)
    {
        printf("정점 번호: %d\t", i);
        {
            for (  j = 0; j < G->nov; j++)
            {
                printf("%3d", G->edge[i][j]);
            }
            printf("\n");
        }
        
    }
}
int main(){
    ArrayGraph* G1 = createGraph();
    for (int i = 0; i < MaxVertex; i++)
    {
        for (int j = 0; j < MaxVertex; j++)
        {
            G1->edge[i][j] = 0;
        }
    }
    insertVertex(G1, 0);        insertVertex(G1, 1);
    insertVertex(G1, 2);        insertVertex(G1, 3);
    insertEdge(G1, 0, 1);        insertEdge(G1, 0, 3);
    insertEdge(G1, 1, 0);        insertEdge(G1, 1, 2);        insertEdge(G1, 1, 3);
    insertEdge(G1, 2, 1);        insertEdge(G1, 2, 3);
    insertEdge(G1, 3, 0);        insertEdge(G1, 3, 1);        insertEdge(G1, 3, 2);
    printGraph(G1);

    return 0;
}