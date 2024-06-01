#include <iostream>

using namespace std;

class Circle
{
private:
    int m_radius;
public:
    Circle(int radius);
    double Get_Area();
};

Circle::Circle(int radius)
{
    m_radius = radius;
}

double Circle::Get_Area()
{
    return 3.14 * m_radius * m_radius;
}

int main()
{
    Circle ob[3] = {10,20,30};
    Circle *p;
    p = ob;

    cout << "객체로 멤버 함수 접근" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << ob[i].Get_Area() << " ";
    }
    cout <<endl;

    cout << "객체 포인터로 멤버 함수 접근" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << p->Get_Area() << " ";
        p++;
    }

    cout <<endl;
    return 0;
}
