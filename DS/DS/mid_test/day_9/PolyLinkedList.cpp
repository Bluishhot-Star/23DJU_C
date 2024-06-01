#include <stdio.h>
#include <stdlib.h>
#include "PolyLinkedList.h"

listhead* createLinkedList(void)
{
    listhead* L = (listhead*)malloc(sizeof(listnode));
    if (L != NULL)
    {
        L->head = NULL;
        L->nodeCount = 0;
    }
    return L;
}
void insertTerm(listhead* L, float coef, int expo)
{
    listnode* newNode = (listnode*)malloc(sizeof(newNode));
    if (newNode != NULL)
    {
        newNode->coef = coef;
        newNode->expo = expo;
        newNode->link = NULL;
    }
    listnode* pFirst = L->head;
    if (pFirst == NULL) // 항이 없을 때
    {
        L->head = newNode;
        L->nodeCount++;
        return;
    }
    else if (L->nodeCount == 1) // 항이 하나일 때
    {
        if (pFirst->expo > expo)
        {
            pFirst->link = newNode;
            L->nodeCount++;
            return;
        }
        else if (pFirst->expo < expo)
        {
            newNode->link = pFirst;
            L->head = newNode;
            L->nodeCount++;
            return;
        }
        else
        {
            pFirst->coef += coef;
            free(newNode);
            return;
        }
    }
    else // 항 2개 이상
    {
        listnode *pSecond = pFirst;
        while (pFirst != NULL)
        {
            if (pFirst->expo < expo)
            {
                if(pFirst == L->head)
                {
                    L->head = newNode;
                }
                else
                {
                    pSecond->link = newNode;
                }
                newNode->link = pFirst;
                L->nodeCount++;
                return;
            }
            else if(pFirst->expo == expo)
            {
                pFirst->coef += coef;
                free(newNode);
                return;
            }
            pSecond = pFirst;
            pFirst = pFirst->link;
        }
        newNode->link = pFirst;
        pSecond->link = newNode;
        L->nodeCount++;
        return;
    }
    

}
void appendTerm(listhead* L, float coef, int expo)
{
    listnode* newNode = (listnode*)malloc(sizeof(newNode));
    if (newNode != NULL)
    {
        newNode->coef = coef;
        newNode->expo = expo;
        newNode->link = NULL;
    }

    listnode* p = L->head;
    if (p == NULL) // 첫 항일 때
    {
        L->head = newNode;
        L->nodeCount++;
        return;
    }
    else
    {
        while (p->link != NULL) //마지막 노드 찾기
        {
            p = p->link;
        }
    }
    p->link = newNode;
    L->nodeCount++;
}
listhead* addPoly(listhead* A, listhead* B)
{
    listhead* C = createLinkedList();
    listnode* nodeA = A->head;
    listnode* nodeB = B->head;

    int idxA = 0, idxB = 0;

    // 다항식 더하기
    if (C != NULL)
    {
        
        while (A->nodeCount != idxA && A->nodeCount != idxB)
        {
            if(nodeA->expo > nodeB->expo)
            {
                appendTerm(C,nodeA->coef, nodeA->expo);
                C->nodeCount++;
                idxA++;
                nodeA = nodeA->link;
            }
            else if (nodeB->expo > nodeA->expo)
            {
                appendTerm(C,nodeB->coef,nodeB->expo);
                C->nodeCount++;
                idxB++;
                nodeB = nodeB->link;
            }
            else
            {
                appendTerm(C,nodeA->coef+nodeB->coef,nodeA->expo);
                C->nodeCount++;
                idxA++; idxB++; 
                nodeA = nodeA->link;    nodeB = nodeB->link;
            }
        }
        for (int i = idxA; i < A->nodeCount; i++)
        {
            appendTerm(C,nodeA->coef, nodeA->expo);
            C->nodeCount++;
            idxA++;
            nodeA = nodeA->link;
        }
        for (int i = idxB; i < B->nodeCount; i++)
        {
            appendTerm(C,nodeB->coef,nodeB->expo);
            C->nodeCount++;
            idxB++;
            nodeB = nodeB->link;
        }
        
    }
    return C;
}
void printPoly(listhead* L){
    if (L->head != NULL)
    {
        listnode* p = L->head;
        for (; p; p = p->link)
        {
            printf("%3.0fx^%d", p->coef, p->expo);
            if (p->link != NULL)
            {
                printf(" +");
            }
            
        }
        printf("\n");
    }
    
}

void ReleaseList(listhead* L)
{
    listnode* pDelete = L->head;
    listnode* pNext = NULL;
    while (pDelete)
    {
        pNext = pDelete->link;
        free(pDelete);
        pDelete = pNext;
    }
}