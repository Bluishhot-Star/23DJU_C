#include <iostream>
using namespace std;

class base
{
private:
    int i,j;
public:
    base(int a, int b)
    {
        i = a;
        j = b;
    }
    void Print_ij() {cout << i << ' ' << j << endl;}
};
class derived : public base
{
private:
    int k;
public:
    derived(int a, int b, int c) : base(a, b)
    {
        k = c;
    }
    void Print_ijk() {cout << k << ' '; Print_ij();}
};


int main(void)
{
   derived ob(1,2,3);
   ob.Print_ijk();
    return 0;
}