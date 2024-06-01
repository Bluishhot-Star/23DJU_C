#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct
{
    int heap[MAX_ELEMENT];
    int heap_size;
}heapType;

heapType* createHeap(){
    heapType *h = (heapType*)malloc(sizeof(heapType));
    h->heap_size = 0;
    return h;
}

void insertHeap(heapType *h, int item){
    int i;
    h->heap_size = h->heap_size + 1;
    i = h->heap_size; // 밑부터 비교시작
    while ((i != 1) && (item > h->heap[i/2])){ // 첫번째 항이 아니고 부모노드값보다 item이 더 큰 경우
        h->heap[i] = h->heap[i / 2]; // 부모노드를 아래로 이동
        i /= 2;
    }
    h->heap[i] = item;
}

int deleteHeap(heapType* h){
    int parent, child;
    int item, temp;
    item = h->heap[1]; // 1번 노드
    temp = h->heap[h->heap_size]; // 현재 마지막 노드
    h->heap_size = h->heap_size - 1; // 사이즈-1
    parent = 1; //루트
    child = 2; //자식 노드부터
    while (child <= h->heap_size) // 2번 자리부터 비교 (마지막 노드까지
    {
        if ((child < h->heap_size) && (h->heap[child] < h->heap[child+1])) //현재 노드의 자식 노드 중 더 큰 것 고르기 (왼쪽 vs 오른쪽)
            child++; //오른쪽이 더 크면 해당 노드 가리키기 (인덱스 1 증가)
        if (temp >= h->heap[child]) break; //마지막 노드가 현재 인덱스(가리키고 있는 둘 중 더 큰 자식노드)보다 크거나 같다면 반복 종료(가장 큰 값 찾음)
        else { //마지막 노드가 현재 인덱스보다 더 작으면
            h->heap[parent] = h->heap[child]; //부모노드와 자식노드 CHG'
            parent = child; // 그 다음 자식 노드 조사
            child = child * 2;
        }
    }
    h->heap[parent] = temp;
    return item;
}

void printHeap(heapType* h){
    int i;
    printf("Heap : ");
    for ( i = 1; i <= h->heap_size; i++)
    {
        printf("[%d] ", h->heap[i]);
    }
}

int main(){
    int i, n, item;
    heapType* heap = createHeap();
    insertHeap(heap, 10);
    insertHeap(heap, 45);
    insertHeap(heap, 19);
    insertHeap(heap, 11);
    insertHeap(heap, 96);

    printHeap(heap);

    n = heap->heap_size;
    for (int i = 1; i <= n; i++)
    {
        item = deleteHeap(heap);
        printf("\n delete : [%d] ", item);
        printHeap(heap);
    }
    
    getchar();
    return 0;
}