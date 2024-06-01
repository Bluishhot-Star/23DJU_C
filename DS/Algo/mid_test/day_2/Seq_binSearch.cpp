#include <stdio.h>

int sum(int S[], int N){
    int sum=0;
    for (int i = 0; i < N; i++)
        sum += S[i];
    return sum;
}

int findMax(int S[], int N){
    int max = S[0];
    for (int i = 0; i < N; i++)
    {
        if (max < S[i]) max=S[i];
    }
    return max;
}
int compare(int x, int y){
    if(x==y)return 0;
    else if (x>y)return 1;
    else return -1;
}
int sequentialSearch(int S[], int N, int searchNum){
    for (int i = 0; i < N; i++)
    {
        if (compare(S[i], searchNum)==0)
            return i;
    }
    printf("No found in List\n");
    return -1;
}

int binarySearch(int S[], int left, int right, int searchNum){
    int mid;
    if (left > right)return -1;
    else{
        mid = (int)((left+right)/2);
        if (S[mid]==searchNum) return mid;
        else if (S[mid]<searchNum)return binarySearch(S, mid+1, right, searchNum);
        else return binarySearch(S, left, mid-1, searchNum);
    }
}

int main(){
    int searchNum  = 7;
    int S[] = {1,3,7,9,10,20};
    printf("리스트의 합: %d\n",sum(S,6));
    printf("리스트의 최대값: %d\n",findMax(S,6));
    printf("Search number: %d의 위치(순차탐색): %d\n",searchNum, sequentialSearch(S,6,searchNum));
    printf("Search number: %d의 위치(이진탐색): %d\n",searchNum, binarySearch(S,0,6,searchNum));
    return 0;
}