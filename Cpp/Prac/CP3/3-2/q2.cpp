#include <iostream>
using namespace std;

class Printer
{
private:
    string newStr;
public:
    Printer();
    void SetString(string strIn);
    void ShowString();
};
Printer::Printer(){}
void Printer::SetString(string strIn)
{
    newStr = strIn;
}
void Printer::ShowString()
{
    cout << newStr << endl;
}

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();
    
    pnt.SetString("I love C++");
    pnt.ShowString();
    
    return 0;
}