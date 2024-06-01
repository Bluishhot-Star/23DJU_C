#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "linkedStack.h"
#include "postFix.h"
// Basic Concept
/*
    1. 피연산자는 바로 옮김
    2. 연산자는 스택 push
    3. 연산자 우선순위 존재 :
        - 우선순위 높은 것이 스택의 top에 위치하도록
        - 우선순위 낮은 것 등장 시 스택 원소 모두 pop, 이후 새로운 연산자 push
        - '(' 는 ')' 등장까지 스택에 존재해야하므로 우선순위 최하위 간주
        - ')' 연산자는 pop 신호로 간주
*/
int GetOpPrec(char op)
{
    switch (op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    
    default:
        return -1;
    }
}
int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec) return 1; // 좌 우위
    else if (op1Prec < op2Prec) return -1; //우 우위
    else return 0; // 동일
}

void ConvToRPNExp(char exp[])
{
    int expLen = strlen(exp);
    int idx = 0;
    char tok, popOp = '\0';
    char* convExp = (char*)malloc(sizeof(char)*(expLen+1)); // 입력받은 수식 담을 공간 할당
    memset(convExp, 0, expLen+1); // 해당 공간 0으로 쵸기화
    Stack* S = createStack(); // 연산자 스택
    for (int i = 0; i < expLen; i++)
    {
        tok = exp[i];
        if (isdigit(tok)) // 숫자는 바로 옮기기
        {
            convExp[idx++] = tok;
        }
        else // 연산자일 경우
        {
            switch (tok)
            {
            case '(':
                SPush(S, tok);
                break;
            case ')':
                while (1)
                {
                    popOp = SPop(S);
                    if(popOp == '(') // '(' 등장까지 모두 빼내기
                        break;
                    convExp[idx++] = popOp; //빼낸 연산자 push
                }
                break;
            case '+': case '-':
            case '*': case '/':
                while (!IsStackEmpty(S) && WhoPrecOp(SPeek(S),tok) >= 0) //현재 연산자가 top보다 우선순위 낮거나 동일하면 모두 빼내기
                    convExp[idx++] = SPop(S);
                SPush(S, tok);
                break;
            default:
                break;
            }
        }
    }
    while (!IsStackEmpty(S))    
        convExp[idx++] = SPop(S);
    
    strcpy(exp, convExp);
    free(convExp);
}
int EvalRPNExp(char exp[])
{
    Stack* S = createStack();
    int expLen = strlen(exp);
    char tok, op1, op2;
    for (int i = 0; i < expLen; i++)
    {
        tok = exp[i];
        if(isdigit(tok))
        {
            SPush(S, tok-'0'); // '0'을 빼면 문자형 숫자를 정수로 바꿀 수 있음
        }
        else{
            op2 = SPop(S);
            op1 = SPop(S);
            switch (tok)
            {
            case '+':
                SPush(S, op1 + op2);
                break;
            case '-':
                SPush(S, op1 - op2);
                break;
            case '*':
                SPush(S, op1 * op2);
                break;
            case '/':
                SPush(S, op1 / op2);
                break;
            default:
                break;
            }
        }
    }
    return SPop(S);
}
