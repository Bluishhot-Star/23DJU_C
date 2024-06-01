#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    // rand() % 100;
    // srand() % 100;
    srand(time(NULL)); // srand = 랜덤에 시드를 줌. time(NULL)로 지정시 시간 참조 이므로 계속 시드 바뀜
    cout << rand() % 10 <<endl; // %를 통해 원하는 숫자까지 -> %10 == 0~9
    
    return 0;
}