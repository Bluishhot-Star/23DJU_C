#include <stdio.h>
#include <stdlib.h>
#include "tArr.h"

void InitializeArr(tArr* _pArr) //메모리 초기화 함수
{
    _pArr -> iptr = (int*)malloc(sizeof(int)*2);
    _pArr -> iCount = 0;
    _pArr -> iMax = 2;
}

void ReleaseArr(tArr* _pArr) //메모리 해제 함수
{
    free(_pArr->iptr);
    _pArr -> iCount = 0;
    _pArr -> iMax = 0;
}

void Reallocate(tArr *_pArr)
{
    int* newArr = (int*)malloc(sizeof(int)*(_pArr->iMax)*2);
    for (int i = 0; i < _pArr->iCount; i++)
    {
        *(newArr + i) = *(_pArr->iptr + i);
    }
    free(_pArr->iptr);
    _pArr->iptr = newArr;
    _pArr->iMax *= 2;
}

void PushData(tArr* _pArr, int _iData) //메모리 추가 함수
{
    if(_pArr->iMax <= _pArr->iCount){
        Reallocate(_pArr);
    }
    _pArr->iptr[_pArr->iCount++] = _iData;
}
void Bubble1(tArr* _pArr){
    int temp;
    for (int i = _pArr->iCount-1; i >0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(_pArr->iptr[j] > _pArr->iptr[j+1]){
                temp = _pArr->iptr[j];
                _pArr->iptr[j] = _pArr->iptr[j+1];
                _pArr->iptr[j+1]=temp;
            }
        }
    }
}


void Bubble(tArr* _pArr){
    int i, temp;

    // 데이터가 1개 이하면 정렬하지 않음
    if(_pArr->iCount <= 1)
        return;

    while (true)
    {
        bool bFinish = true; //정렬 완료 여부
        int iLoop = _pArr->iCount -1 ;
        for (i = 0; i < iLoop; i++)
        {
            if(_pArr->iptr[i] > _pArr->iptr[i+1]){
                temp = _pArr->iptr[i];
                _pArr->iptr[i] = _pArr->iptr[i+1];
                _pArr->iptr[i+1]=temp;
                bFinish = false; //끝나지 않았다!
            }
        }

        if (bFinish) //반복문 이후에 ture값이 유지 되었을 때 (if문에 들어가지 않음 = 정렬완료! 라는 뜻)
        {
            break;
        }
        
    }
    
}

