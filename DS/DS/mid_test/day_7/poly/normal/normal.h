#pragma once
#define MAX(a, b) ((a>b) ? a : b)
#define MAX_DEGREE 100

typedef struct Polynominal
{
    int degree;
    float coef[MAX_DEGREE];
}polynominal;

polynominal* createPolynominal(int degree, float coef[]);
polynominal* addPolynominal(polynominal* polyA, polynominal* polyB);
void printPolynominal(polynominal* poly);
