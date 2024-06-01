#include <iostream>
using namespace std;

int main(void)
{
    int num = 0, sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << "번째 정수 입력 : ";
        cin >> num; // 다음 줄 이동 됨
        sum += num;
     }
    cout << "합계 : " << sum << endl;
    
    return 0;
}