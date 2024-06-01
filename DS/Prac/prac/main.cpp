#include <stdio.h>
#include <iostream>
#include <time.h>
#include "tArr.h"

int main() {
    tArr newArr = {};
    InitializeArr(&newArr);

    srand(time(nullptr));

    for (int i = 0; i < 10; i++)
    {
        int iRand = rand() % 100 +1;
        PushData(&newArr,iRand);
    }
    printf("\n정렬 전\n");
    for (int i = 0; i < newArr.iCount; i++)
    {
        printf("%d\n",newArr.iptr[i]);
    }
    printf("\n");
    printf("정렬 후\n");

    Bubble(&newArr);
    for (int i = 0; i < newArr.iCount; i++)
    {
        printf("%d\n",newArr.iptr[i]);
    }
    ReleaseArr(&newArr);
    return 0;
}