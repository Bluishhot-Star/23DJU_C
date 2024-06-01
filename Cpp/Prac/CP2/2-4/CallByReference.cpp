#include <iostream>
using namespace std;

/*
(참조자)
참조자는 변수의 또다른 '별칭'이다.
메모리 공간에 또다른 이름을 붙이는 느낌

선언과 동시에 초기화가 필수
참조자를 이용해서 값을 넣으면 해당 메모리 공간의 값이 바뀜
*/

void SwapByRef(int &ref1, int &ref2) //참조자를 이용한 swap (Call by Reference)
{
    int temp = ref1; //참조자의 메모리 공간이 가지고 있는 값 할당
    ref1 = ref2; // ref1의 공간에 ref2가 가지고 있는 값 할당
    ref2 = temp; // ref2의 공간에 temp의 값 할당
}
int main(void)
{
    int a = 10, b = 20;
    SwapByRef(a, b);
    cout << a << "  " << b << endl;
    
    return 0;
}