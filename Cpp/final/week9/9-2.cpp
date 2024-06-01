#include <iostream>
#include <math.h>
using namespace std;

class Point
{
private:
    int m_x, m_y;
public:
    Point(int x = 2, int y = 0);
    void SetX(int x);
    void SetY(int x);
    void Print_Point(string pnt);
    int GetX() {return m_x;}
    int GetY() {return m_y;}
    double Length();
};

Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Point::SetX(int x)
{
    m_x = x;
}
void Point::SetY(int y)
{
    m_y = y;
}

void Point::Print_Point(string pnt)
{
    cout << pnt << " = (" << m_x << ", " << m_y << ')' << endl;
}
double Point::Length()
{
    return sqrt(double(m_x*m_x + m_y*m_y));
}

int main()
{
    Point p1;
    Point p2(5,2);
    Point p3(-3,7);
    cout << "p3.x = " << p3.GetX() << endl;
    cout << "p3.y = " << p3.GetY() << endl;
    cout << "p3 Length= " << p3.Length() << endl;

    p1.SetX(6);
    p1.Print_Point("점 p1");
    cout << "p1 Length = " << p1.Length() << endl;

    p3.SetY(4);
    p3.Print_Point("점 p3");
    cout << "p3 Length = " << p3.Length() << endl;
    
    p2.Print_Point("점 p2");
    cout << "p2 Length = " << p2.Length() << endl;
    
    return 0;
}
