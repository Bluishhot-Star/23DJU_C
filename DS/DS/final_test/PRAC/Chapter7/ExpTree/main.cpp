#include <stdio.h>
#include "expressTree.h"

int main()
{
    char exp[] = "12+7*";
    tNode* eTree = MakeExpTree(exp);

    printf("전위 표기법의 수식\n");
    ShowPrefixTypeExp(eTree); printf("\n");
    printf("중위 표기법의 수식\n");
    ShowInfixTypeExp(eTree); printf("\n");
    printf("후위 표기법의 수식\n");
    ShowPostfixTypeExp(eTree); printf("\n");

    printf("연산 결과: %d \n", EvaluateExpTree(eTree));
    return 0;
}