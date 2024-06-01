#include <iostream>
using namespace std;

int main(void)
{
    int num;
    cout << "숫자를 입력하세요 : ";
    cin >> num;
    for (int i = 0; i < 9; i++)
    {
        cout << num << " * " << i+1 << " = " << num*(i+1) << endl;
    }
    
    return 0;
}