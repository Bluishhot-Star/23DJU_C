#include <iostream>
using namespace std;

int main() {
    char name, A = 66;
    
    name = 'A';
    cout << name << "  " << (int) name << endl;
    name = A;
    cout << name << "  " << (int) name << endl << endl;
    
    cout << "**자료형의 크기를 알아보자**" << endl;
    cout << "int 자료형의 크기 : " << sizeof(int) << endl;
    cout << "long 자료형의 크기 : " << sizeof(long) << endl;
    cout << "float 자료형의 크기 : " << sizeof(float) << endl;
    cout << "double 자료형의 크기 : " << sizeof(double) << endl;
    cout << "char 자료형의 크기 : " << sizeof(char) << endl;
    return 0;
}


