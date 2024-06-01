#include <stdio.h>
#include <stdlib.h>
#include "BsTree.h"
#include "binaryTree.h"

tNode* BSTcreate(Tdata data)
{
    tNode* N = (tNode*)malloc(sizeof(tNode));
    N->data = data;
    N->left = NULL;
    N->right = NULL;
    return N;
}
BSTData BSTGetNodeData(tNode* node)
{
    return node->data;
}
void BSTInsertNode(tNode * pRoot, tNode* nNode)
{
    tNode* temp = pRoot;
    if (temp == NULL) return;
    if (temp->data == nNode->data) return;
    else if(temp->data > nNode->data) //현재 data가 더 큼
    {
        if(GetLeftSubTree(temp) != NULL) BSTInsertNode(GetLeftSubTree(temp), nNode);
        else temp->left = nNode;
    }
    else{
        if(GetRightSubTree(temp) != NULL) BSTInsertNode(GetRightSubTree(temp), nNode);
        else temp->right = nNode;
    }
}
tNode* BSTSearch(tNode* node, Tdata target)
{
    tNode* pNode = node;
    if(pNode == NULL) return NULL;
    if(pNode->data == target) return pNode;
    if(pNode->data > target) return BSTSearch(pNode->left, target); //return 하지 않으면 스택 쌓여서 계속 진행됨
    else return BSTSearch(pNode->right, target);
}

void printBST(tNode* P)
{
    if(P == NULL) return;
    printBST(P->left);
    printf("%3d ",P->data);
    printBST(P->right);
}

void destroyNode(tNode *N){
    free(N);
}
void destroyTree(tNode* T){
    if(T == NULL) return;
    destroyTree(T->left); destroyTree(T->right); destroyNode(T);
}

void removeNode(tNode* T, Tdata data)
{
    // 자식 X
    // 자식 1개
    // 자식 2개
    tNode* dNode = T;
    tNode* parent = NULL;
    while (dNode!= NULL && dNode->data != data)
    {
        parent = dNode;
        if(dNode->data > data) dNode = dNode->left;
        else dNode = dNode->right;
    }
    if(dNode == NULL) {printf("존재하지 않는 노드\n"); return;}
    else
    {
        if(dNode->left == NULL && dNode->right == NULL)
        {
            if(parent->left == dNode) parent->left = NULL;
            else parent->right = NULL;
        }
        else if(dNode->left == NULL || dNode->right == NULL)
        {
            if(parent->left == dNode)
            {
                if(dNode->left == NULL) parent->left = dNode->right;
                else parent->left = dNode->left;
            }
            else
            {
                if(dNode->left == NULL) parent->right = dNode->right;
                else parent->right = dNode->left;
            }
        }
        else // 자식 노드 둘 다 O (왼쪽 자식 중 가장 큰 값 or 오른쪽 자식 중 가장 작은 값)
        {
            tNode* newChild = dNode->right;
            tNode* ncParent = NULL;

            while(newChild->left != NULL)
            {
                ncParent = newChild;
                newChild = newChild->left;
            }
            if (dNode->right == newChild)
            {
                newChild->left = dNode->left;
            }
            else{
                ncParent->left = NULL;
                newChild->left = dNode->left;
                newChild->right = dNode->right;
            }
            if (parent->left == dNode) parent->left = newChild;
            else parent->right = newChild;
        }
    }
    free(dNode);
}