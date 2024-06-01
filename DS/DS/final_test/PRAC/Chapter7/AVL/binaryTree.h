#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Tdata;
typedef struct binaryTree
{
    int data;
    struct binaryTree* left;
    struct binaryTree* right;
}tNode;

tNode* createNode();

Tdata GetData(tNode* node);

void SetData(tNode* node, Tdata data);

tNode* GetLeftSubTree(tNode* parent);

tNode* GetRightSubTree(tNode* parent);

void MakeLeftSubTree(tNode* parent, tNode* child);
void MakeRightSubTree(tNode* parent, tNode* child);
// 함수 포인터를 이용해 노드 방문 시 처리할 연산 캡슐화
typedef void VisitFunc(Tdata data); 

void PreTrav(tNode* node, VisitFunc action);
void InTrav(tNode* node, VisitFunc action);
void PostTrav(tNode* node, VisitFunc action);

void printIntData(int data);
void DeleteTree(tNode* node); //트리 메모리 해제 (후위 탐색)

#endif