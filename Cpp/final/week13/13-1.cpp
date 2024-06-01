#include <iostream>
using namespace std;

template <class T1, class T2>
void MyCopy(T1 src[], T2 dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = (T2)src[i];
    }
    
}

int main(void)
{
    int x[] = {1,3,5,7,9};
    double d[5];
    char c1[5] = {'A','p', 'p','l','e'}, c2[5];

    MyCopy(x,d, 5);
    MyCopy(c1,c2, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << d[i] << ' ';
    }
    cout<< endl;
    for (int i = 0; i < 5; i++)
    {
        cout << c2[i] << ' ';
    }
    cout<< endl;
    return 0;
}