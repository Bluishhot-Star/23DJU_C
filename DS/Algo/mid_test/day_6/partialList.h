#ifndef PARTIAL_LIST_H
#define PARTIAL_LIST_H

// 삽입정렬
void InsertionSort(int A[] ,int size);
// swap
void swap(int* a, int* b);
// 
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void merge(int arr[], int i1, int j1, int i2, int j2);
void mergeSort(int arr[], int i, int j);
void heapify(int arr[], int size, int i);
void heapSort(int arr[], int size);
void printList(int A[], int n);

#endif