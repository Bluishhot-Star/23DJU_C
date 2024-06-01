#pragma once


typedef struct _tArr
{   
    // 가변배열을 위한 필수 3요소
    int* pInt; //데이터를 담을 주소
    int iCount; //데이터 현재까지 받은 개수 (데이터를 이어서 받기 위해서)
    int iMax; //데이터의 최대치 (데이터를 그만 받게 하려면?)
}tArr;

//배열 초기화 함수
void InitArr(tArr* _pArr); 

//데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

//공간 추가 확장
// void Reallocate(tArr* _pArr);
// 헤더 파일에 선언해놓으면 main에서 접근이 가능하기 때문에 숨겨놓기

//배열 메모리 해제 함수
void ReleaseArr(tArr* _pArr); 

//데이터 정렬 함수 (함수 포인터 포함)
void Sort(tArr* _pArr, void(*SortFunc)(int*, int));