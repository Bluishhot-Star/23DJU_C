#include <stdio.h>
#include <stdlib.h>
#include "AdjM.h"
#include "PriorQ.h"
#define MAX 100;
int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}
int* Dijkstra(char start, ArrayGraph* adjM)
{
    int dist[100]; //정점 경로 정보 리스트
    for (int i = 0; i < adjM->nov; i++) dist[i] = -1; //무한 초기화
    dist[start-65] = 0;

    Heap* H = createHeap(DataPriorityComp);
    path* p = createPath(start, start, 0);

    HInsert(H, p);
    while (!HisEmpty(H))
    {
        path cNode = HDelete(H); // 이전 방문 -> 현재
        for (int i = 0; i < adjM->nov; i++)
        {
            if (cNode.end == i+65) continue;
            char newEnd = i+ 65; // 현재 방문 정점의 인접점 조사
            int curToWeight = adjM->edge[(cNode.end) - 65][i]; // 현재 -> 인접점 가중치
            int strToCurIdx = (cNode.start - 65); // 처음->현재 가중치 조사하기위한 idx
            if (curToWeight == 0) continue; // 현재 간선에서 다음 정점으로 간선 X
            
            if(dist[i] == -1) //아직 정보X
            {
                dist[i] = curToWeight + dist[(cNode.end) - 65];
            }
            else
            {
                if(dist[i] < curToWeight + dist[(cNode.end) - 65])
                    continue;
                else
                    dist[i] = curToWeight + dist[(cNode.end) - 65];
            }
            path* p = createPath(cNode.end, newEnd, curToWeight + dist[strToCurIdx]);
            HInsert(H, p);
            p = NULL;
        }
    }
    return dist;
}

int main()
{
    ArrayGraph* G = createGraph();
    insertVertex(G, 'A');
    insertVertex(G, 'B');
    insertVertex(G, 'C');
    insertVertex(G, 'D');
    insertVertex(G, 'E');

    insertEdge(G, 'A', 'B', 10);    insertEdge(G, 'A', 'C', 20);    insertEdge(G, 'A', 'D', 25);
    insertEdge(G, 'B', 'A', 10);    insertEdge(G, 'B', 'C', 15);    insertEdge(G, 'B', 'D', 13); 
    insertEdge(G, 'C', 'A', 20);    insertEdge(G, 'C', 'B', 15);    insertEdge(G, 'C', 'E', 2);
    insertEdge(G, 'D', 'E', 4);
    insertEdge(G, 'E', 'A', 2);    insertEdge(G, 'E', 'D', 6);

    // insertVertex(G, 'A');
    // insertVertex(G, 'B');
    // insertVertex(G, 'C');
    // insertVertex(G, 'D');
    // insertVertex(G, 'E');
    // insertVertex(G, 'F');

    // insertEdge(G, 'A', 'B', 2);    insertEdge(G, 'A', 'C', 5);    insertEdge(G, 'A', 'D', 1);
    // insertEdge(G, 'B', 'D', 2);    insertEdge(G, 'B', 'C', 3);
    // insertEdge(G, 'C', 'B', 3);    insertEdge(G, 'C', 'F', 5);
    // insertEdge(G, 'D', 'C', 3);    insertEdge(G, 'D', 'E', 1);
    // insertEdge(G, 'E', 'C', 1);    insertEdge(G, 'E', 'F', 2);

    int* ptr = Dijkstra('A', G);
    printf("===최단경로===\n");
    for (int i = 0; i < G->nov; i++)
    {
        printf("[A] -> [%c] : %d\n", i+65, *(ptr+i));
    }

    
    return 0;
}