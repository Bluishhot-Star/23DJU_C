#include <iostream>
#include <string>
using namespace std;

void TestFunc(int test)
{
    cout << "호출하는 함수 내부 : 매개변수 값은 " << test << "\n";
    try
    {
        if(test) throw test;
        else throw (char*)"스트링 0";
    }
    catch(int i)
    {
        cout << "에러를 잡았음 : 예외 값은 " << i << "\n";
    }
    catch(char* str)
    {
        cout << "에러를 잡았음 : 예외 값은 " << str << "\n";
        throw;
    }
    catch(...)
    {
        cout << "나머지 에러를 잡음 " << "\n";
    }
    
}

int main(void)
{
    cout << "프로그램 시작\n";
    try
    {
        TestFunc(10);
        TestFunc(-20);
        TestFunc(0);
        TestFunc(30);
    }
    catch(char* str)
    {
        cout << "메인 함수 내부에서 에러 잡음 : 예외 값은 " << str << endl;
    }
    
    cout << "프로그램 종료" << endl;

    return 0;
}