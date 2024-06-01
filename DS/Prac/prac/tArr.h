// 가변배열
// 구조체 (포인터, 카운트, 맥스)
// 메모리해제 함수
// 초기화함수
// 데이터 확장 함수
// 데이터 추가

typedef struct tArr
{
    int* iptr; //메모리 포인터
    int iCount; //카운트
    int iMax; //맥스
}tArr;

void InitializeArr(tArr* _pArr); //메모리 초기화 함수
void ReleaseArr(tArr* _pArr); //메모리 해제 함수
void PushData(tArr* _pArr, int _iData); //메모리 추가 함수
void Bubble1(tArr* _pArr);
void Bubble(tArr* _pArr);