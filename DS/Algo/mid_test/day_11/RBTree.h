#ifndef RBTREE_H
#define RBTREE_H

typedef int element;
enum Color {RED, BLACK};
typedef struct RBTreeNode
{
    struct RBTreeNode* parent;
    struct RBTreeNode* left;
    struct RBTreeNode* right;
    Color color;
    element data;
}Node;
Node* createNode(element data);
Node* createNilNode();
void destroyNode(Node *N);
void destroyTree(Node* T);
Node* searchNode(Node* tree, element target);
Node* searchMinNode(Node* tree);
void printTree(Node* tree);

void insertNode(Node** tree, Node* newNode);
void insertNodeHelper(Node** tree, Node* newNode);

void rotateRight(Node** root, Node* parent);
void rotateLeft(Node** root, Node* parent);

void rebuildAfterInsert(Node** root, Node* X);

Node* removeNode(Node** root, element data);
void rebuildAfterRemove(Node** root, Node* successor);
#endif