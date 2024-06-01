#include "tArr.h"
#include <iostream>

void InitArr(tArr* _pArr){ 
    _pArr -> pInt = (int*)malloc(sizeof(int)*2); //int로 처리하겠다는 의도를 보여줌
    _pArr -> iCount = 0;
    _pArr -> iMax = 2; //int 2개 받도록 초기화했으니까 2!
}

void ReleaseArr(tArr* _pArr){
    free(_pArr -> pInt); //주소값 담은 곳 접근해서 해제
    _pArr -> iCount = 0;
    _pArr -> iMax = 0;
}

// 공간 추가 확장
void Reallocate(tArr* _pArr){
    // 1. 2배 더 큰 공간을 동적할당한다.
    int* pNew = (int*)malloc(_pArr->iMax * 2 * sizeof(int));
    // 2. 기존에 있던 데이터 가져오기
    for (int i = 0; i < _pArr->iCount; i++)
    {
        pNew[i]= _pArr->pInt[i];
    }
    // 3. 기존 공간은 메모리 해제
    free(_pArr->pInt);
    // 4. 배열이 새로 할당된 공간을 가리키게 한다.
    _pArr->pInt = pNew;
    // 5. MaxCounter 변경점 적용
    _pArr->iMax *= 2;
}


void PushBack(tArr* _pArr, int _iData){
    //힙 영역에 할당한 공간이 다 참?
    if (_pArr -> iMax <= _pArr -> iCount){ 
        Reallocate(_pArr);
    }
    // 메모리 문제 해결 후..

    // 데이터 추가
    _pArr -> pInt[_pArr -> iCount++] = _iData;
    // 추가 후 데이터cnt+1
}
void Sort(tArr* _pArr, void(*SortFunc)(int*, int)){
    SortFunc(_pArr->pInt, _pArr->iCount);
}


