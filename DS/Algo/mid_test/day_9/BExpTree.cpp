#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element;
typedef struct BinaryExpressionTreeNode
{
    element data;
    struct BinaryExpressionTreeNode* left;
    struct BinaryExpressionTreeNode* right;
} Node;
Node* createNode(element data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;  node->left = NULL; node->right = NULL;
    return node;
}

void printTree_preOrder(Node* node){
    if(!node)return;
    printf(" %c ", node->data);
    printTree_preOrder(node->left);
    printTree_preOrder(node->right);
}
void printTree_inOrder(Node* node){
    if(!node)return;
    printTree_inOrder(node->left);
    printf(" %c ", node->data);
    printTree_inOrder(node->right);
}
void printTree_postOrder(Node* node){
    if(!node)return;
    printTree_postOrder(node->left);
    printTree_postOrder(node->right);
    printf(" %c ", node->data);
}
void buildExpressionTree(char* postFixExpression, Node** node){
    size_t length = strlen(postFixExpression);
    char token = postFixExpression[length - 1];
    postFixExpression[length - 1] = '\0';
    switch (token){
    case '+':case '-':case '*':case '/':
        *node = createNode(token);
        buildExpressionTree(postFixExpression, &(*node)->right);
        buildExpressionTree(postFixExpression, &(*node)->left);
        break;
    default:
        *node = createNode(token);
        break;
    }
}
double evaluateExpression(Node* tree){
    char temp[2];
    double left = 0;    double right = 0;   double result = 0;
    if(!tree) return 0;
    switch(tree->data){
        case '+':case '-':case '*':case '/':
        left = evaluateExpression(tree->left);
        right = evaluateExpression(tree->right);
        if(tree->data == '+') result = left + right;
        else if(tree->data == '-')result = left - right;
        else if(tree->data == '*')result = left * right;
        else if(tree->data == '/')result = left / right;
        break;
    default:
        memset(temp, 0, sizeof(temp));
        temp[0] = tree->data;
        result = atof(temp);
        break;
    }
    return result;
}

int main(){
    Node* root = NULL;
    char postFixedExpression[] = "71*52-/";
    buildExpressionTree(postFixedExpression, &root);
    printf("preOrder: "); printTree_preOrder(root); printf("\n");
    printf("inOrder: "); printTree_inOrder(root); printf("\n");
    printf("postOrder: "); printTree_postOrder(root); printf("\n");
    printf("수식트리 값: %f\n",evaluateExpression(root));
    
    return 0;
}