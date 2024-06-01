#include <stdio.h>
int main()
{
    // 1. 정수형 변수
    // int age = 12;
    // printf("%d\n", age);
    // age = 13; //처음에만 형 선언해주면 그 다음엔 안 해도 됨
    // printf("%d\n", age);
    
    // 2. 실수형 변수
    // float f = 46.5;
    // printf("%.2f\n",f); //포매팅
    // double d = 4.428;
    // printf("%.2lf\n",d);
    
    // 3. 상수
    // const int Year = 2000;  // 상수 : 바꿀 수 없는 값
    // printf("태어난 년도 : %d\n, Year");
    // Year = 2001; // 바꿀 수 있는 값이 아니므로 오류 발생!
    
    // 4. printf
    // int add = 3+7; // 10
    // printf("3 + 7 = %d\n", add);
    // printf("%d + %d = %d\n", 30, 79, 30 * 79);
    
    // 5. scanf
    // 키보드 입력을 받아서 저장
    // int input;
    // printf("값을 입력하세요 : ");
    // scanf("%d", &input);
    // printf("입력값 : %d\n", input);

    // int one, two, three;
    // printf("3개의 정수를 입력하세요 : ");
    // scanf("%d %d %d", &one, &two, &three);
    // printf("첫번째 값 : %d\n", one);
    // printf("첫번째 값 : %d\n", two);
    // printf("첫번째 값 : %d\n", three);

    //문자(한 글자), 문자열(한 글자 이상의 여러 글자)
    // char c = 'A';
    // printf("%c\n", c);

    char str[256];
    scanf("%s", str);
    printf("%s\n",str);



    return 0;
}

