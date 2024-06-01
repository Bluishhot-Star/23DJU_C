#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct BtreeNode
{
    element data;
    struct BtreeNode *left, *right;
} BtreeNode;

BtreeNode* createBtreeNode(element data)
{
    BtreeNode*  newNode = (BtreeNode*)malloc(sizeof(BtreeNode));
    newNode->data = data; newNode->left = NULL; newNode->right = NULL;
    return newNode;
}

BtreeNode* makeBtree(BtreeNode* N, BtreeNode* left, BtreeNode* right)
{
    if (N!= NULL) {N->left = left; N->right=right;}
    return N;
}

void destroyBtreeNode(BtreeNode* N){
    free(N);
}

void destroyBtree(BtreeNode* N){
    if(N!=NULL) return;
    destroyBtreeNode(N->left); destroyBtree(N->right); destroyBtreeNode(N);
}

element getFolderSizePreorder(BtreeNode* N) //전위
{
    element temp = 0;
    if (N != NULL)
    {
        temp = N->data + getFolderSizePreorder(N->left) + getFolderSizePreorder(N->right);
    }
    return temp;
}

element getFolderSizeInorder(BtreeNode* N) //중위
{
    element temp = 0;
    if (N != NULL)
    {
        temp = getFolderSizePreorder(N->left) + N->data + getFolderSizePreorder(N->right);
    }
    return temp;
}
void printFolderSizePostorder(BtreeNode* N) //후위
{
    element temp = 0;
    if (N != NULL)
    {
        temp += getFolderSizePreorder(N->left) + getFolderSizePreorder(N->right) + N->data;
    }
    printf("%dMB\n", temp);
}

int main(){
    BtreeNode* Desktop = createBtreeNode(0);
    BtreeNode* C = createBtreeNode(0);
    BtreeNode* D = createBtreeNode(10);

    BtreeNode* Program = createBtreeNode(2);
    BtreeNode* C_Program = createBtreeNode(200);
    BtreeNode* Java_Program = createBtreeNode(100);
    
    BtreeNode* Data = createBtreeNode(15);

    BtreeNode* Music = createBtreeNode(40);
    BtreeNode* Paint = createBtreeNode(68);
    BtreeNode* Picture = createBtreeNode(55);
    BtreeNode* Movie = createBtreeNode(120);

    makeBtree(Program,C_Program,Java_Program);
    makeBtree(C,Program,Data);

    makeBtree(Paint,Picture,Movie);
    makeBtree(D,Music,Paint);

    makeBtree(Desktop,C,D);

    printf("--- C 드라이브의 용량 ---\n");
    printf("%dMB\n",getFolderSizePreorder(C));
    printf("%dMB\n",getFolderSizeInorder(C));
    printFolderSizePostorder(C);

    printf("--- D 드라이브의 용량 ---\n");
    printf("%dMB\n",getFolderSizePreorder(D));
    printf("%dMB\n",getFolderSizeInorder(D));
    printFolderSizePostorder(D);

    printf("--- 내 컴퓨터의 용량 ---\n");
    printf("%dMB\n",getFolderSizePreorder(Desktop));
    printf("%dMB\n",getFolderSizeInorder(Desktop));
    printFolderSizePostorder(Desktop);

    return 0;
}