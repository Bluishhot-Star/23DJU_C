#include <iostream>
using namespace std;

class myClass
{
private:
    static int m_data;
public:
    void Set_Data(int n){m_data = n;}
    int Get_Data() {return m_data;}
};
int myClass::m_data;
int main()
{
    myClass ob1, ob2;
    ob1.Set_Data(100);
    ob2.Set_Data(200);

    cout << "ob1의 m_data 값은 " << ob1.Get_Data() << endl;
    cout << "ob2의 m_data 값은 " << ob2.Get_Data() << endl;
    return 0;
}