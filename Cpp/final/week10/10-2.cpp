#include <iostream>
using namespace std;

class Point
{
private:
    int m_x, m_y;
public:
    Point(int x=0, int y=0);
    void Get_XY(int &a, int &b);
    Point operator+(Point ob);
    Point operator=(Point ob);
};

Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Point::Get_XY(int &a, int &b)
{
    a = m_x;
    b = m_y;
}
Point Point::operator+(Point ob)
{
    Point temp;
    temp.m_x = this->m_x + ob.m_x;
    temp.m_y = this->m_y + ob.m_y;
    return temp;
}
    
Point Point::operator=(Point ob)
{
    this->m_x = ob.m_x;
    this->m_y = ob.m_y;
    return *this;
}

int main()
{
    Point ob1(7, 3), ob2(5, 8), ob3, ob4;
    int x, y;
    ob3 = ob1 + ob2;
    ob3.Get_XY(x, y);
    cout << "ob3 의 x 는 " << x << " y 는 " << y << "\n";

    ob4 = ob3 = ob2 = ob1;

    ob4.Get_XY(x,y);
    cout << "ob4 의 x 는 " << x << " y 는 " << y << "\n";

    return 0;
}