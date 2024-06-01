#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int xpos = 0, int ypos = 0)
    {
        this->xpos = xpos; this->ypos = ypos;
    }
    void Set_pos(int x, int y)
    {
        xpos = x; ypos = y;
    }
    void ShwoPointInfo() const
    {
        cout << "[" << xpos << ", "<< ypos << "]" << endl;
    }
};

class Circle
{
private:
    int m_rad;
    Point m_center;
public:
    Circle(){}
    void Set_Circle(int xpos, int ypos, int rad)
    {
        m_center.Set_pos(xpos, ypos);
        m_rad = rad;
    }
    void ShwoCircleInfo() const
    {
        cout << "radius : " << m_rad << endl;
        m_center.ShwoPointInfo();
    }
};

class Ring
{
private:
    Circle in_Circle;
    Circle out_Circle;
public:
    Ring(){}
    void Set_Ring(int InX, int InY, int InRad, int OutX, int OutY, int OutRad)
    {
        in_Circle.Set_Circle(InX, InY, InRad);
        out_Circle.Set_Circle(OutX, OutY, OutRad);
    }
    void ShowRingInfo() const
    {
        cout << "Inner Circle Info..."<<endl;
        in_Circle.ShwoCircleInfo();
        cout << "Outter Circle Info..."<<endl;
        out_Circle.ShwoCircleInfo();
    }
};

int main(void)
{
    Ring ring;
    ring.Set_Ring(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}