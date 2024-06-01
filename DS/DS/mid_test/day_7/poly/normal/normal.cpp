/* 
일반 차항식
*/
#include <stdio.h>
#include <stdlib.h>
#include "normal.h"

polynominal* addPolynominal(polynominal* polyA, polynominal* polyB)
{
    polynominal* polyC = (polynominal*)malloc(sizeof(polynominal));
    if (polyC != NULL)
    {
        polyC->degree = MAX(polyA->degree,polyB->degree);
        int A_index = 0, B_index = 0, C_index = 0;
        int A_degree = polyA->degree, B_degree = polyB->degree, C_degree = polyC->degree; //조사를 위한 지역변수
        while (A_index <= polyA->degree && B_index <= polyB->degree)
        {
            if (A_degree > B_degree) //A의 현재 차항이 더 높을 경우
            {
                polyC->coef[C_index++] = polyA->coef[A_index++]; //C의 현재 차항에 A의 현재 차항의 계수 넣기
                A_degree--; //다음 차항으로
            }
            else if (A_degree == B_degree) //A와 B가 현재 차항이 같을 경우
            {
                polyC->coef[C_index++] = polyA->coef[A_index++] + polyB->coef[B_index++]; //A와B의 계수 더하기
                A_degree--; //다음 차항으로
                B_degree--; 
            }
            else //B의 현재 차항이 A보다 더 높을 경우
            {
                polyC->coef[C_index++] = polyB->coef[B_index++]; //B의 계수 넣기
                B_degree--; //다음 차항으로
            }
        }
        
    }
    return polyC;
}
polynominal* createPolynominal(int degree, float coef[])
{
    polynominal* polyP = (polynominal*)malloc(sizeof(polynominal));
    if (polyP != NULL)
    {
        polyP->degree = degree;
        for (int i = polyP->degree; i >= 0 ; i--)
        {
            polyP->coef[i] = coef[i];
        }
    }
    return polyP;
}
void printPolynominal(polynominal* poly){
    if (poly != NULL)
    {
        printf("다항식 차수: %d\n", poly->degree);
        for (int i = poly->degree; i >= 0; i--)
        {
            printf("지수 x^%d의 계수 = %.2f\n", i, poly->coef[poly->degree-i]);
        }
    }
}

int main(){
    float coef_A[] = {4,3,5,0};
    float coef_B[] = {3, 1, 0, 2, 1};
    polynominal* polyA = createPolynominal(3, coef_A);
    polynominal* polyB = createPolynominal(4, coef_B);
    polynominal* polyC = addPolynominal(polyA, polyB);
    printPolynominal(polyC);

    free(polyA);
    free(polyB);
    free(polyC);
    return 0;
}