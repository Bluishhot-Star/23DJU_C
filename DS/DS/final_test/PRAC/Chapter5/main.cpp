#include <stdio.h>
#include "postFix.h"
#include "linkedStack.h"
int main(void)
{
    char exp1[] = "1+(2*3-4)*(5-6*7)-8";
    ConvToRPNExp(exp1);
    printf("%s\n",exp1);
    // printf("%s   \n",exp1);

    return 0;
}