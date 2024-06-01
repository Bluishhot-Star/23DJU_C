#include <iostream>

struct tMy
{
    
};

class CMy
{
    // 접근 제한 지정자
    // private, protected(상속), public
    
private:
    int m_i, m_f;

public:
    void SetInt(int i)
    {
        m_i = i;
    }

    // 생성자
    // 이니셜라이저 (진정한 의미의 초기화 가능)
    // (만들어지면서 초기화)
    CMy()
        : m_i(100)
        , m_f(0.f)
    {
    }

    // 소멸자 함수 종료시 실행
    ~CMy(){}
};




int main()
{
    // C++ 클래스 특징
    // 구조체와 동일(사용자가 정의한 자료형) 

    CMy c;
    //c.m_i; // private 필드의 멤버는 외부에서 직접 접근할 수 없다.
    c.SetInt(10); // public필드의 함수를 이용해 간접 접근할 수 있다.

    return 0;
}