#include <stdio.h>

int findMax(int score[], int n);
int findMax2(int score[], int n);
int main(){
    int score[] = {30, 70, 50, 60, 100};
    int max = findMax(score, 5);
    // int max = findMax2(score, 5);
    printf("최대값: %d\n",max);
    return 0;
}

int findMax(int score[], int n){
    int temp = score[0];
    for (int i = 1; i < n; i++)
    {
        if (temp < score[i]){
            temp = score[i];
        }
    }
        return temp;
}
int findMax2(int score[], int n){
    int* ptr = score;
    int temp = *ptr;
    for (int i = 1; i < n; i++)
    {
        if (temp < *(ptr+i)){
            temp = *(ptr+i);
        }
    }
        return temp;
}