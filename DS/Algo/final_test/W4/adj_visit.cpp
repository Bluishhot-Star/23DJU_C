#include <stdio.h>
#include <stdlib.h>
#define MaxVertex 7

typedef struct Graph_AdjMatrix_Node
{
    int vertex;
    struct Graph_AdjMatrix_Node* link;
}Node;

typedef struct Graph_AdjMatrix{
    int vertexCount;
    Node* adjHead[MaxVertex];
    int visited[MaxVertex];
}Graph;

Graph* createGraphInstance(){
    Graph* G1 = (Graph*)malloc(sizeof(Graph));
    G1->vertexCount = 0;
    for (int i = 0; i < MaxVertex; i++)
    {
        G1->visited[i] = false;
        G1->adjHead[i] = NULL;
    }
    return G1;
}
void addVertex(Graph* G){
    if (G->vertexCount < MaxVertex) G->vertexCount++;    
}
void addEdge(Graph* G, int u, int v){
    Node* V = (Node*)malloc(sizeof(Node));
    V->vertex = v;
    V->link = G->adjHead[u];
    G->adjHead[u] = V;
}
void printGraph(Graph* G){
    Node* p;
    for (int i = 0; i < G->vertexCount; i++)
    {
        p = G->adjHead[i];
        printf("정점 %d의 인접리스트 : ", i);
        while (p){
            printf("%d ",p->vertex);
            p = p->link;
        }
        printf("\n");
    }
}
int main(){
    Graph* G1 = createGraphInstance();
    for (int i = 0; i < MaxVertex; i++)
    {
        addVertex(G1);
    }
    addEdge(G1, 0, 2);
    addEdge(G1, 0, 1);
    addEdge(G1, 1, 4);
    addEdge(G1, 1, 3);
    addEdge(G1, 1, 0);
    addEdge(G1, 2, 4);
    addEdge(G1, 2, 0);
    addEdge(G1, 3, 6);
    addEdge(G1, 3, 1);
    addEdge(G1, 4, 6);
    addEdge(G1, 4, 2);
    addEdge(G1, 4, 1);
    addEdge(G1, 5, 6);
    addEdge(G1, 6, 5);
    addEdge(G1, 6, 4);
    addEdge(G1, 6, 3);


    printGraph(G1);
    return 0;
}