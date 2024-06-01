
// C++ program to demonstrate performance of
// C qsort and C++ sort() algorithm
#include <time.h>
#include <iostream>
#include <algorithm>
#include <bitstring.h>
using namespace std;

// Number of elements to be sorted
#define N 100000

// A comparator function used by qsort
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Driver program to test above functions
int main()
{
    int arr[N], arr1[N*10];

    // seed for random input
    srand((unsigned int)time(NULL));

    // to measure time taken by qsort and sort
    clock_t begin, end;
    double time_spent;

    // generate random input
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100000;
    for (int i = 0; i < N*10; i++)
            arr1[i] = rand() % 100000;
    begin = clock();
    qsort(arr, N, sizeof(int), compare);
    end = clock();

    // calculate time taken by C qsort function
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "Time taken by C qsort() - "
        << time_spent << endl;

    time_spent = 0.0;

    begin = clock();
    qsort(arr1, N, sizeof(int), compare);
    end = clock();

    // calculate time taken by C++ sort
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    cout << "Time taken by C++ sort() - "
        << time_spent << endl;

    return 0;
}