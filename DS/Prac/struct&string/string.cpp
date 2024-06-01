#include <stdio.h>
#include <wchar.h>


int main() {
    // 메모리 영역
    // 1. 스택
    // 2. 데이터
    // 3. 힙
    // 4. ROM(코드)

    // 문자
    // char(1byte), wchar_t(2byte) = 문자를 위한 자료형들!(저장하는 데이터의 표현방식은 정수를 따르지만)
    char c = 1; // '\x01'
    char cc = 65; // 'A'
    wchar_t wc = 65; // 문자를 표현하는 2byte 자료형, 따옴표 앞에 L을 붙여서 표현된다.
    short s = 49; // 49

    c = 1; // 1이라는 값을 넣음
    c = '1'; // 문자 1에 해당하는 값을 넣음 (49)
    //위의 둘은 전혀 다름

    wchar_t nc = '459'; // 문자 4, 5, 9에 해당하는 값을 나열 5253570 / 0은 널문자 
    // 문자열의 끝은 /0 (널문자)가 들어있음
    // 공백은 32 라는 값, 널문자와 전혀 다르다! / '1 1' == 4932490

    // ============================
    // 문자열
    char c1 = 'a';
    wchar_t c2 = L'a'; // L자를 붙여줌. 2바이트로 쓰겠다는 뜻

    char szChar[10] = "abcdef"; //1바이트씩 -> 널문자까지 7byte
    wchar_t szWchar[10] = L"abcdef"; //2바이트씩 -> 널문자까지 14byte

    short arrShort[10] = {97,98,99,100,101,102}; //위와 같음

    const wchar_t* pChar = L"abcdef"; //문자열이 주소이기때문에 포인터 지정가능 / 2byte 단위이므로 wchar_t로 써줘야함

    szWchar[1] = 'z'; // 문자열을 배열에 복사한 후, 배열의 1번째 접근
    // pChar[1] = 'z'; // 문자열 자체의 1번째 접근 (불가능!!!), 코드영역에 있는 명령어는 실행중에는 수정이 불가하다.(Read Only Memory 안)

    unsigned char szTest[10] = "abc한글"; // 유니코드 문자열은 개당 2바이트여서 한 번에 많은 크기를 차지함. "멀티바이트"
    wchar_t szTestWchar[10] = L"abc한글"; // 2byte 배열로 처리했을 때 한 칸씩 들어감.

    {
        wchar_t szName[10] = L"Raimond";

        int iLen = wcslen(szName);
        // iLen = 1;
    }

    return 0;
}