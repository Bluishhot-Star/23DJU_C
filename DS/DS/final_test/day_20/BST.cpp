#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct BSTNode
{
    element data;
    struct BSTNode *left, * right;
}BSTNode;

BSTNode* createNode(element data){
    BSTNode* N = (BSTNode*)malloc(sizeof(BSTNode));
    N->data = data; N->left = NULL; N->right = NULL;
    return N;
}
void destroyNode(BSTNode *N){
    free(N);
}
void destroyTree(BSTNode* T){
    if(T == NULL) return;
    destroyTree(T->left); destroyTree(T->right); destroyNode(T);
}
BSTNode* searchNode(BSTNode* T, element data){
    BSTNode* pNode = T;
    if (pNode == NULL) return NULL;
    if (pNode->data == data) return pNode;
    if(data < pNode->data) return searchNode(pNode->left, data);
    else return searchNode(pNode->right, data);
}

void insertNode(BSTNode* T, BSTNode* C){
    BSTNode* pNode = T;
    if (pNode == NULL) return;
    if (pNode->data < C->data)
    {
        if (pNode->right == NULL) pNode-> right = C;
        else insertNode(pNode->right, C);       
    }
    else if(pNode->data > C->data)
    {
        if (pNode->left == NULL) pNode-> left = C;
        else insertNode(pNode->left, C);  
    }
}
BSTNode* removeNode(BSTNode* T, element data)
{
    if (T == NULL) return NULL;
    BSTNode* pNode = T;
    BSTNode* parent = NULL;
    while (pNode != NULL && pNode->data != data)
    {
        parent = pNode;
        if (data < pNode->data) pNode = pNode->left;
        else pNode = pNode->right; 
    }
    if (pNode == NULL)
    {
        printf("삭제할 노드가 트리에 존재하지 않음!\n");
        return NULL;
    }
    else
    {
        if (pNode->left == NULL && pNode->right == NULL) // 단말 노드일 경우
        {
            if (parent != NULL) // 부모노드 존재할 경우 (트리에 항이 하나가 아닐 경우)
            {
                if (parent->left == pNode) parent->left = NULL;
                else parent->right = NULL;
            }            
            else T = NULL; // 트리의 노드가 하나일 경우
        }
        else if (pNode->left == NULL || pNode->right==NULL) // 삭제할 노드가 하나의 자식 노드를 가지고 있을 경우
        {
            if(parent->left == pNode)
            {
                if (pNode->left == NULL) // 오른쪽에 자식노드
                    parent->left = pNode->right;
                else // 왼쪽에 자식노드
                    parent->left = pNode->left;
            }
            else
            {
                if (pNode->left == NULL) // 오른쪽에 자식노드
                    parent->right = pNode->right;
                else // 왼쪽에 자식노드
                    parent->right = pNode->left;
            }
        }
        else // 둘 다 가지고 있을 경우
        {
            BSTNode* tNode = pNode->left; // 삭제할 노드보다 작은 값 포레스트 탐색
            BSTNode* tpNode = tNode; // 타겟노드의 부모노드
            while (tNode->right != NULL) // 포레스트 중 가장 큰 값 = 타겟노드
            {
                tpNode = tNode;
                tNode = tNode->right;
            }
            tpNode->right = NULL;
            tNode->left = pNode->left;    tNode->right = pNode->right;
            if(parent->left == pNode) parent->left = tNode;
            else parent->right = tNode;
        }
    }
    return pNode;
}
void printBSTInorder(BSTNode* N)
{
    if (N == NULL) return;
    printBSTInorder(N->left);   printf("%3d\t", N->data);   printBSTInorder(N->right);
}

int main(){
    BSTNode* T = createNode(123);
    BSTNode* N = NULL;
    insertNode(T, createNode(22)); insertNode(T, createNode(9918));
    insertNode(T, createNode(424)); insertNode(T, createNode(17));
    insertNode(T, createNode(3)); insertNode(T, createNode(98));
    insertNode(T, createNode(34)); insertNode(T, createNode(760));
    insertNode(T, createNode(317)); insertNode(T, createNode(1));
    printBSTInorder(T); printf("\n");

    N = removeNode(T, 98);
    destroyNode(N);
    printBSTInorder(T); printf("\n");

    if ((N = searchNode(T, 111)) == NULL) insertNode(T, createNode(111));
    printBSTInorder(T); printf("\n");

    destroyTree(T);

    return 0;
}