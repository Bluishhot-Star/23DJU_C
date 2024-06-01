#include <stdio.h>
#include <string.h>

void InsertionSort(int A[] ,int n){
    int i = 0, j = 0;
    int temp = 0;

    for (i = 1; i < n; i++)
    {
        if (A[i-1] <= A[i])
            continue;
        temp = A[i];
        for ( j = 0; j < i; j++)
        {
            if (A[j] > temp)
            {
                memmove(&A[j+1], &A[j], sizeof(A[0])*(i-j));
                A[j] = temp;
                break;
            }
        }
    }
}
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high]; // pivot 설정 : 가장 오른쪽 끝
    int i = (low -1); // p보다 작은 구역 끝지점
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot) // p보다 작은 원소
        {
            i++; // 구역 확장
            swap(&arr[i], &arr[j]); // 교체하기
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
    
}
void merge(int arr[], int i1, int j1, int i2, int j2){
    int temp[50] = {0};
    int i, j, k;
    i = i1;
    j = i2;
    k=0;
    while (i <= j1 && j <= j2)
    {
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while (i <= j1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= j2)
    {
        temp[k++] = arr[j++];
    }
    for ( i = i1,j=0; i <= j2; i++, j++)
    {
        arr[i] = temp[j];
    }
    

}
void mergeSort(int arr[], int i, int j){
    int mid;
    if (i < j)
    {
        mid = (i+j)/2;
        mergeSort(arr, i, mid);
        mergeSort(arr, mid + 1, j);
        merge(arr, i, mid, mid + 1, j);
    }
}

int val;
void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;
    if (largest != i)
    {
        val = arr[i];
        arr[i] = arr[largest];
        arr[largest] = val;
        heapify(arr, size, largest);
    }
}
void heapSort(int arr[], int size){
    int i;
    for (i = (size/2)-1; i >= 0; i--)
        heapify(arr, size, i);
    for (i = size-1; i >=0; i--)
    {
        val = arr[0];
        arr[0] = arr[i];
        arr[i] = val;
        heapify(arr, i , 0);
    }
}
void printList(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", A[i]);
    }
    printf("\n");
}