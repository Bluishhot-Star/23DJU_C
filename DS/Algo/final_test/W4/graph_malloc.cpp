#include <stdio.h>
#include <stdlib.h>

typedef struct Graph_AdjMatrix{
    int ** adjMatrix;
}Graph;

typedef struct Graph_AdjMatrix_Node
{
    int vertex;
    struct Graph_AdjMatrix_Node* link;
}Node;


Graph createGraphInstance(int maxvert){
    int i, j;
    Graph G1;
    G1.adjMatrix = (int**)malloc(maxvert * sizeof(int*));
    for (i = 0; i < maxvert; i++)
        G1.adjMatrix[i] = (int*)malloc(maxvert*sizeof(int));
    
    // 초기화
    for (i = 0; i < maxvert; i++)
        for ( j = 0; j < maxvert; j++)
            G1.adjMatrix[i][j] = 0;

    return G1;
}

int main(){
    int i, j;
    Graph G1 = createGraphInstance(4);
    printf("%p -> %p\n",G1.adjMatrix, *(G1.adjMatrix));

    for (i = 0; i < 4; i++)
    {
        printf("%p:\n",G1.adjMatrix[i]);
        for ( j = 0; j < 4; j++)
        {
            printf("%d %d : %d\n", i, j, G1.adjMatrix[i][j]);
        }
        
    }
    

    return 0;
}
