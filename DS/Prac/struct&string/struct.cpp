#include <stdio.h>

typedef struct _tagMyst
{
    int a; //멤버
    float f;
}MYST;


int main() {
    MYST s = {};
    MYST* pST = &s; //구조체 포인터도 다른 것과 동일하게 접근해서 얼마나 메모리를 읽을 것인가! 라는 정보가 담겨있는 것

    (*pST).a = 100; // 역참조해서 a라는 멤버에 접근, a라는 멤버는 정수형이므로 4byte를 접근함.
    (*pST).f = 10.3f;

    pST -> a = 100; // 역참조하는 것을 줄여서 이렇게 코드작성가능!
    pST -> f = 10.3f;

    

    return 0;
}