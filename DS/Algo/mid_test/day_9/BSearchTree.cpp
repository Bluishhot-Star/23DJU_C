#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct BinarySearchTreeNode{
    element data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
}Node;

Node* createNode(element data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;  node->left = NULL; node->right = NULL;
    return node;
}

Node* searchNode(Node* tree, element target){
    if(tree == NULL) return NULL;
    if(tree->data > target)
        return searchNode(tree->left, target);
    else if(tree->data < target)
        return searchNode(tree->right, target);
    else
        return tree;
}
Node* searchMinNode(Node* tree){
    if(tree == NULL) return NULL;
    if(tree->left == NULL) return tree;
    else
        return searchMinNode(tree->left);
}
void insertNode(Node* tree, Node* child){
    if (tree->data < child ->data){
        if(tree->right == NULL) tree->right = child;
        else insertNode(tree->right, child);
    }
    else if(tree->data > child->data){
        if(tree->left == NULL) tree->left = child;
        else insertNode(tree->left, child);
    }
}

Node* removeNode(Node* tree, Node* parent, element target){
    Node* removed = NULL;
    if(tree == NULL) return NULL; // 접근 노드 NULL
    if(tree->data > target)
        removed = removeNode(tree->left, tree, target); // 왼쪽 자식으로
    else if(tree->data < target)
        removed = removeNode(tree->right, tree, target); // 오른쪽으로
    else {
        if (tree->left != NULL && tree->right != NULL){ // 자식 노드 2개?
            Node* minNode = searchMinNode(tree->right); // 오른쪽 트리중 가장 작은 값 select
            minNode = removeNode(tree, NULL, minNode->data); // 해당 노드 삭제
            tree->data = minNode->data; // 값 변경
        }
        else { // 자식 노드 1개? 0개?
            Node* temp = NULL; // 단말노드
            if (tree->left != NULL) temp = tree->left; // 왼쪽 자식만
            else temp = tree->right; // 오른쪽 자식만
            if (parent->left == tree) // 현 노드가 부모의 왼쪽에?
                parent->left = temp; 
            else // 현 노드가 부모의 오른쪽
                parent->right = temp;
        }
    }
    return removed;
}
void printTree_inOrder(Node* tree){
    if (tree == NULL) return;
    printTree_inOrder(tree->left); printf(" %d ", tree->data); printTree_inOrder(tree->right);
}

int main(){
    Node* tree = createNode(123); Node* node = NULL;
    insertNode(tree, createNode(22));
    insertNode(tree, createNode(9918));
    insertNode(tree, createNode(424));
    insertNode(tree, createNode(17));
    insertNode(tree, createNode(3));
    insertNode(tree, createNode(98));
    insertNode(tree, createNode(34));
    insertNode(tree, createNode(760));
    insertNode(tree, createNode(317));
    insertNode(tree, createNode(1));
    printTree_inOrder(tree);    printf("\n");
    node = removeNode(tree,NULL, 98);
    printTree_inOrder(tree);    printf("\n");
    return 0;
}