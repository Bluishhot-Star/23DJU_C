#include <stdio.h>
#include <stdlib.h>
#include "GoodHeap.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}

int main()
{
    Heap* H = createHeap(DataPriorityComp);

    HInsert(H, 'A');
    HInsert(H, 'B');
    HInsert(H, 'C');
    HInsert(H, 'A');
    HInsert(H, 'B');
    HInsert(H, 'C');
    while (!HisEmpty(H))
    {
        printf("%c \n", HDelete(H));
    }
    

    return 0;
}