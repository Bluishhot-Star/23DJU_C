#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

tNode* createNode()
{
    tNode* N = (tNode*)malloc(sizeof(tNode));
    return N;
}

Tdata GetData(tNode* node)
{
    return node->data;
}

void SetData(tNode* node, Tdata data)
{
    if (0<=data && data<=9)
    {
        node->data = data;
    }
    else node->data = data;
}

tNode* GetLeftSubTree(tNode* parent)
{
    return parent->left;
}

tNode* GetRightSubTree(tNode* parent)
{
    return parent->right;
}

void MakeLeftSubTree(tNode* parent, tNode* child)
{
    if (parent->left != NULL)
        free(parent->left);
    parent->left = child;
}

void MakeRightSubTree(tNode* parent, tNode* child)
{
    if (parent->right != NULL)
        free(parent->right);
    parent->right = child;
}
// 함수 포인터를 이용해 노드 방문 시 처리할 연산 캡슐화
// typedef void VisitFunc(Tdata data); 

void PreTrav(tNode* node, VisitFunc action)
{
    if (node == NULL) return;
    action(node->data);
    PreTrav(node->left, action);
    PreTrav(node->right, action);
}
void InTrav(tNode* node, VisitFunc action)
{
    if (node == NULL) return;
    InTrav(node->left, action);
    action(node->data);
    InTrav(node->right, action);
}
void PostTrav(tNode* node, VisitFunc action)
{
    if (node == NULL) return;
    PostTrav(node->left, action);
    PostTrav(node->right, action);
    action(node->data);
}

void printIntData(int data)
{
    printf("%3d |", data);
}
void DeleteTree(tNode* node) //트리 메모리 해제 (후위 탐색)
{
    if(node == NULL) return;
    DeleteTree(node->left);
    DeleteTree(node->right);
    printf("del node : %3d \n", node->data);
    free(node);
}

// int main()
// {
//     tNode* N = createNode();    tNode* N1 = createNode();
//     tNode* N2 = createNode();    tNode* N3 = createNode();
//     tNode* N4 = createNode();    tNode* N5 = createNode();
//     tNode* N6 = createNode();
//     MakeLeftSubTree(N4,N5);      MakeRightSubTree(N4,N6);
//     MakeLeftSubTree(N1,N2);      MakeRightSubTree(N1,N3);
//     MakeLeftSubTree(N,N1);       MakeRightSubTree(N,N4);

//     SetData(N,0);    SetData(N1,1);
//     SetData(N2,2);    SetData(N3,3);
//     SetData(N4,4);    SetData(N5,5);
//     SetData(N6,6);

//     InTrav(N, printIntData); printf("\n");
//     PreTrav(N, printIntData); printf("\n");
//     PostTrav(N, printIntData); printf("\n");
//     DeleteTree(N);
//     return 0;
// }