#include <iostream>
#include "linkedList.h"

int main(){
    tLinkedList newList = {};
    InitList(&newList);

    PushFront(&newList, 10);
    PushBack(&newList, 100);
    PushBack(&newList, 200);
    PushBack(&newList, 300);

    PushFront(&newList, 400);
    PushFront(&newList, 500);
    PushFront(&newList, 600);



    ReleaseList(&newList);
    return 0;
}