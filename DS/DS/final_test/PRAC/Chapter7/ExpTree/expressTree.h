#ifndef __EXPRESS_TREE_H__
#define __EXPRESS_TREE_H__
#include "binaryTree.h"
tNode* MakeExpTree(char exp[]);
int EvaluateExpTree(tNode* node);
void ShowNodeData(int data);
void ShowPrefixTypeExp(tNode* node);
void ShowInfixTypeExp(tNode* node);
void ShowPostfixTypeExp(tNode* node);

#endif