#include <iostream>
using namespace std;

class Simple
{
private:
    int a;
public:
    int &ref = a;
    Simple();
    int Getval();
};

Simple::Simple()
{
    a = 10;
}
int Simple::Getval()
{
    return a;
}

// private 변수 상수화

class Simple2
{
private:
    int a = 10; // a 상수화
public:
    const int &ref = a; // 참조자 상수화, const 붙이지 않으면 컴파일 에러 (상수화된 변수를 참조하기 때문)
    Simple2();
    int Getval();
};
Simple2::Simple2(){}
int Simple2::Getval()
{
    return a;
}

int main(void)
{
    Simple A;
    A.ref += 10; // 참조자로 private값 변화
    cout << A.ref << endl; //참조자를 이용해서 값 가져오기
    cout << A.Getval() << endl; //참조자로 private값 변화 가능..
    
    Simple2 B;
    // B.ref
    cout << B.ref << endl;
    cout << B.Getval() << endl;

    return 0;
}