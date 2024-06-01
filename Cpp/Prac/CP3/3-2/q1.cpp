#include <iostream>
using namespace std;
class Calculator
{
private:
    int Addcount;
    int Mincount;
    int Mulcount;
    int Divcount;
public:
    Calculator();
    double Add(double x, double y);
    double Min(double x, double y);
    double Mul(double x, double y);
    double Div(double x, double y);
    void ShowOpCount();
};

Calculator::Calculator()
{
    Addcount = 0;
    Mincount = 0;
    Mulcount = 0;
    Divcount = 0;
}

double Calculator::Add(double x, double y)
{
    Addcount++;
    return x + y;
}
double Calculator::Min(double x, double y)
{
    Mincount++;
    return x - y;
}
double Calculator::Mul(double x, double y)
{
    Mulcount++;
    return x * y;
}
double Calculator::Div(double x, double y)
{
    Divcount++;
    return x / y;
}
void Calculator::ShowOpCount()
{
    cout << "덧셈 : " << Addcount << " 뺄셈 : " << Mincount;
    cout << " 곱셈 : " << Mulcount << " 나눗셈 : " << Divcount << endl;
}

int main()
{
    Calculator cal;
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}