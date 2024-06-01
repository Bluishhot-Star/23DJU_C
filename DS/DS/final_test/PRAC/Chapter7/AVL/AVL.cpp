#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "BsTree.h"

int getHeight(tNode* node)
{
    int lHeight, rHeight;
    if(node == NULL) return 0;
    lHeight = getHeight(node->left);
    rHeight = getHeight(node->right);
    return (lHeight>rHeight ? lHeight : rHeight)+1;
}
int getBF(tNode* node)
{
    return getHeight(node->left) - getHeight(node->right);
}
tNode* rotateLL(tNode* parent)
{
    tNode* child = parent->left;
    parent->left = child->right;
    child->right = parent;
    return child;
}
tNode* rotateRR(tNode* parent)
{
    tNode* child = parent->right;
    parent->right = child->left;
    child->left = parent;
    return child;
}
tNode* rotateLR(tNode* parent)
{
    parent->left = rotateRR(parent->left);
    return rotateLL(parent);
}
tNode* rotateRL(tNode* parent)
{
    parent->right = rotateLL(parent->right);
    return rotateRR(parent);
}
tNode* rebalance(tNode** node)
{
    int BF = getBF(*node);
    if(BF>=2) // 2 이상(왼쪽으로 치우쳐짐)
    {
        if(getBF((*node)->left) > 0) *node = rotateLL(*node); //왼쪽 자식 BF가 + (LL유형)
        else *node = rotateLR(*node); //BF가 - (LR유형)
    }
    else if(BF<=-2) // -2 이하(오른쪽으로 치우쳐짐
    {
        if(getBF((*node)->right) < 0) *node = rotateRR(*node); //오른쪽 자식 BF가 - (RR유형)
        else *node = rotateRL(*node); //BF가 + (RL유형)
    }
    return *node; // 정상이라면 위 연산 거치지 않음, 연산 거친 후라면 정리된 이후!
}

tNode* insertAVLNode(tNode** node, Tdata data) //루트 노드 주소, 데이터
{
    if (*node == NULL) // 첫 번째로 넣는 경우
    {
        *node = (tNode*)malloc(sizeof(tNode));
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
    else if(data > (*node)->data) //삽입 대상이 더 큰 data
    {
        insertAVLNode(&((*node)->right), data); // 오른쪽으로 넣기(재귀로 들어감)
        *node = rebalance(node); //연산 후 루트 주소를 rebalance에 전달 (해당 세션의 루트 노드 바뀔 수 있음)
    }
    else if(data < (*node)->data)
    {
        insertAVLNode(&((*node)->left), data); // 왼쪽으로 넣기(재귀로 들어감)
        *node = rebalance(node); //연산 후 루트 주소를 rebalance에 전달
    }
    else
    {
        printf("same key\n");
        return NULL;
    }
    return *node;
}



tNode* removeAVLNode(tNode** T, tNode** parent, Tdata data)
{
    // 자식 X
    // 자식 1개
    // 자식 2개
    if ((*T) != NULL && (*T)->data != data)
    {
        if((*T)->data > data) removeAVLNode(&((*T)->left), T, data);
        else removeAVLNode(&((*T)->right), T, data);
        if(parent != NULL) *parent = rebalance(parent);
    }
    if((*T) == NULL) {printf("존재하지 않는 노드\n"); return NULL;}
    else if((*T)->data == data)
    {
        tNode* temp = (*T);
        if((*T)->left == NULL && (*T)->right == NULL)
        {
            if((*parent)->left == (*T)) (*parent)->left = NULL;
            else (*parent)->right = NULL;
        }
        else if((*T)->left == NULL || (*T)->right == NULL)
        {
            if((*parent)->left == (*T))
            {
                if((*T)->left == NULL) (*parent)->left = (*T)->right;
                else (*parent)->left = (*T)->left;
            }
            else
            {
                if((*T)->left == NULL)
                    (*parent)->right = (*T)->right;
                else (*parent)->right = (*T)->left;
            }
        }
        else // 자식 노드 둘 다 O (왼쪽 자식 중 가장 큰 값 or 오른쪽 자식 중 가장 작은 값)
        {
            tNode* newChild = (*T)->right;
            tNode* ncParent = NULL;

            while(newChild->left != NULL)
            {
                ncParent = newChild;
                newChild = newChild->left;
            }
            if ((*T)->right == newChild)
            {
                newChild->left = (*T)->left;
            }
            else{
                ncParent->left = NULL;
                newChild->left = (*T)->left;
                newChild->right = (*T)->right;
            }
            if ((*parent)->left == (*T)) (*parent)->left = newChild;
            else (*parent)->right = newChild;
        }
        free((temp));
    }
}


int main()
{
    tNode* rootAVL = NULL;
    rootAVL = insertAVLNode(&rootAVL, 12);
    insertAVLNode(&rootAVL, 11);
    insertAVLNode(&rootAVL, 10);
    insertAVLNode(&rootAVL, 5);
    insertAVLNode(&rootAVL, 3);
    insertAVLNode(&rootAVL, 7);
    insertAVLNode(&rootAVL, 6);
    insertAVLNode(&rootAVL, 1);
    insertAVLNode(&rootAVL, 13);
    insertAVLNode(&rootAVL, 2);
    insertAVLNode(&rootAVL, 4);
    printBST(rootAVL); printf("\n");

    // removeAVLNode(&rootAVL,NULL,4);
    // printBST(rootAVL); printf("\n");

    return 0;
}