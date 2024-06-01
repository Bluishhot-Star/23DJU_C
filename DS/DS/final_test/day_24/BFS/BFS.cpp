#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h" // 인접리스트 그래프
#include "Queue.h" // 큐

void BFS(LinkedGraph* G, int v)
{
    GNode* temp = searchVertex(G, v); //정점 찾기
    temp->visited = true;           //첫번째 정점 방문
    Queue* Q = createQueue();       //큐 생성
    AdjNode* N = temp->edgeHead;    //정점의 인접 정점 정보
    GNode* AdV = NULL; //인접 정점의 주소
    printf("%3d", v);
    for (int i = 0; i < temp->eCnt; i++)
    {
        GNode* AdV = searchVertex(G, N->linkedV); //인접 정점 주소
        AdV->visited = true; //방문인증
        printf("%3d", AdV->vertex); //값 출력
        enQueue(Q, N->linkedV); //큐에 넣기
        N = N->rlink; //다음 인접항
    }
    while (Q->front != NULL)
    {    
        v = deQueue(Q);
        temp = searchVertex(G, v);
        N = temp->edgeHead;
        for (int i = 0; i < temp->eCnt; i++)
        {
            AdV = searchVertex(G,N->linkedV);
            if (!(AdV->visited))
            {
                AdV->visited = true; printf("%3d", AdV->vertex); enQueue(Q, N->linkedV);
            }
            N = N->rlink;
        }
    }
}

int main(void)
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

    printf("\n*****BFS*****\n");
    BFS(G1, 0);     printf("\n");
    return 0;
}