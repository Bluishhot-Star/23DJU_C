#include <stdio.h>
#include <stdlib.h>
#include "BsTree.h"
#include "binaryTree.h"

int main(void)
{
    tNode* P = BSTcreate(4);
    BSTInsertNode(P,BSTcreate(1));
    BSTInsertNode(P,BSTcreate(6));
    BSTInsertNode(P,BSTcreate(2));
    BSTInsertNode(P,BSTcreate(8));
    BSTInsertNode(P,BSTcreate(3));
    BSTInsertNode(P,BSTcreate(5));
    BSTInsertNode(P,BSTcreate(7));
    BSTInsertNode(P,BSTcreate(10));

    printBST(P); printf("\n");

    tNode* T = BSTSearch(P,5);
    if(T != NULL){printf("탐색 성공 : %3d\n",T->data);}
    else printf("실패\n");

    T = BSTSearch(P,7);
    if(T != NULL){printf("탐색 성공 : %3d\n",T->data);}
    else printf("실패\n");

    removeNode(P, 6);
    printBST(P); printf("\n");

    return 0;
}
