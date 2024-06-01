#include <stdio.h>
#define _MAXSTR 100 //STR 받기위한 배열의 크기 변수
#define _NOFSTR 4 //STR 개수

int strlen(char str[]){
    int count = 0;
    while (*(str + count) != NULL)
    {
        count++;
    }
    return count;
}

int* strmlen(char str[][_MAXSTR]){
    int count = 0, mlens[_NOFSTR];
    for (int i = 0; i < _NOFSTR; i++)
    {
        mlens[i] = strlen(str[i]);
    }
    return mlens;
}

int main(){
    int len, *m_ptr=NULL, mlens[_NOFSTR]; //길이, 포인터변수, 2차원배열 선언
    char str1[] = "I luv U! How about U!!"; 
    char str2[][_MAXSTR] = {"I luv U!", "How about U!!", "ok", "DONE"}; //2차원 배열 행마다 한 줄씩 초기화

    len = strlen(str1); //문자열 길이 반환 후 초기화
    printf("%s의 길이 : %d\n", str1, len); // 해당 문자열 & 길이 출력
    getchar();

    m_ptr = strmlen(str2); //길이를 담고있는 배열의 주소로 초기화
    for (int i = 0; i < _NOFSTR; i++) //STR 개수 만큼 반복
    {
        mlens[i] = *(m_ptr + i); // 길이 하나씩 담기
    }
    for (int i = 0; i < _NOFSTR; i++)
    {
        printf("%s의 길이: %d\n", str2[i], mlens[i]);
    }
    getchar();
    
    return 0;
}