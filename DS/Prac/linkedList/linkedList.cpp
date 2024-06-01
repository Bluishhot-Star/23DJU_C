#include <iostream>
#include "linkedList.h"

// 리스트 초기화
void InitList(tLinkedList* _pList){
    _pList -> pHeadNode = nullptr;
    _pList -> iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData){
    // 데이터를 저장할 노드 생성
    // 데이터 복사
    tNode* pNode = (tNode*)malloc(sizeof(tNode));
    pNode -> iData = _iData;
    pNode -> pNextNode = nullptr; // 지금 들이는 데이터는 마지막 데이터니까 다음 데이터 주소는 없음
    
    // 추가한 데이터가 첫 번째인지 아닌지
    if (0 == _pList->iCount){ // 카운트가 0
        _pList->pHeadNode = pNode; // 현재 노드를 헤드노드에 넣는다.(1번이니까)
    }
    else{ //최초생성 X
        // 현재 생성되어있는 마지막 노드를 찾아서,
        // 해당 노드의 pNextNode에 현재 노드 주소를 담기

        // 지금 하고 있는 구조는 '단방향'연결 리스트이기 떄문에
        // 현재 접근할 수 있는 방법은 '헤드 노드'를 이용하는 것이다.
        tNode* pCurFinalNode = _pList->pHeadNode; //헤드노드를 건드리지 않기위해서 지역변수 활용(현재 기준 마지막 노드)
        while (true)
        {
            if (nullptr == pCurFinalNode->pNextNode) //다음 노드 주소가 NULL일 때까지 or Count만큼 반복하기
            {
                break;
            }
            pCurFinalNode= pCurFinalNode->pNextNode; //break되지 않으면 다음 노드의 주소를 지역변수에 할당시킴(다음 노드 조사 한다는 뜻)

        }
        pCurFinalNode->pNextNode = pNode; //현재 기준 마지막 노드에 접근해서 지금 넣으려는 노드의 주소값 가리킬 수 있도록 넣어주기
    }
    _pList->iCount++; //노드 수 카운트 up
}

void Release(tNode* _pNode)
{
    if (nullptr == _pNode)
        return;
    Release(_pNode->pNextNode);
    free(_pNode);
}

    // Release(_pList->pHeadNode); 재귀를 사용하는 방법

    // 반복문
void ReleaseList(tLinkedList* _pList) //하나하나 초기화 -> 반복문 or 재귀 / 재귀는 효율이 안 좋음
{
    tNode* pDeleteNode = _pList->pHeadNode;
    while (pDeleteNode) //NULL일 때 반복 종료
    {
        tNode* pNext = pDeleteNode->pNextNode; // 다음 리스트의 주소 미리 저장
        free(pDeleteNode); // 현재 노드 메모리 해제
        pDeleteNode = pNext; // 삭제할 노드의 주소를 다음 리스트의 주소로 할당
    }
}

void PushFront(tLinkedList* _pList, int _iData)
{
    tNode* pNode = (tNode*)malloc(sizeof(tNode));
    pNode->iData = _iData;
    pNode->pNextNode = _pList->pHeadNode;
    _pList->pHeadNode = pNode;
    _pList->iCount++;
}

// 