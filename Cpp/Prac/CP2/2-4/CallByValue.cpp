#include <iostream>
using namespace std;
int* SimpleFunc(int* ptr) //Call by Value
{
    return ptr+1; // 단지 값을 더한 것일 뿐.
}

int SimpleFunc(int* ptr)
{
    if(ptr == nullptr)
    {
        return NULL;
    }
    *ptr = 20;
    return prt;
}

int main()
{
    int a[10] = {1,2,3,4,5};
    int* ptr = a;
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << (SimpleFunc(ptr)) << endl;
    return 0;
}