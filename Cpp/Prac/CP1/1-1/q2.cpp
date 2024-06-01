#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string name, phone;
    cout << "이름과 전화번호 입력 : ";
    cin >> name >> phone; //공백으로 입력 구분
    cout << name<< " " << phone <<endl;
    return 0;
}

