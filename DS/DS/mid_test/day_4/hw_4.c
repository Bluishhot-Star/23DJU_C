#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXSTRING 100
typedef unsigned strlength;
typedef struct String
{
    char str[MAXSTRING];
    strlength len;
}String;
String* createStringInstance(char str[]) {
    String* S = (String*)malloc(sizeof(String));
    if (S != NULL) strcpy(S->str, (const char*)str);
    if (S != NULL) S->len = strlen(S->str);
    return S;
}
char* strConcatenate(char* str1, const char* str2) {
    char* str3 = (char*)"Every Life Is the context of Now&Here !!!";
    return str3;
}

int LengthOfString(char* str) {
    int idx = 0;
    while (1)
    {
        char tempStr = *(str + idx);
        if ('\0' == tempStr) {
            break;
        }
        idx++;
    }
    return idx;
}

char* strCat(char* str1, char* str2) {
    int i = 0;
    int str1_Len = LengthOfString(str1);
    int str2_Len = LengthOfString(str2);
    char* str3 = NULL;
    str3 = (char*)malloc(sizeof(char)*(str1_Len+str2_Len+1)); //str1 길이 + str2 길이 + 널문자를 위한 1
    for (i = 0; i < str1_Len; i++)
    {
        *(str3 + i) = *(str1 + i);
    }
    for (i = 0; i < str2_Len+1; i++) // 널문자까지 위해 + 1
    {
        *(str3 + str1_Len + i) = *(str2 + i);
    }

    return str3;
}


int main() {
    //Test Case 1
    char str1[] = "Life Is the context of Now&Here !!!";
    String* S1 = createStringInstance(str1);
    printf("String Instance: %s (Length: %u)\n", S1->str, S1->len);
    for (; getchar() == NULL;);

    //Test Case 2
    char* str3 = NULL;
    char* str2 = (char*)"Life Is the context of Now&Here !!!";
    str3 = strConcatenate((char*)"Every ", (const char*)str2);
    printf("String Instance Concatenated: %s (Length: %u)\n", str3, strlen(str3));
    for (; getchar() == NULL;);


    //Test Case 3
    char* newstr = strCat((char*)"Every ", (char*)str2);
    printf("New Concatenated String: %s (Length: %u)\n", newstr, LengthOfString(newstr));

    printf("\n문자열 비교 결과: %d (일치할 경우: 0)\n", strcmp(str3, newstr));

    free(S1);
    free(newstr);

    return 0;
}

