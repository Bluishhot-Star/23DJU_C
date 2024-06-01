#include <stdio.h>

//자료형 = 데이터 타입
// 구조체 = 사용자 정의 자료형
typedef struct _tagTarget
{
    int a;
    float b;
} Target;
typedef struct _tagNew
{
    Target t; // 내가 만든 자료형이 또하나의 부분이 될 수 있다.
    int a;
    float b;
} New;
/* ======================================= */
// typedef 타입 재정의
// typedef int INT; >> INT를 int로 타입 재정의 / INT를 int와 동일하게 사용할 수 있다.

// 구조체, typedef 따로 따로
// struct MYST{
//     int a;
//     float b;
// };
// typdef struct MYST myst;

// 구조체 선언과 typedef을 한 번에
typedef struct MYST{
    int a;
    float b;
    int c;
}myst;

int main()
{
    // struct MYST MM; // struct를 써줘야함(C기반에서)

    myst M = {100, 3.14f, 100};
    M.a = 10;
    

    int iSize = sizeof(myst); // 4byte짜리 3개가 요소이기 때문에 12
    return 0;
}