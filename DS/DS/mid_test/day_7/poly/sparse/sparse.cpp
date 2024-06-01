/* 
희소 차항식
*/
#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"

SPoly* createPoly(int cnt, sPolyTerm item[]){
    SPoly* sparse = (SPoly*)malloc(sizeof(SPoly));
    sparse->count = cnt;
    for (int i = 0; i < sparse->count; i++)
    {
        sparse->term[i].expo = item[i].expo;
        sparse->term[i].coef = item[i].coef;
    }
    return sparse;
}
SPoly* addPoly(SPoly* polyA, SPoly* polyB){
    SPoly* polyC = (SPoly*)malloc(sizeof(SPoly));
    int index_A=0, index_B=0, index_C = 0; //0번째 칸
    while (index_A != polyA->count && index_B != polyB->count)
    {
        if (polyA->term[index_A].expo > polyB->term[index_B].expo)
        {
            polyC->term[index_C].expo = polyA->term[index_A].expo;
            polyC->term[index_C++].coef = polyA->term[index_A++].coef;
        }
        else if (polyA->term[index_A].expo < polyB->term[index_B].expo)
        {
            polyC->term[index_C].expo = polyB->term[index_B].expo;
            polyC->term[index_C++].coef = polyB->term[index_B++].coef;
        }
        else if (polyA->term[index_A].expo == polyB->term[index_B].expo)
        {
            polyC->term[index_C].expo = polyA->term[index_A].expo;
            polyC->term[index_C++].coef = polyA->term[index_A++].coef + polyB->term[index_B++].coef;
        }
    }
    polyC->count = index_C;
    return polyC;
}
void printSPoly(SPoly* poly){
    if (poly != NULL)
    {
        for (int i=0; i < poly->count; i++)
        {
            printf("지수 x^%d의 계수 = %d\n", poly->term[i].expo, poly->term[i].coef);
        }
    }
}


int main(){
    SPolyTerm itemA[] = {{1000,2}, {1,5}}; // 2x^1000 + 5x
    SPolyTerm itemB[] = {{10,2}, {1,5}}; // 2x^10 + 5x

    SPoly* SA = createPoly(2, itemA);
    SPoly* SB = createPoly(2, itemB);
    SPoly* SC = addPoly(SA,SB);

    printSPoly(SA);
    printf("\n\n\n");
    printSPoly(SB);
    printf("\n\n\n");
    printSPoly(SC);



    free(SA);        
    free(SB);
    free(SC);

    return 0;
}