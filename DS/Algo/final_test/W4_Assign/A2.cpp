#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 6
#define MaxQueue 10
#define MaxStack 10
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
    printf("그래프(정점개수 : %d, 간선개수 : %d)\n", G->noV, G->noE);
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

typedef struct CircularQueue
{
    int front, rear;
    int queue[MaxQueue];
}Queue;
Queue* creatQueueInstance(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0; Q->rear = 0;
    return Q;
}
void enQueue(Queue* Q, int item){
    if(((Q->rear + 1) % MaxQueue) == Q->front){
        printf("overflow: can't enqueue item\n");
        return;
    }
    Q->rear = (Q->rear + 1) % MaxQueue;
    Q->queue[Q->rear] = item;
}
int deQueue(Queue* Q){
    if (Q->front == Q->rear){
        printf("underflow: can't dequeue item\n");
        return 1;
    }
    Q->front = (Q->front + 1) % MaxQueue;
    return Q->queue[Q->front];
}

void BFS(ArrayGraph* G, int v){
    int visited[G->noV];
    for (int i = 0; i < G->noV; i++)
    {
        visited[i] = 0;
    }
    
    Queue* Q = creatQueueInstance();
    enQueue(Q, v);
    printf("BFS : ");
    while(Q->front != Q->rear){
        int temp = deQueue(Q);
        printf("%2d ", temp);
        visited[temp] = 1;
        for (int j = 0; j < MaxVertex; j++)
        {
            if(G->edge[temp][j] == 1){
                if(visited[j] == 1) continue;
                enQueue(Q, j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

typedef struct ArrayStack
{
    int top;
    int stack[MaxStack];
}Stack;

Stack* createStackInstance(){
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->top = -1;
    return S;
}
void push(Stack* S, int item){
    if (S->top == MaxStack)
    {
        printf("overflow : can't push item\n");
        return;
    }
    S->stack[++S->top] = item;
}
int pop(Stack* S){
    if (S->top == -1)
    {
        printf("underflow : can't pop item\n");
        return -1;
    }
    return S->stack[S->top--];
}

void DFS(ArrayGraph* G, int v){
    int visited[G->noV];
    for (int i = 0; i < G->noV; i++)
    {
        visited[i] = 0;
    }
    Stack* S = createStackInstance();
    push(S, v);
    printf("DFS :");
    while (S->top != -1)
    {
        int temp = pop(S);
        printf("%3d", temp);
        visited[temp] = 1;
        for (int j = 0; j < G->noV; j++)
        {
            if(G->edge[temp][j] == 1){
                if(visited[j] == 1) continue;
                push(S, j);
                break;
            }
        }        
    }
    printf("\n");
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

    BFS(G1, 0);
    DFS(G1, 1);
}