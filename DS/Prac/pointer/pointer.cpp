#include <stdio.h>
#include <stddef.h>
#include <iostream>

int Test(int a){
    a = 500;
}

int main() {
    // 포인터변수
    // 주소를 저장하는 변수 (주소를 가리키는 변수)
    int i = 100;
    float f = 3.f;

    float* ptr = &f; 

    // 주소로 접근
    int a = 1;
    int* pInt = &a;

    pInt += 1; // 주소를 저장하는 변수에 1을 더함 = 주소를 1 증가시켜라 = 다음 int 위치로 가겠다 = 주소 4증가
    // pInt는 int* 변수이기 때문에, 가리키는 곳을 int로 해석한다.
    // 따라서 주소값을 1 증가하는 의미는 다음 int 위치로 접근하기 위해서 sizeof(int) 단위로 증가하게 된다.

    // 포인터와 배열
    
    // 배열의 특징
    // 1. 메모리가 연속적인 구조이다.
    // 2. 배열의 이름은 배열의 시작 주소이다.

    int iArr[10] = {};
    // int 단위로 접근
    *(iArr) = 10; // iArr[0] = 10;
    *(iArr + 1) = 10; // 1번째 칸에 10 할당 // iArr[1] = 10;

    // 포인터 이해 확인 문제
    // 문제 1
    short sArr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* pI = (int*)sArr;

    int iData = *((short*)(pI + 2));
    printf("1번 문제 정답 : %d\n", iData);

    // 문제 2
    char cArr[2] = {1, 1};
    short* pS = (short*)cArr;
    iData = *pS;
    printf("2번 문제 정답: %d\n", iData);

    // ====================================

    //const

    //상수화
    //l-value : 변수
    //r-value : 상수
    int ii = 10;

    volatile const int cint = 100;
    int* ppInt = (int*)&cint;
    *ppInt = 300;
    printf("cint 출력: %d\n", cint);

    return 0; 
}