#include <iostream>
using namespace std;

class Color
{
private:
    int red, green, blue;
public:
    Color( );
    Color(int red, int green, int blue);
    void Set_Color(int red, int green, int blue);
    void Print_Color();
};

Color::Color()
{
    red = 0, green = 0,blue = 0;
}

Color::Color(int red, int green, int blue)
{
    this->red = red, this->green = green, this->blue = blue;
}

void Color::Set_Color(int red, int green, int blue)
{
    this->red = red, this->green = green, this->blue = blue;
}

void Color::Print_Color()
{
    cout << red << ' ' << green << ' ' << blue << endl;
}

int main()
{
    Color screenColor(255, 0, 0);
    Color *p;
    p = &screenColor;
    p->Print_Color();

    Color *colors = new Color[3];
    p = colors;

    p[0].Set_Color(255,0,0);
    (p+1)->Set_Color(0,255,0);
    (p+2)->Set_Color(0,0,255);

    for (int i = 0; i < 3; i++)
    {
        (p+i)->Print_Color();
    }
    
    return 0;
}