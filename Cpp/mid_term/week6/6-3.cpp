#include <iostream>
using namespace std;

class SafeArray
{
private:
    int *p;
    int m_size;
public:
    SafeArray(int size);
    ~SafeArray();
    SafeArray(const SafeArray &a);
    void Put(int i, int j);
    int Get(int i);
};

SafeArray::SafeArray(int size)
{
    p = new int[size];
    m_size = size;
    cout << "인수 있는 생성자 호출\n";
}

SafeArray::~SafeArray()
{
    delete[]p;
}
SafeArray::SafeArray(const SafeArray &ob)
{
    p = new int[ob.m_size];

    for (int i = 0; i < ob.m_size; i++)
    {
        p[i] = *(ob.p+i);
    }
    cout << "복사 생성자 호출\n";
    
}

void SafeArray::Put(int i, int j)
{
    if (i >= 0 && i < m_size)
    {
        p[i] = j;
    }
    
}
int SafeArray::Get(int i)
{
    return p[i];
}

int main(void)
{
    SafeArray num(10);

    for (int i = 0; i < 10; i++)
    {
       num.Put(i, i);
    }
    for (int i = 9; i >= 0; i--)
    {
        cout << num.Get(i) << ' ';
    }
    
    cout << '\n';

    SafeArray copy = num;

    for (int i = 0; i < 10; i++)
    {
        cout << copy.Get(i) << ' ';
    }
    cout << "\n";

    return 0;
}