#include <stdio.h>
#include <stdlib.h>
#include "PolyLinkedList.h"

int main()
{
    listhead* A = createLinkedList();
    listhead* B = createLinkedList();
    // appendTerm(A, 4, 3);    appendTerm(A, 3, 2);
    // appendTerm(A, 5, 1);    printPoly(A);

    insertTerm(A, 5, 1);
    insertTerm(A, 4, 3);
    insertTerm(A, 3, 2);
    insertTerm(A, 6, 2); 
    printPoly(A);

    // appendTerm(B, 3, 4);    appendTerm(B, 1, 3);
    // appendTerm(B, 2, 1);    appendTerm(B, 1, 0);    printPoly(B);
    
    insertTerm(B, 2, 1);
    insertTerm(B, 1, 0);
    insertTerm(B, 3, 4);
    insertTerm(B, 1, 3);
    printPoly(B);

    listhead* C = addPoly(A, B);    printPoly(C);

    ReleaseList(A);
    ReleaseList(B);
    ReleaseList(C);
    return 0;
}