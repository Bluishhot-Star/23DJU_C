#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

playList* createPlayList(void)
{
    playList* CL = (playList*)malloc(sizeof(playList)); //구조체 동적배열
    CL->head = NULL; // 현재 노래를 넣지 않은 상태 이므로 NULL
    return CL;
}
void insertPlayListLastNode(playList* CL, char* x)
{
    playListNode* newNode, *temp;
    newNode = (playListNode*)malloc(sizeof(playListNode));
    strcpy(newNode->data, x);
    if (CL->head == NULL) //원형 리스트의 항이 없을 때
    {
        CL->head = newNode; // 새로운 항 추가
        newNode->link = newNode; // 새로운 항의 링크를 자기 노드로
    }
    else
    {
        temp = CL->head;
        while (temp -> link != CL->head) //마지막 노드 찾기(마지막 노드의 링크는 헤드 주소를 담고 있음)
        {
            temp = temp->link;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
}
playListNode* searchNode(playList* CL, char* x)
{
    playListNode* temp;
    temp = CL->head;
    if (temp == NULL) return NULL;
    do
    {
        if (strcmp(temp->data,x) == 0) return temp; //문자열이 같으면 temp 리턴
        else temp = temp->link; //아니면 다음 노드로
    } while (temp != CL->head); //마지막 노드까지 탐색
    printf("\n입력한 음악을 찾지 못했습니다.\n");
    return NULL;
}
selectList* createSelectList(void)
{
    selectList* sCL;
    sCL = (selectList*)malloc(sizeof(selectList));
    if (sCL != NULL) sCL->head = NULL;
    return sCL;
}
void insertSelectListLastNode(selectList* sCL, playListNode* p_temp)
{
    selectListNode* newNode, * s_temp;
    newNode = (selectListNode*)malloc(sizeof(selectListNode));
    newNode->data = p_temp;
    if (sCL->head == NULL) // 첫번째 항을 넣을 때
    {
        sCL->head = newNode;
        newNode->link = newNode;
    }
    else 
    {
        s_temp = sCL->head;
        while (s_temp->link != sCL->head) s_temp = s_temp->link; //마지막 노드 찾기
        
        if(newNode != NULL) newNode->link = s_temp->link; //새로운 노드의 링크를 헤드로
        s_temp->link = newNode; //현 마지막 노드의 링크를 새로운 노드로   
    }
}
void printSelectList(selectList* CL)
{
    selectListNode* s;
    printf("\n\nmyPlayList : ");
    s = CL->head;
    if (s==NULL) return;
    do
    {
        printf("  %s", s->data->data);
        s = s->link;
    } while (s != CL->head); //마지막 노드까지
    printf("\n\n");
}