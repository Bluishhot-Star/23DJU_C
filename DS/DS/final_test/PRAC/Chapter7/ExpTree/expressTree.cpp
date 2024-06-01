#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include "binaryTree.h" 
#include "linkedStack.h"

tNode* MakeExpTree(char exp[])
{
    Stack* S = createStack();
    tNode* pNode;

    int expLen = strlen(exp);
    for (int i = 0; i < expLen; i++)
    {
        pNode = createNode();

        if (isdigit(exp[i]))
        {
            SetData(pNode, exp[i]-'0');
        }
        else
        {
            SetData(pNode, exp[i]);
            MakeRightSubTree(pNode, SPop(S));
            MakeLeftSubTree(pNode, SPop(S));
        }
        SPush(S, pNode);
    }
    return SPop(S);
}

int EvaluateExpTree(tNode* node)
{
    int op1, op2;

    if(GetLeftSubTree(node)==NULL&&GetRightSubTree(node)==NULL) return GetData(node);

    op1 = EvaluateExpTree(GetLeftSubTree(node));
    op2 = EvaluateExpTree(GetRightSubTree(node));

    switch (GetData(node))
    {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;    
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    }
    return 0;
}

void ShowNodeData(char data)
{
    if (0<=data && data<=9)
    {
        printf("%d ",data);
    }
    else printf("%c ", data);
}

void ShowPrefixTypeExp(tNode* node)
{
    PreTrav(node, ShowNodeData);
}
void ShowInfixTypeExp(tNode* node)
{
    if (node == NULL) return;
    if(node->left != NULL || node->right != NULL) printf(" ( "); // 연산자 등장 시 '('
    ShowInfixTypeExp(node->left);
    ShowNodeData(node->data);
    ShowInfixTypeExp(node->right);
    if (node->left != NULL || node->right != NULL) printf(" ) "); // 피연산자 모두 등장 후 ')'

}
void ShowPostfixTypeExp(tNode* node)
{
    PostTrav(node, ShowNodeData);
}
