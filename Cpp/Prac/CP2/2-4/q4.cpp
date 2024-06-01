#include <iostream>
using namespace std;

int main(void)
{
    const int num = 12;
    const int* ptr = &num; // const 변수를 가리킬 때는 const를 붙여서 값 변경 불가하도록.
    const int* &ref = ptr; // const int* 을 참조하기 위해서는 자료형 똑같이 선언

    cout << *ref << endl;
    return 0;
}