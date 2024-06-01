#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>
// 메모리 영역

// 함수 오버로딩
// 함수의 이름은 같지만, 인자의 타입이나 개수 등의 차이로 여러 종류가 만들어지는 것

// <-> 함수 오버라이딩 : 클래스 때 등장, 전혀 다른 개념
void Test(int a){

}
void Test(float ){

}


unsigned int GetLength(const wchar_t* _pStr){ // 2byte로 문자열 받기 위해서 wchar & 원본 수정 방지용 const
    int i = 0; //문자 체크용
    while (true)
    {
        wchar_t c = *(_pStr + i);
        if('\0' == c){ // 널문자면 반복문 탈출! // 비교 조건에 상수를 왼쪽에 배치하면 혹시모를 등호(=) 실수에 대비 가능!
            break;
        }
        i++;
    }
    return i;
}

void Strcat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc){ // 접합시킬 배열 공간의 최대공간 크기 알아서 넘치지 않도록
    int iDestLen = GetLength(_pDest); // 원 배열에 들어있는 문자열 길이
    int iSrcLen = GetLength(_pSrc); // 후위 문자열 길이

    // 예외처리
    // 이어붙인 최종 문자열 길이가, 목적지 저장 공간을 넘어서려는 경우
    if (_iBufferSize < iDestLen + iSrcLen + 1){ // 널문자까지 계산해서 전체 공간보다 접합시킨 후의 문자열 길이가 길다면
        assert(NULL); // 경고창 띄우기
    };
    // 문자열 이어 붙이기
    // 1. 목적지 배열의 널문자 찾기 -> 계산한 길이가 바로 널문자의 인덱스
    // 2. 널문자의 인덱스부터 문자열 넣기
    // 3. Src 문자열의 끝을 만나면 반복 종료
    for (int i = 0; i < iSrcLen+1; i++) // iSrcLen+1 을 하는 이유는 널문자까지 받기 위해서(문자열의 끝을 내야하니까!)
    {
        *(_pDest + iDestLen +i) = *(_pSrc + i);
    }
}
int StrCom(const wchar_t* left, const wchar_t* right){
    ////두 문자열 비교해서 완전일치: 0 / 불일치: 양 쪽중 우선순위가 높은 것이 왼쪽 -1, 오른쪽 1

    // 1. 길이 받아오기
    // 2. 길이 같으면 앞부터 하나씩 비교(아스키코드)
    // 3. 아스키코드가 낮으면 우열이 높은 것.

    int leftLen = GetLength(left);
    int rightLen = GetLength(right);
    int iLoop = 0;
    int iReturn  = 0;
    // 두 문자열 길이 비교
    // 길이가 다르면?
    if (leftLen != rightLen)
    {
        if(leftLen > rightLen)
        { 
            iLoop = rightLen;
            iReturn = 1;
        }
        else if (leftLen < rightLen)
        {
            iLoop = leftLen;
            iReturn = -1;
        }
        for (int i = 0; i < iLoop; i++)
        {
            if (*(left + i) != *(right + i))   // 두 문자열의 i인덱스 원소가 다를 때
            {
                if (*(left + i)>*(right + i))  // 아스키코드 비교, 코드가  더 높은 곳이, 우열 낮음,
                {
                    return 1; // 왼쪽이 더 크면? ... 오른쪽이 우열 높음
                }
                return -1; // 반대로 오른쪽이 크면 왼쪽이 우열 높음
            }
        }
        return iReturn;
    }
    
    if(left == right){ // 두 문자열이 동일하면
        return 0;
    }
    for (int i = 0; i < leftLen; i++) // 문자열 길이만큼 반복
    {   
        if (*(left + i) != *(right + i)){   // 두 문자열의 i인덱스 원소가 다를 때
            if (*(left + i)>*(right + i)){  // 아스키코드 비교, 코드가  더 높은 곳이, 우열 낮음,
                return 1; // 왼쪽이 더 크면? ... 오른쪽이 우열 높음
            }
            return -1; // 반대로 오른쪽이 크면 왼쪽이 우열 높음
        }
    }

}

int main(){
    wchar_t szName[10] = L"Raimond";
    int iLen;
    // iLen = wcslen(szName); // 문자열 길이 반환 
    iLen = GetLength(szName); // 만든 함수 (문자열 길이 반환)

    // 문자열 이어 붙이기
    Test(10);
    Test(10.f);

    wchar_t szString[10] = L"abc";
    wcscat(szString, L"def");
    // wcscat(szString, L"scfeee");
    Strcat(szString,10, L"xyz");
    // assert(NULL); // 경고창 띄우기

    int iRet = wcscmp(L"cac", L"ca"); //두 문자열 비교해서 완전일치: 0 / 불일치: 양 쪽중 우선순위가 높은 것이 왼쪽 -1, 오른쪽 1
    int iRet2 = StrCom(L"aaad", L"aac");
    return 0;
}