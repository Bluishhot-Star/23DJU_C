#include <iostream>
#include <math.h>
using namespace std;

class Coord
{
private:
    int m_x, m_y;
public:
    Coord(int x=0, int y=0)
    {
        m_x = x;
        m_y = y;
    }
    int GetX() {return m_x;}
    int GetY() {return m_y;}
    double Length();
    void Print_Point(string pnt);

    Coord operator-();
    Coord operator*(int k);
    double operator^(Coord &p);
};

double Coord::Length()
{
    return sqrt(double(m_x*m_x + m_y*m_y));
}

void Coord::Print_Point(string pnt)
{
    cout << pnt << "= (" << m_x << ", " << m_y << ')' << endl;
}

Coord Coord::operator*(int k)
{
    Coord temp;
    temp.m_x = this->m_x * k;
    temp.m_y = this->m_y * k;
    return temp;
}

double Coord::operator^(Coord &p)
{
    double length;
    length = sqrt(double((m_x-p.m_x) * (m_x-p.m_x) + (m_y-p.m_y) * (m_y-p.m_y)));
    return length;
}

Coord Coord::operator-()
{
    Coord temp;
    temp.m_x = this->m_x * -1;
    temp.m_y = this->m_y * -1;
    return temp;
}


int main()
{
    Coord origin, dju(6, 8), cityhall(5, 3);
    dju.Print_Point("대전대 ");
    cityhall.Print_Point("시청 ");

    cout << "원점에서 대전대까지 거리 = " << dju.Length() << endl;

    cout << "원점 - 대전대 거리 = " << (origin ^ dju) << endl;
    
    cout << "대전대 - 시청 거리 = " << (dju ^ cityhall) << endl;

    (cityhall*3).Print_Point("시청의 3배 좌표 ");

    (-cityhall).Print_Point("시청 원점 대칭 ");

    return 0;
}