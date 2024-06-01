#ifndef __ADJ_LIST__H
#define __ADJ_LIST__H

typedef struct AdjListNode
{
    int linkedV;
    struct AdjListNode* llink;
    struct AdjListNode* rlink;
}AdjNode;

typedef struct AdjLinkedListNode //doubleLinked
{
    unsigned vertex;
    AdjNode* edgeHead;
    int eCnt;
    struct AdjLinkedListNode* left;
    struct AdjLinkedListNode* right;
} GNode;

typedef struct AdjLinkedList //head
{
    int vCnt;
    int visited[30];
    GNode* head;
} LinkedGraph;

LinkedGraph* createGraph(); // 무방향 그래프 생성

void insertVertex(LinkedGraph* G, int v); // 원형linked insertVertex


GNode* searchVertex(LinkedGraph* G, int v); // 정점 존재 확인

void insertEdge(LinkedGraph* G, int u, int v); //무방향 그래프 간선 추가
void insertEdgeNode(GNode* U, int v); // 간선 노드 추가
void deleteVertex(LinkedGraph* G, int v); // 정점 제거
void deleteEdge(LinkedGraph* G, int u, int v);
void deleteEdgeNode(GNode* U, int v);
void printGraph(LinkedGraph* G);

#endif