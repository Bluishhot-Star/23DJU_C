#include <iostream>
using namespace std;
class Box
{
private:
    int m_x, m_y, m_z;
public:
    void Set_Box(int x, int y, int z);
    void Print_Box();
    int Compute_Volume();
    void Compare_Volume(Box b);
};

void Box::Set_Box(int x, int y, int z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

void Box::Compare_Volume(Box b)
{
    int v1 = m_x * m_y * m_z;
    int v2 = b.m_x * b.m_y * b.m_z;

    if (v1 > v2)
    {
        cout << v1 << " 부피가 " << v2 << " 부피보다 큽니다." << endl;
    }
    else if (v2 > v1)
    {
        cout << v1 << " 부피가 " << v2 << " 부피보다 작습니다." << endl;
    }
    else
    {
        cout << v1 << " 부피와 " << v2 << " 부피는 같습니다." << endl;
    }
}

void Box::Print_Box(){
    cout << "(" << m_x << ", " << m_y << ", " << m_z << ")";
}

int Box::Compute_Volume(){
    return m_x*m_y*m_z;
}

int main(){
    Box b1, b2;
    b1.Set_Box(5, 6, 7);
    b2.Set_Box(4, 7, 8);

    cout << "Box b1의 좌표는 ";
    b1.Print_Box();
    cout << " 부피는 " << b1.Compute_Volume() << "입니다." << endl;
    
    cout << "Box b2의 좌표는 ";
    b2.Print_Box();
    cout << " 부피는 " << b2.Compute_Volume() << "입니다.\n" << endl;

    b1.Compare_Volume(b2);
    b1.Compare_Volume(b1);

    return 0;
}