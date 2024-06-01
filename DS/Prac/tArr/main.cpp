#include <iostream>
#include <time.h>
#include "tArr.h"

//함수 포인터
void Bubble(int* _pData, int _iCount){ //버블 정렬 함수
    int i, temp;
    if(_iCount <= 1)
        return;
    while (true)
    {
        bool bFinish = true;
        int iLoop = _iCount -1 ;
        for (i = 0; i < iLoop; i++)
        {
            if(_pData[i] > _pData[i+1]){
                temp = _pData[i];
                _pData[i] = _pData[i+1];
                _pData[i+1]=temp;
                bFinish = false;
            }
        }
        if (bFinish)
            break;   
    }
}

int main(){

    tArr newArr = {};
    InitArr(&newArr);

    srand(time(nullptr));

    for (int i = 0; i < 10; i++)
    {
        int iRand = rand() % 100 +1;
        PushBack(&newArr,iRand);
    }
    printf("\n정렬 전\n");
    for (int i = 0; i < newArr.iCount; i++)
    {
        printf("%d\n",newArr.pInt[i]);
    }
    printf("\n");
    printf("정렬 후\n");

    Sort(&newArr, Bubble);
    for (int i = 0; i < newArr.iCount; i++)
    {
        printf("%d\n",newArr.pInt[i]);
    }
    ReleaseArr(&newArr);

    return 0;
}
//malloc
//원하는 만큼의 바이트 수 요청 / 힙 메모리 어딘가에 요청한 사이즈만큼 할당된 공간의 주소를 받음
//원하는 곳에 주소 할당? 안 됨.. / 안전장치가 없음 (잘못 접근하면 시스템에 문제가 생김)
//배열공간이 모자랄 때 추가하는 동작이 가능한가???
//NO -> 초기부터 충분히 받았어야함