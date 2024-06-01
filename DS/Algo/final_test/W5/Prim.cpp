#include <stdio.h>
#include <stdlib.h>

#define MaxV 7
#define INF 99999
typedef struct Graph_AdjMatrix
{
    int vCnt;
    int adjMatirx[MaxV][MaxV];
}Graph;

Graph* createGraphInstance(int n){
    int i, j;
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vCnt = n;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            G->adjMatirx[i][j] = 0;
    
    return G;
}

void addEdgeND(Graph* G, int u, int v, int w){
    G->adjMatirx[u][v] = w;
    G->adjMatirx[v][u] = w;
}
void addEdgeD(Graph* G, int u, int v, int w){
    G->adjMatirx[u][v] = w;
}

void printGraph(Graph* G){
    printf("그래프 (정점의 갯수 : %d)\n", G->vCnt);
    printf("\n인접행렬\n");
    for (int i = 0; i < G->vCnt; i++)
    {
        for (int j = 0; j < G->vCnt; j++)
        {
            printf("%4d", G->adjMatirx[i][j]);
        }
        printf("\n");
    }
}

void Prim(Graph* G, int u){
    int x = 0, y = 0;
    int i, j, minDist, nextv = 0;
    int weight[MaxV][MaxV];
    int n = G->vCnt;
    int eCnt = 0;
    int visited[MaxV];

    // 인접행렬 복사하기 (0-->INF)
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G->adjMatirx[i][j] == 0) weight[i][j] = INF;
            else weight[i][j] = G->adjMatirx[i][j];
        }
    }
    // 시작 정점의 인접행렬 가져오기&visited 배열 생성
    for ( i = 0; i < n; i++)
    {
        visited[i] = 0;
    }   
    // 방문여부 설정
    visited[u] = true;

    printf("프림 MST(시작점:%d)\n", u);
    // 시작정점 제외 나머지 정점에 접근할 때 마다 간선 하나 생성
    while (eCnt < n -1)
    {
        minDist = INF;
        for (int i = 0; i < n; i++)
        {
            if (visited[i]){ // 방문했던 정점의 인접정점 탐색
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && weight[i][j]) // 인접정점 중 방문 X && 가중치 존재
                    {
                        if(minDist > weight[i][j]){ // minDist에 저장된 값보다 가중치가 더 작다면
                            minDist = weight[i][j]; // 바꾸기
                            x = i; y = j; // 현재 인접행렬 인덱스 저장
                        }
                    }   
                }
            }
        }
        printf("%d - %d: %d\n", x, y, weight[x][y]); // 가장 가까운 정점으로 간선 추가
        visited[y] = true; // 가장 가까운 정점으로 방문
        eCnt++; // 간선 추가
    }
}

void Dijkstra(Graph* G, int u){
    int i, j, count, minDist, nextV = 0;
    int weight[MaxV][MaxV], distance[MaxV], pred[MaxV], visited[MaxV];
    int n = G->vCnt;
    // 인접행렬 복사
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G->adjMatirx[i][j] == 0) weight[i][j] = INF;
            else weight[i][j] = G->adjMatirx[i][j];
        }
    }
    // 시작 정점으로부터의 최단거리 정보 배열 & visited배열 생성및초기화
    for (i = 0; i < n; i++)
    {
        distance[i] = weight[u][i]; // 알단은 시작 정점의 인접정보로 초기화
        pred[i] = u;
        visited[i] = 0;
    }
    // 시작 정점에 대한 정보 업데이트
    distance[u] = 0;
    visited[u] = true;
    count = 1;

    while (count < n-1)
    {
        minDist = INF;
        for (i = 0; i < n; i++)
        {
            // 정점들 중 현재 최소 거리보다 작고 방문하지 않은 것이 있다면
            if(distance[i] < minDist && !visited[i]){
                // 해당 정점을 다음 방문 정점으로
                minDist = distance[i];
                nextV = i;
            }
        }
        // 방문정보 업데이트
        visited[nextV] = 1;
        for (i = 0; i < n; i++)
        {
            // 아직 방문하지 않은 정점에 대하여
            if (!visited[i])
            {
                // 새로운 정점을 거쳐 가는 것이 현재 저장된 거리보다 더 가깝다면
                if (minDist + weight[nextV][i] < distance[i])
                {
                    // 새로운 경로의 거리를 저장하기
                    distance[i] = minDist + weight[nextV][i];
                    // 거점 정보 추가
                    pred[i] = nextV;
                }
            }
        }
        count++;
    }
    printf("다익스트라 최단경로(시작점:%d)\n", u);
    for (i = 0; i < n; i++)
    {
        if(i != u){
            printf("\nDistance from %d to %d: %d", u, i, distance[i]);
        }
    }
}

int main(){
    Graph* G = createGraphInstance(7);
    addEdgeND(G,0,1,11);addEdgeND(G,0,5,8);addEdgeND(G,0,6,9);
    addEdgeND(G,1,6,13);addEdgeND(G,1,2,8);
    addEdgeND(G,2,3,7);
    addEdgeND(G,3,6,12);
    addEdgeND(G,4,6,5);addEdgeND(G,4,5,10);
    printGraph(G);
    Prim(G,0);

    Graph* G1 = createGraphInstance(7);

    Dijkstra(G,0);
    return 0;
}