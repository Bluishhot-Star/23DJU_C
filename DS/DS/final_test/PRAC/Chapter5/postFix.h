#ifndef __POSTFIX__H__
#define __POSTFIX__H__
int GetOpPrec(char op);             // 우선순위 반환
int WhoPrecOp(char op1, char op2);  // 연산자 우선순위 조사
void ConvToRPNExp(char exp[]);      // 중위->후위
int EvalRPNExp(char exp[]);         // 후위 수식 연산
#endif