#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    int m_x, m_y;
    double Length()
    {
        return (sqrt(double(m_x*m_x + m_y*m_y)));
    }
public:
    Point(int x, int y)
    {
        m_x = x;
        m_y = y;
    }
    void Print_Point();
    friend void Print_Me(Point &p);
};

void Point::Print_Point()
{
    cout << "객체 멤버함수로 (" << m_x << ',' << m_y << ')' <<
    "   Length = " << Length() << endl;
}

void Print_Me(Point &p)
{
    cout << "프렌드 함수로 (" << p.m_x << ',' << p.m_y << ')' <<
    "   Length = " << p.Length() << endl;
}

int main()
{
    Point obj(6,8);
    obj.Print_Point();
    Print_Me(obj);
    return 0;
}