#include <iostream>
using namespace std;

void SwapPointer(int* &ref1, int* &ref2)
{
    int* temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(void)
{
    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;
    cout << *ptr1 << ' ' << *ptr2 << endl;
    SwapPointer(ptr1, ptr2);
    cout << *ptr1 << ' ' << *ptr2 << endl;
    return 0;
}