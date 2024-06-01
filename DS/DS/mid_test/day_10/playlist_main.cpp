#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"
#define MAX_N 100

int main(void)
{
    int i, len, N, K; // N : 전체 음악 수 K : 나의 선택 음악 수
    char tmp[30];
    char* select[MAX_N] = {0}; //최대 100개까지 플레이리스트 저장 가능
    playList* pCL = createPlayList();
    selectList* sCL = createSelectList();
    playListNode* p;
    char* playList[MAX_N] = {"BTS", "에스파", "AKMU", "헤이즈", "SG워너비", "빅뱅"};

    scanf("%d %d", &N, &K); // 전체 음악 개수, 나의 플레이리스트 수 입력
    for (i = 0; i < K; i++) // 나의 플레이리스트 수 만큼 음악 입력
    {
        scanf("%s", tmp); // 음악 입력
        len = strlen(tmp) + 1; // 음악 정보의 길이 + 1 (널문자 포함)
        select[i] = (char*)malloc(sizeof(char)*len); // 해당 인덱스의 크기를 음악 정보길이 만큼 동적할당한 후 
        strcpy(select[i], tmp); // 플레이리스트 배열에 음악 정보 할당
    }

    // 2
    for (  i = 0; i < N; i++)
    {
        insertPlayListLastNode(pCL, playList[i]); //플레이리스트 만들기
    }

    // 3
    for (  i = 0; i < K; i++)
    {
        p = searchNode(pCL, select[i]); // 내가 선택한 음악이 전체 플레이리스트에 있는지 / 있으면 주소를 받아옴 /없으면 NULL
        if (p != NULL)
        {
            insertSelectListLastNode(sCL, p); // 나의 플레이리스트에 p 저장 /
        }
        
    }
    
    printSelectList(sCL);
    return 0;
}