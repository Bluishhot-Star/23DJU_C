#pragma once
#define MAX(a, b) ((a>b) ? a : b)
#define MAX_DEGREE 100

typedef struct SPolyTerm{
    int expo;
    int coef;
}sPolyTerm;

typedef struct SPoly
{
    int count;
    sPolyTerm term[MAX_DEGREE];
}sPoly;

SPoly* createPoly(int cnt, sPolyTerm item[]);
SPoly* addPoly(SPoly* polyA, SPoly* polyB);
void printSPoly(SPoly* poly);
