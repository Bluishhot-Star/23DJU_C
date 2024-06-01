#include <stdio.h>
#include <stdlib.h>
#include "AdjM.h"
#define MaxArray 30
#define MaxVertex 6


ArrayGraph* createGraph() {
    ArrayGraph* G = (ArrayGraph*)malloc(sizeof(ArrayGraph));
    G->nov = 0;
    G->noe = 0;
    return G;
}

void insertVertex(ArrayGraph* G, char v) {
    int V = v-65;
    if ((G->nov) + 1 > MaxVertex)
    {
        printf("정점 개수 초과\n"); return;
    }
    if (V < (G->nov)) return;
    (G->nov)++;
}

void insertEdge(ArrayGraph* G, char u, char v, int weight){
    int U = u-65;
    int V = v-65;
    if (U > (G->nov) - 1 || V > (G->nov) - 1) {
        printf("정점 번호 없음\n"); return;
    }
    G->edge[U][V] = weight;
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
                printf("%3d", G->edge[i][j]);
            printf("\n");
        }   
    }
}
