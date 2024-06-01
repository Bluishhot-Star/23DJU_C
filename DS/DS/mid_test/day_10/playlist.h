typedef struct playListNode
{
    char data[30];  // 문자열 (노래 정보)
    struct playListNode* link;  //  다음 노드
}playListNode;

typedef struct playList
{
    playListNode* head;     // 헤드노드
}playList;

typedef struct selectListNode
{
    struct playListNode* data;      // 노드의 주소를 가지고 있음
    struct selectListNode* link;    // 다음 리스트
}selectListNode;

typedef struct selectList
{
    selectListNode* head;
}selectList;

playList* createPlayList(void);
void insertPlayListLastNode(playList* CL, char* x);
playListNode* searchNode(playList* CL, char* x);
selectList* createSelectList(void);
void insertSelectListLastNode(selectList* sCL, playListNode* p_temp);
void printSelectList(selectList* CL);