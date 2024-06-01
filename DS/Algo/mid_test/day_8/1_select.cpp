#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int l, int r){
    int x = arr[r], i=l;
    for (int j = l; j <= r-1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k){
    if (k > 0 && k <= r - l + 1)
    {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
        {
            return arr[index];
        }
        if (index - l > k -1)
        {
            return kthSmallest(arr, l, index - 1, k);
        }
        return kthSmallest(arr, index + 1, r, k - index + l -1 );
    }
    return INT_MAX;
}
void insertionSort(int A[], int n){
    int i = 0, j = 0;
    int temp = 0;

    for (  i = 1; i < n; i++)
    {
        if (A[i-1] <= A[i])
            continue;
        temp = A[i];

        for (j = 0; j < i; j++)
        {
            if(A[j] > temp){
                memmove(&A[j+1], &A[j], sizeof(A[0])*(i-j));
                A[j] = temp;
                break;
            }
        }   
    }
}
int main(){
    int arr[] = {10, 4, 5, 8, 6, 11, 26, 1, 2, 3, 15, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
    int k = 7;
    printf("\nK(%d)th smallest element is %d\n", k, kthSmallest(arr, 0, n-1, k));
}