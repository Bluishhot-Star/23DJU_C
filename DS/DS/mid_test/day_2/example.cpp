#include <stdio.h>
#include <time.h>
#define MAX_SIZE 30001
#define ITERATIONS 23
#define SWAP(x, y, t) ((t)=(x), (x)=(y),(y)=(t))

void sort(int list[], int n){
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (  j = 0; j < n; j++)
        {
            if(list[j] < list[min])
                min = j;
            SWAP(list[i], list[min], temp);
        }
    }
    
}

int main() {
    int i, j;
    int list[MAX_SIZE];
    int sizelist[] = {0,10,30,50,70,90,100,300,500,700,900,1000,3000,5000,7000,9000,
    11000,13000,15000,17000,19000,21000,30000}; // 데이터들

    clock_t start, stop; //
    double duration;

    printf("\t n\t time\n");
    for (i = 0; i < ITERATIONS; i++)
    {
        for (  j = 0; j < sizelist[i]; j++)
        {
            list[j] = sizelist[i] - j;
            start = clock(); //시작 전 시간
            sort(list, sizelist[i]); // 정렬대상 시작주소, 데이터
            stop = clock(); // 끝낸 후 시간

            duration = (double)(stop - start) / CLOCKS_PER_SEC; //1초는 1000개의 clock tick으로 이뤄짐 // 초단위로 표현
            printf("%10d \t %10.5f\n", sizelist[i], duration);
        }

    }
    


    return 0;
}