#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DLNode
{
    char data[10];
    struct DLNode *llink, *rlink; //이전 노드, 다음 노드
}DLNode;

typedef struct DLList
{
    struct DLNode* head; // 헤드 주소
}DLList;

DLList* createDLList(void)
{
    DLList* DL = (DLList*)malloc(sizeof(DLList));
    DL->head = NULL;
    return DL;
}

DLNode* searchNode(DLList* DL, const char* x)
{
    DLNode* p = DL->head;
    while (p != NULL)
    {
        if (strcmp(p->data, x) == 0) return p;
        else p = p->rlink;
    }
    return p;
}
void insertNode(DLList* DL, DLNode* preNode, const char* x)
{
    DLNode* newNode = (DLNode*)malloc(sizeof(DLNode));
    strcpy(newNode->data, x);
    if (DL->head == NULL)
    {
        newNode->rlink = NULL; newNode->llink = NULL;
        DL->head = newNode;
    }
    else
    {
        newNode->rlink = preNode->rlink;
        preNode->rlink = newNode;
        newNode->llink = preNode;
        if (newNode->rlink != NULL)
        {
            newNode->rlink->llink = newNode;
        }
    }
}
void appendNode(DLList* DL, const char* x)
{
    DLNode* newNode = (DLNode*)malloc(sizeof(DLNode));
    strcpy(newNode->data, x);
    if (DL->head == NULL)
    {
        newNode->rlink = NULL; newNode->llink = NULL;
        DL->head = newNode;
    }
    else
    {
        DLNode* pNode = DL->head;
        while (pNode->rlink != NULL)
        {
            pNode = pNode->rlink;
        }
        pNode->rlink = newNode;
        newNode->rlink = NULL;
        newNode->llink = pNode;
    }
}
void deleteNode(DLList* DL, const char* x)
{
    DLNode* delNode = searchNode(DL, x);
    if (delNode != NULL)
    {
        delNode->llink->rlink = delNode->rlink;
        if (delNode->rlink != NULL)
        {
            delNode->rlink->llink = delNode->llink;
        }
        free(delNode);
    }
    else
    {
        printf("입력한 정보를 찾을 수 없습니다.\n");
    }
}
void printDLList(DLList* DL)
{
    DLNode* p = DL->head;
    if (p == NULL) return;
    while (p != NULL)
    {
        printf("%s ", p->data);
        p = p->rlink;
    }
    printf("\n");
}

int main()
{
    DLList* DL = createDLList();
    insertNode(DL, NULL, "월요일");                     printDLList(DL);
    insertNode(DL, searchNode(DL, "월요일"), "화요일"); printDLList(DL);
    appendNode(DL, "수요일"); printDLList(DL);
    deleteNode(DL, "수요일"); printDLList(DL);
    appendNode(DL, "금요일"); printDLList(DL);
    return 0;
}