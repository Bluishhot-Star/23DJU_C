#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10
typedef struct CDLNode
{
    int number;
    int step;
    bool visit;
    struct CDLNode *llink, *rlink;
}CDLNode;
typedef struct CDLList
{
    CDLNode* head;
}CDLList;
CDLList* createCDLList(void)
{
    CDLList* CDL = (CDLList*)malloc(sizeof(CDLList));
    CDL->head = NULL;
    return CDL;
}
CDLNode* insertCDLNode(CDLList* CDL, CDLNode* pre, int x, int step)
{
    CDLNode* newNode = (CDLNode*)malloc(sizeof(CDLNode));
    newNode->number = x; newNode->step = step; newNode->visit = false;
    if (CDL -> head == NULL)
    {
        CDL -> head = newNode;
        newNode->rlink = newNode;
        newNode->llink = newNode;
    }
    else
    {
        newNode->rlink = pre->rlink;
        pre->rlink = newNode;
        newNode->llink = pre;
        if (newNode->rlink == CDL->head)
        {
            CDL->head->llink = newNode;
        }
    }
    return newNode;
}
int main()
{
    int i, N, step, move[MAX_N] = {0};
    int count  = 0;
    CDLNode *p;
    CDLList* CDL = createCDLList();
    scanf("%d", &N);
    for ( i = 0; i < N; i++)
    {
        scanf("%d", &move[i]);
    }
    p = CDL->head;
    for ( i = 0; i < N; i++)
    {
        p = insertCDLNode(CDL, p, i+1, move[i]);
    }
    p = CDL->head;
    p->visit = true;
    printf("%5d", p->number);
    do
    {
        step = p->step;
        if (step > 0)
        {
            for (i = 0; i<step; i++)
            {
                p = p->rlink;
            }
            if (p->visit == true)
            {
                while (p->visit == true)
                {
                    p = p->rlink;
                }
            }
        }
        else
        {
            for(i = step; i< 0; i++)
            {
                p = p->llink;
            }
            if (p->visit == true)
            {
                while (p->visit == true)
                {
                    p = p->llink;
                }
            }
        }
        p->visit = true;
        printf(" %5d ", p->number);
        count++;
    } while (count < N-1);
    printf("\n");
    return 0;
}