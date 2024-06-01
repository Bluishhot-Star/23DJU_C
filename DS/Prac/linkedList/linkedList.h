//삽입 선택 merge quick 힙정렬(완전 이진트리 이후에)

typedef struct _tagNode
{
    int iData;
    struct _tagNode* pNextNode;
}tNode;


typedef struct _tagList
{
    int iCount; // 데이터 개수
    tNode* pHeadNode;
}tLinkedList;

// 연결형 리스트 초기화
void InitList(tLinkedList* _pList);

// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int iData);
void PushFront(tLinkedList* _pList, int iData);

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);
