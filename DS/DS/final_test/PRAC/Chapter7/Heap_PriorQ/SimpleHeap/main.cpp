#include <stdio.h>
#include <stdlib.h>
#include "SimpleHeap.h"

int main()
{
    Heap* H = createHeap();
    HInsert(H,'C',3);
    HInsert(H,'B',2);
    HInsert(H,'A',1);
    HInsert(H,'C',3);
    HInsert(H,'B',2);
    HInsert(H,'A',1);
    while (!HisEmpty(H))
    {
        printf("%c", HDelete(H)); printf("\n");
    }
    


    return 0;
}