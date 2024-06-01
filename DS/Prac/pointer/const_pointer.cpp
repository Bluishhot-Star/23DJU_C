#include <stdio.h>

void Output(const int * pI){
    int i = *pI;
}

int main(){
    // 1. const
    const int i = 100;
    // ==============
    // const 포인터
    // ==============
    int a = 0;
    int* pInt = &a;

    *pInt = 1;
    pInt = NULL;

    // ==========================
    // 포인트의 상수화 (2가지)
    // ==========================
    // 1.
    const int* pConstInt = &a; // a를 상수화
    // *pConstInt = 100; // 가리킨 원본은 변경 불가 / l-value이어야 변경 가능
    int b = 0;
    pConstInt = &b; // 가리키는 대상은 변경 가능

    // 2.
    int* const pIntConst = &a; //포인터 변수를 상수화
    *pIntConst = 1; // 가리킨 원본 변경 가능
    // pIntConst = &b; // 가리키는 대상은 변경 불가

    // 초기화 시 가리킨 대상만 가리킴, 가리키는 원본을 수정 불가
    const int* const pConstIntConst = NULL; // 즉, 두 가지 모두 적용

    {
        int a = 0;
        const int* pInt = &a;

        a = 100; 
        
        
        // 가능! .. a를 상수로 만든 것이 아니라 포인터의 '가리킨 대상을 수정하는 기능'이 상수화된 것이다.

    }
    
    //void (존재하지않는다 라는 뜻)
    //void*
    // 1. 원본의 자료형을 정하지 않음!
    // 2. 어떠한 타입의 변수의 주소든 다 저장 가능
    // 3. 역참조 불가능
    // 4. 주소 연산 불가능
    
    void* pVoid = NULL; // 원본으로 접근했을 때 형태를 정하지 않음 = 어떤 자료형이든 다 받을 수 있음
    float* pFloat = NULL;
    {
        int a = 0;
        float f = 0.f;
        double d = 0;
        long long ll = 0;

        pVoid = &a;
        pVoid = &f;
        pVoid = &d;
        pVoid = &ll; //모든 자료형을 다 받을 수 있음!

        // *pVoid = 1; 하지만 역참조는 할 수 없음..(어떤 타입인지 모르니까)
        // pVoid +1 포인터 연산 역시 타입을 모르므로 불가!


    }


    return 0;
}