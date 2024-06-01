#include <iostream>
using namespace std;

int main(void)
{
    int a = 30;
    // 30과 같은 숫자는 '리터럴 상수'이다. 다음 줄로 넘어가면 존재하지 않는 상수가 된다.
    const int &ref = 30;
    // 위의 문장은 숫자 30이 메모리 공간에 계속 남아있을 때 성립한다.
    // const 참조자로 리터럴 상수를 참조할 때 C++에서는 이를 위해서 '임시변수'를 만든다.
    // 즉, 결과적으로는 '상수화된 변수'를 참조한 것이 된다.

    
    return 0;
}