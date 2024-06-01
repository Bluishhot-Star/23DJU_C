#include <stdio.h>

/*변수 종류
1. 지역변수
2. 전역변수
3. 정적변수 static
4. 외부변수 extern
(1 스택영역 / 2~3 모두 데이터 영역)
*/

/* 메모리영역
1. 스택 영역
2. 데이터 영역
3. 읽기 전용(코드, ROM)
4. 힙 영역
*/

//전역변수
int g_i = 0; // Data 영역

//Data영역
// 프로그램 시작 시 생성
// 프로그램 종료 시 해제
// 스택에 들어갔다가 해제되고 이런 과정 없음
// 즉, 프로그램 내내 유지되어야하는 값을 전역변수로!!



#include "function.h" //헤더파일에서 선언한 것을 가져옴
#include "common.h"
//정적변수
// static int snum = 0; //재정의 오류 include는 복붙이라서 이 파일에서 선언한 것과 동일


int exnum = 0;
void Test();
int Hello();
int main(){
    snum = 100;
    exnum = 500;
    Add(10,20);
    printf("%d %d\n", snum, exnum);
    Hello();
    Hello();
    Hello();
    Hello();
    int Hcnt = Hello();

    return 0;
}
void Test() {
    int i = 0;
    i++; //지역변수 함수가 호출되어서 스택에 쌓였다가 해제될 때 함께 clear
    g_i++; //전역변수라서 계속해서 증가
}
int Hello() {
    static int cnt = 0;
    cnt++;
    return cnt;
}