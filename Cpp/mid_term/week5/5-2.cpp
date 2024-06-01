#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
private:
    double m_x, m_y;
public:
    Vector( );
    Vector(double x, double y);
    double Get_Magnitude();
};

Vector::Vector()
{
    m_x = 1.0;
    m_y = 2.0;
}

Vector::Vector(double x, double y)
{
    m_x = x;
    m_y = y;
}

double Vector::Get_Magnitude()
{
    return sqrt(m_x*m_x + m_y*m_y);
}

int main()
{
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);

    Vector *p1, *p2;
    p1 = new Vector;
    p2 = new Vector(2.0,3.0);

    if (!p1 && !p2)
    {
        cout << "동적 메모리 할당 에러\n";
        return 1;
    }

    cout << "p1의 벡터의 크기는 : " << p1->Get_Magnitude() << "\n";
    cout << "p2의 벡터의 크기는 : " << p2->Get_Magnitude() << "\n";

    Vector ob1;
    Vector ob2(3.0, 4.0);
    cout << "ob1의 벡터의 크기는 : " << ob1.Get_Magnitude() << "\n";
    cout << "ob2의 벡터의 크기는 : " << ob2.Get_Magnitude() << "\n";
    
    Vector ob3[3] = {Vector(2.0,1.0), Vector(3.0,2.0), Vector(4.0,3.0) };

    for (int i = 0; i < 3; i++)
    {
        cout << "ob3[" << i <<"]의 벡터의 크기는 : " << ob3[i].Get_Magnitude() << "\n";

    }
    delete p1;
    delete p2;

    return 0;   
}