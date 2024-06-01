#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adjList.h"

LinkedGraph* createGraph(){ //head 생성
    LinkedGraph *G = (LinkedGraph*)malloc(sizeof(LinkedGraph));
    G->head = NULL;
    G->vCnt = 0;
    memset(G->visited, 0, sizeof(int)*30);
    return G;
}

void insertVertex(LinkedGraph* G, int v) //원형linked insertVertex
{
    GNode *newVertex = (GNode*)malloc(sizeof(GNode));
    newVertex->vertex = v;
    newVertex->eCnt = 0;
    newVertex->edgeHead = NULL;
    if (G->head == NULL) // 정점이 0개
    {
        newVertex->left = NULL;
        newVertex->right = NULL;
        G->head = newVertex;
    }
    else
    {
        GNode* P = G->head;
        while (true)
        {
            if (P->vertex == newVertex->vertex)
            {
                printf("이미 존재하는 정점\n");
                free(newVertex);
                return;
            }
            else if (P->vertex > newVertex->vertex) // 현재 정점이 더 큰 수
            {
                if(P == G->head)
                {
                    G->head = newVertex;
                }
                newVertex->left = P->left;
                newVertex->right = P;
                P->left = newVertex;
                break;
            }
            else if (P->right == NULL) // 마지막 항
            {
                newVertex->left = P;
                P->right = newVertex;
                newVertex->right = NULL;
                break;
            }
            else
            {
                P = P->right;
            }
        }
    }
    G->vCnt++;
}

GNode* searchVertex(LinkedGraph* G, int v)
{
    if(G)
    {
        GNode* P = G->head;
        while (P != NULL)
        {
            if (P->vertex == v)
            {
                return P;
            }
            P = P->right;
        }
        printf("%d : 존재하지 않는 정점\n", v);
    }
    return NULL;
}

void insertEdge(LinkedGraph* G, int u, int v)
{
    if(G->vCnt <= 1){printf("정점의 수가 부족합니다.\n"); return;}
    if(u == v) {printf("%d 와 %d 같음\n",u, v); return;}
    GNode* U = searchVertex(G, u);
    GNode* V = searchVertex(G, v);
    if(U && V) //정점 존재
    {
        insertEdgeNode(U, v);
    }
}

void insertEdgeNode(GNode* U, int v)
{
    AdjNode* N = (AdjNode*)malloc(sizeof(AdjNode));
        N->llink = NULL;
        N->rlink = NULL;
        N->linkedV = v;
        if(U->edgeHead == NULL)
        {   
            U->edgeHead = N;
            N->llink = N;
            N->rlink = N;
        }
        else
        {
            AdjNode* temp = U->edgeHead;
            while (temp != NULL)
            {
                if (temp->linkedV == N->linkedV)
                {
                    printf("이미 연결된 정점\n");
                    free(N);
                    return;
                }
                else if (temp->linkedV > N->linkedV) // 현재 정점이 더 큰 수
                {
                    N->llink = temp->llink;
                    temp->llink->rlink = N;
                   temp->llink = N;
                    break;
                }
                else if (temp->rlink == U->edgeHead) // 마지막 항
                {
                    N->llink = temp;
                    temp->rlink = N;
                    N->rlink = U->edgeHead;
                    U->edgeHead->llink = N;
                    break;
                }
                else
                {
                    temp = temp->rlink;
                }
            }
        }
        U->eCnt++;
}

void deleteVertex(LinkedGraph* G, int v)
{
    if ((G->vCnt) == 0)
    {
        printf("현재 정점 개수 0개\n"); return;
    }
    else
    {
        GNode* P = searchVertex(G, v);
        if (P)
        {
            GNode* inspect = G->head;
            for (int i = 0; i < G->vCnt; i++)
            {
                if (v == inspect->vertex)
                {
                    AdjNode* tempNode = inspect->edgeHead->llink;
                    AdjNode* deleteNode = tempNode;
                    for (int i = 0; i < inspect->eCnt; i++)
                    {
                        tempNode = tempNode->llink;
                        free(deleteNode);
                        deleteNode = tempNode;
                    }

                    P->left->right = P->right;
                    P->right->left = P->left;
                    free(P);
                }
                else
                {
                    AdjNode* tempNode = inspect->edgeHead;
                    for (int i = 0; i < inspect->eCnt; i++)
                    {
                        if(tempNode->linkedV == v)
                        {
                            if(tempNode == inspect->edgeHead)
                            {
                                inspect->edgeHead = tempNode->rlink;
                            }
                            tempNode->rlink->llink = tempNode->llink;
                            tempNode->llink->rlink = tempNode->rlink;
                            free(tempNode);
                            inspect->eCnt--;
                            break;
                        }
                        tempNode = tempNode->rlink;
                    }
                }
                inspect = inspect->right;
            }
            G->vCnt--;
        }
    }
}
void deleteEdge(LinkedGraph* G, int u, int v)
{
    if(u == v) {printf("%d 와 %d 같음\n",u, v); return;}
    GNode* U = searchVertex(G, u);
    GNode* V = searchVertex(G, v);
    if(U&&V)
    {
        deleteEdgeNode(U, v);
    }
}

void deleteEdgeNode(GNode* U, int v)
{
    AdjNode* tempNode = U->edgeHead;
        for (int i = 0; i < U->eCnt; i++)
        {
            if(tempNode->linkedV == v)
            {
                if(tempNode == U->edgeHead)
                {
                    U->edgeHead = tempNode->rlink;
                }
                tempNode->rlink->llink = tempNode->llink;
                tempNode->llink->rlink = tempNode->rlink;
                free(tempNode);
                U->eCnt--;
                return;
            }
            tempNode = tempNode->rlink;
        }
}


void printGraph(LinkedGraph* G)
{
    if(G)
    {
        int noe = 0;
        printf("그래프 : \n");
        GNode* P = G->head;
        for (int i = 0; i < G->vCnt; i++)
        {
            printf("정점 : %d\t", P->vertex);
            AdjNode* tempNode = P->edgeHead;
            noe += P->eCnt;
            for (int j = 0; j < P->eCnt; j++)
            {
                printf("%3d", tempNode->linkedV);
                tempNode = tempNode->rlink;
            }
            P = P->right;
            printf("\n");
        }
        printf("( 정점 개수 : %d | 간선 개수 : %d )\n",G->vCnt, noe);
    }
}
