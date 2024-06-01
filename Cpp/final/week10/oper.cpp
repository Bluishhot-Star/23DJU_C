#include <iostream>
using namespace std;

class Shape{
public:
    virtual void draw()
    {
        cout << "--shape--";
    }
};

class Circle : public Shape
{
public:
    void draw()
    {
        Shape::draw();
        cout << "Circle"<< endl;
    }
};

int main(void)
{
    Circle c;
    Shape * pShape = &c;
    Circle * p = &c;
    // pShape->draw();
    // pShape->Shape::draw();
    p->draw();
    p->Shape::draw();
    return 0;
}