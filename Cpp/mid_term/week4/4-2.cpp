#include <iostream>
using namespace std;
class Coord
{
private:
    int m_id;
    int m_x, m_y;
public:
    Coord();
    Coord(int id, int x, int y);
    ~Coord();
    void Print_Coord();
};

Coord::Coord()
{
    m_id = 100;
    m_x = 0;
    m_y = 0;
}

Coord::Coord(int id, int x, int y)
{
    m_id = id;
    m_x = x;
    m_y = y;
}
Coord::~Coord(){}

void Coord::Print_Coord(){
    cout<<m_id<<" 의 좌표는    ("<<m_x<<", "<<m_y<<")\n";
}

int main(){
    Coord c1;
    c1.Print_Coord();

    Coord c2(101,10,20);
    c2.Print_Coord();
    
    Coord c3(102, 30, 40);
    c3.Print_Coord();

    return 0;
}