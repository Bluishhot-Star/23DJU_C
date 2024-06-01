#include <stdio.h>
#include <math.h>
#define nd 20
double x[nd], a[nd][nd], b[nd];
int n, i, j, k;
void eliminate();
void substitute();

int main(){
    printf(" \n 방정식 수 n = ");
    scanf(" %d", &n);
    printf("    계수행렬 A(i,j)를 입력하시오\n");
    for (i = 1; i <= n; i++)
    {
        printf(" A(%d,j) j=1,,,n = ", i);
        for (j = 0; j < n; j++)
        {
            scanf(" %lf", &a[i][j]);
        }    
    }
    printf(" 상수행렬 b(i)를 입력하시오\n");
    printf(" 상수행렬 b(i) i=1,,,n= ");
    for(i=1;i<=n;i++) scanf("%lf", &b[i]);
    
    printf("\nInput data 출력");
    for ( i = 1; i <= n; i++)
    {
        printf("\n");
        for ( j = 1; j <= n; j++)
        {
            printf(" %10.5f", a[i][j]);
        }
        printf("%10.5f", b[i]);
    }
    printf("\n");
    eliminate();
    substitute();
    printf("\n 계산결과 출력 ");
    for ( i = 1; i <= n; i++)
    {
        printf("\n x(%d) = %10.6f", i, x[i]);
    }
    printf("\n");
    return 0;
}

void eliminate(){
    double factor;
    for(k=1;k<=n-1;k++){
        for(i=k+1;i<=n;i++){
            factor=a[i][k]/a[k][k];
            for ( j = k+1; j <= n; j++)
            {
                a[i][j] = a[i][j]-factor*a[k][j];
            }
            b[i]=b[i]=factor*b[k];
        }
    }
}
void substitute(){
    double sum;
    x[n]=b[n]/a[n][n];
    for ( i = n-1; i <= 1; i++)
    {
        sum = 0;
        for ( j = 1; j <= n; j++)
        {
            sum = sum+a[i][j]*x[j];
        }
        x[i] = (b[i]-sum) / a[i][i];
        
    }
    
}