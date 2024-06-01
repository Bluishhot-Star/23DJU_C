#include <stdio.h>

int main() {
    //test case0
    printf("C언어 세계에 오신 것을 환영합니다!!!\n");
    printf("%c\n", getchar());
    printf("\n\n\n");

    //test case1
    int n = 65;
    printf("테스트1: 일반 변수의 주소와 값 확인하기\n");
    printf("변수 n의 주소: %p\n", &n); //16진수로 반환
    printf("변수 n의 값: %d(크기:%d)\n", n, sizeof(n)); // 크기 4(byte)
    printf("%c\n", getchar());

    //test case2
    int* ptr1 = &n;
    printf("테스트2: 포인터 변수의 자료형 확인하기\n");
    printf("변수 ptr1의 주소: %p\n", &ptr1);
    printf("변수 ptr1의 값(주소): %p(크기:%d)\n", ptr1, sizeof(ptr1)); // 크기 8(byte)
    printf("변수 ptr1의 참조값: %d\n", *ptr1); // 주소가 가리키는 값 반환
    printf("%c\n", getchar());

    //test case3
    char ch = 'A';
    char* ptr2 = &ch;
    printf("테스트3: 포인터 변수의 자료형 확인하기\n");
    printf("변수 ptr2의 주소: %p\n", &ptr2);
    printf("변수 ptr2의 값(주소): %p(크기:%d)\n", ptr2, sizeof(ptr2)); // 크기 8(byte)
    printf("변수 ptr2의 참조값: %c\n", *ptr2); 
    printf("%c\n", getchar());

    //test case4
    char ch1 = (char)n;
    char* ptr3 = &ch1;
    printf("테스트4: 형변환자 확인하기\n");
    printf("변수 ptr3의 주소: %p\n", &ptr3);
    printf("변수 ptr3의 값(주소): %p(크기:%d)\n", ptr3, sizeof(ptr3)); // 크기 8(byte) 포인터변수 자체는 64비트에서 8byte로 동일함.
    printf("변수 ptr3의 참조값: %c\n", *ptr3);

    

    return 1;
}