#include <stdio.h>
#include "partialList.h"

int main(){
    int A[] = {8,7,2,1,0,9,6,11,13,12,34,56,112,115};
    int length = sizeof(A) / sizeof(A[0]);
    printf("Unsorted Array\n");
    printList(A, length);  getchar();

    // perform InsertionSort on A
    printf("Sorted list by insertionSort\n");
    InsertionSort(A, length);
    printList(A, length);   getchar();

    int B[] = {8,7,2,1,0,9,6,11,13,12,34,56,112,115};
    // perform quickSort on B

    printf("Sorted list by quickSort\n");
    quickSort(B, 0, length -1);
    printList(B, length);   getchar();

    int C[] =  {8,7,2,1,0,9,6,11,13,12,34,56,112,115};
    // perform mergeSort on C
    printf("Sorted list by mergeSort\n");
    mergeSort(C, 0, length-1);
    printList(C, length);   getchar();

    // int D[] = {8,7,2,1,0,9,6,11,13,12,34,56,112,115};
    int D[] = {10, 4, 5, 8, 6, 11, 26, 1, 2, 3, 15, 25, 30};
    // perform heapSort on D
    printf("Sorted list by heapSort\n");
    heapSort(D, length-1);
    printList(D, length);   getchar();


}
