#include <iostream>
using namespace std;

void plusOne(int &ref)
{
    ref += 1;
}

void signChg(int &ref)
{
    ref *= -1;
}

int main(void)
{
    int a = 2;
    plusOne(a);
    cout << a << endl;
    signChg(a);
    cout << a << endl;
    
    return 0;
}