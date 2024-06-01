#include <iostream>
using namespace std;

int SimpleFunc(int a=10)
{
    return a + 1;
}
int SimpleFunc(void)
{
    return 10;
}

// 함수 오버로딩의 조건은 충족하므로 컴파일은 됨


int main(void)
{
    cout << SimpleFunc(1) << endl; // 이 경우에는 컴파일 에러 없음
    // cout << SimpleFunc() << endl; // 이 경우에는 두 함수 중 호출 대상이 불분명하므로 컴파일 에러
    return 0;
}