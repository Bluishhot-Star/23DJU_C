#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RBTree.h"

Node* createNode(element data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    return node;
}
Node* createNilNode(){
    Node* node = (Node*)malloc(sizeof(Node));
    node->parent= NULL; node->left= NULL; node->right=NULL; node->data = -1;
    node->color=BLACK;
    return node;
}
void destroyNode(Node *N){
    free(N);
}
void destroyTree(Node* T){
    if(T == NULL) return;
    destroyTree(T->left); destroyTree(T->right); destroyNode(T);
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
void printTree(Node* tree){
    if (tree == NULL) return;
    if (tree->data == -1) return;
    printTree(tree->left); 
    char s = (tree->color == RED)?'R':'B'; printf(" %d (%c)", tree->data, s); 
    printTree(tree->right);
}

static Node* Nil = createNilNode();
void insertNode(Node** tree, Node* newNode){
    insertNodeHelper(tree, newNode);
    if(newNode == NULL) return;
    newNode->color = RED;
    newNode->left = Nil;
    newNode->right = Nil;
    rebuildAfterInsert(tree, newNode);
}

void insertNodeHelper(Node** tree, Node* newNode){
    if (*tree == NULL) *tree = newNode;
    if((*tree)->data < newNode->data){
        if ((*tree)->right == Nil){
            (*tree)->right = newNode;
            newNode->parent = *tree;
        }
        else{
            insertNodeHelper(&(*tree)->right, newNode);
        }
    }
    else if((*tree)->data > newNode->data){
        if((*tree)->left == Nil){
            (*tree)->left = newNode;
            newNode->parent = *tree;
        }
        else{
            insertNodeHelper(&(*tree)->left, newNode);
        }
    }
    else{

    }
}
void rotateRight(Node** root, Node* parent){
    Node* leftChild = parent->left;
    parent->left = leftChild->right;

    if(leftChild->right != Nil) leftChild->right->parent = parent;
    leftChild->parent = parent->parent;

    if(parent->parent == NULL) (*root) = leftChild;
    else{
        if(parent == parent->parent->left) parent->parent->left = leftChild;
        else parent->parent->right = leftChild;
    }
    leftChild->right = parent;
    parent->parent = leftChild;
}

void rotateLeft(Node** root, Node* parent){
    Node* rightChild = parent->right;
    parent->right = rightChild->left;
    if(rightChild->left != Nil) rightChild->left->parent = parent;
    rightChild->parent = parent->parent;

    if(parent->parent == NULL) (*root) = rightChild;
    else{
        if(parent == parent->parent->left) parent->parent->left = rightChild;
        else parent->parent->right = rightChild;
    }
    rightChild->left = parent;
    parent->parent = rightChild;
}

void rebuildAfterInsert(Node** root, Node* X){
    while (X != (*root) && X->parent->color == RED)
    {
        if(X->parent == X->parent->parent->left){
            Node* uncle = X->parent->parent->right;
            if(uncle->color == RED){
                X->parent->color = BLACK;
                uncle->color = BLACK;
                X->parent->parent->color = RED;
                X = X->parent->parent;
            }
            else {
                if (X == X->parent->right){
                    X = X->parent;
                    rotateLeft(root, X);
                }
                X->parent->color = BLACK;
                X->parent->parent->color = RED;
                rotateRight(root, X->parent->parent);
            }
        }
        else{
            Node* uncle = X->parent->parent->left;
            if(uncle->color == RED){
                X->parent->color = BLACK;
                uncle->color = BLACK;
                X->parent->parent->color = RED;
                X = X->parent->parent;
            }
            else {
                if (X == X->parent->left){
                    X = X->parent;
                    rotateRight(root, X);
                }
                X->parent->color = BLACK;
                X->parent->color = BLACK;
                X->parent->parent->color = RED;
                rotateLeft(root, X->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

Node* removeNode(Node** root, element data){
    Node* removed = NULL;
    Node* successor = NULL;
    Node* target = searchNode((*root), data);
    if (target == NULL) return NULL;
    if (target->left == Nil || target->right == Nil) removed = target;
    else{
        removed = searchMinNode(target->right);
        target->data = removed->data;
    }
    if (removed->left != Nil) successor = removed->left;
    else successor = removed->right;

    successor->parent = removed->parent;
    if (removed->parent == NULL) (*root) = successor;
    else{
        if (removed == removed->parent->left) removed->parent->left = successor;
        else removed->parent->right = successor;
    }
    if (removed->color == BLACK) rebuildAfterRemove(root, successor);

    return removed;
}

void rebuildAfterRemove(Node** root, Node* successor){
    Node* sibling = NULL;
    while (successor->parent != NULL && successor->color == BLACK)
    {
        if(successor == successor->parent->left){
            sibling = successor->parent->right;
            if (sibling->color == RED){
                sibling->color = BLACK;
                successor->parent->color = RED;
                rotateLeft(root, successor->parent);
            }
            else {
                if(sibling->left->color == BLACK && sibling->right->color == BLACK){
                    sibling->color = RED;
                    successor = successor->parent;
                }
                else{
                    if (sibling->left->color == RED){
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rotateRight(root, sibling);
                        sibling = successor->parent->right;
                    }
                    sibling->color = successor->parent->color;
                    successor->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(root, successor->parent);
                    successor = *root;
                }
            }
        }
        else{
            sibling = successor->parent->left;
            if (sibling->color == RED){
                sibling->color = BLACK;
                successor->parent->color = RED;
                rotateRight(root, successor->parent);
            }
            else {
                if (sibling->right->color == RED){
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(root, sibling);
                    sibling = successor->parent->left;
                }
                else {
                    if (sibling->right->color == RED){
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(root, sibling);
                    sibling = successor->parent->left;
                    }
                    sibling->color = successor->parent->color;
                    successor->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rotateRight(root, successor->parent);
                    successor = *root;
                }
            }
        }
    }   
    successor->color = BLACK;
}