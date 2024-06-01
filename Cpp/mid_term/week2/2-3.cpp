#include <iostream>
using namespace std;

int main() {
    cout << "여러 가지 값을 출력하는 프로그램입니다." << endl << endl;

    int num;
    cout << "정수를 입력하세요.: ";
    cin >> num;
    cout << "입력된 정수는 " << num << "입니다." << endl << endl;
    
    char ch;
    cout << "문자를 입력하세요.: ";
    cin >> ch;
    cout << "입력된 문자는 " << ch << "입니다." << endl << endl;
    
    double db;
    cout << "실수를 입력하세요.: ";
    cin >> db;
    cout << "입력된 실수는 " << db << "입니다." << endl << endl;

    return 0;
} 