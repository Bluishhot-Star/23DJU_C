#include <stdio.h>
#include <math.h>

#define funct(x) (x*x*x - x - 1.344)

int main(){
    double a, b, xc, fa, fb, fc, epsilon;
    int imax, iter;

    epsilon = 0.0001;
    imax = 1000;
    printf("---(할선법)---\n");

    printf("\n좌측 경계값 : a = ");
    scanf("%lf", &a);
    
    printf("\n우측 경계값 : b = ");
    scanf("%lf", &b);

    printf("\n a, b, epsilon, imax : %f %f %f %d\n", a, b, epsilon, imax);

    fa = funct(a);
    fb = funct(b);

    if (fabs(fa) <= epsilon)
    {
        printf("\n a가 근입니다 ");
        goto END;
    }
    if (fabs(fb) <= epsilon)
    {
        printf("\n b가 근입니다 ");
        goto END;
    }

    for (iter = 1; iter < imax; ++iter)
    {
        xc = b-(fb*(a-b))/(fa-fb);
        fc = funct(xc);
        printf("\n xc   f(xc) : %f\t%f",xc, fc);
        if (fabs(fc) <= epsilon)
        {
            printf("\n 근 xc = %f\n", xc);
            goto END;
        }
        a = b;
        b = xc;
        fa = fb;
        fb = fc;
        printf("\t수렴하지 않음");
    }
    END:;
    return 0;
}