#ifndef __BSTREE_H__
#define __BSTREE_H__
#include "binaryTree.h"

typedef Tdata BSTData;


tNode* BSTcreate(Tdata data);
BSTData BSTGetNodeData(tNode* node);
void BSTInsertNode(tNode* pRoot, tNode* nNode); // 삽입위치 탐색 및 연산
tNode* BSTSearch(tNode* node, Tdata target); // 탐색.. 중요한 점은 return으로 재귀연산 시 쌓이지 않도록 하는 것!
void printBST(tNode* P); //중위 순회로 오름차순 출력
void destroyNode(tNode *N);
void destroyTree(tNode* T); //후위 순회로 clear
void removeNode(tNode* T, Tdata data);
#endif