#include <stdio.h>
#include <stdlib.h>

#define MaxV 4
typedef struct Graph
{
    int* adjMatrix[MaxV][MaxV];
}Graph;

Graph createGraphInstance(){
    Graph G1;
    for (int i = 0; i < MaxV; i++)
    {
        for (int j = 0; j < MaxV; j++)
        {
            G1.adjMatrix[i][j] = 0;
        }
    }
    return G1;
}

int main(){
    Graph G1 = createGraphInstance();
    return 0;
}
