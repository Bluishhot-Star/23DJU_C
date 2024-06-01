#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 6

typedef struct AdjMatrix
{
    int noV;
    int noE;
    int edge[MaxVertex][MaxVertex];
}ArrayGraph;

ArrayGraph* createGraph() {
    ArrayGraph* G = (ArrayGraph*)malloc(sizeof(ArrayGraph));
    G->noV = 0;
    G->noE = 0;
    return G;
}

void addVertex(ArrayGraph* G, int v){
    if ((G->noV) + 1 > MaxVertex) {printf("정점 개수 초과\n"); return;}
    if (v < (G->noV)) return;
    (G->noV)++;
}

void addEdge(ArrayGraph* G, int u, int v){
    if (u > (G->noV)-1 || v > (G->noV)-1) {printf("정점 번호 없음\n"); return;}
    if (u < 0 || v < 0) {printf("정점 번호 없음\n"); return;}
    G->edge[u][v] = 1;
    (G->noE)++;
}

void printGraph(ArrayGraph* G){
    printf("그래프(정점개수 : %d, 간선개수 : %d\n", G->noV, G->noE);
    printf("인접 행렬\n");
    for (int i = 0; i < G->noV; i++)
    {
        printf("V %d :\t",i);
        for (int j = 0; j < G->noV; j++)
        {
            printf("%3d",G->edge[i][j]);
        }
        printf("\n");
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
    addVertex(G1, 0);        addVertex(G1, 1);
    addVertex(G1, 2);        addVertex(G1, 3);
    addEdge(G1, 0, 1);        addEdge(G1, 0, 3);
    addEdge(G1, 1, 0);        addEdge(G1, 1, 2);        addEdge(G1, 1, 3);
    addEdge(G1, 2, 1);        addEdge(G1, 2, 3);
    addEdge(G1, 3, 0);        addEdge(G1, 3, 1);        addEdge(G1, 3, 2);
    printGraph(G1);
    return 0;
}