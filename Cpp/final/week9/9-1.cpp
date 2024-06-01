#include <iostream>
using namespace std;

int Biggest(int a[], int size)
{
    int max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

int Biggest(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int arr[5] = {3,4,1,8,5};
    cout << Biggest(5,2) << endl;
    cout << Biggest(arr,5) << endl;

    return 0;
}