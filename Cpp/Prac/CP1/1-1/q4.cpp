#include <iostream>
using namespace std;

int main(void)
{
    int base = 50;
    float per = 0.12;
    int gross_salary = 0;
    int money;

    while (true)
    {
        cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        cin >> money;
        if (money == -1)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        gross_salary = base + (money*0.12);
        cout << "이번 달 급여 : " << gross_salary << "만원" << endl;
        
    }
    
    return 0;
}