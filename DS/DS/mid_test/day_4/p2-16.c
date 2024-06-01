#include <stdio.h>
#define ROWS 2
#define COLS 3

int main(){
    int ArrN[][COLS] = {{1, 2, 3}, {4, 5, 6}};
    int *ptr_arr = NULL;

    for (int i = 0; i < ROWS; i++)
    {
        ptr_arr = ArrN[i];
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\n", *(ptr_arr + j)); //ArrN[i][j]의 dereferencing
        }
    }

    return 0;
}