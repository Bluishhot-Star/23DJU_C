#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1, str2, str3;

    cout << "첫 번째 문자열을 입력하세요 : ";
    getline(cin, str1);
    cout << "두 번째 문자열을 입력하세요 : ";
    getline(cin, str2);
    cout << '\n';

    // 문자열의 길이를 출력한다.
    cout << str1 << "의 문자열 길이는 " << str1.length() << " 바이트 이다.\n";
    cout << str2 << "의 문자열 길이는 " << str2.length() << " 바이트 이다.\n";

    // 문자열을 비교한다.
    if (str1 == str2)
    {
        cout << "두 문자열은 같다.\n";
    }
    else if (str1.compare(str2) < 0)
    {
        cout << str1 << "이 " << str2 << "보다 작다.\n";
    }
    else
    {
        cout << str1 << "이 " << str2 << "보다 크다.\n";
    }

    // 두 문자열을 연결한다.
    str3 = str1 + str2;
    cout << str3 << "\n";

    str3 = str1 + str2;

    // 문자열 str2를 문자열 str1에 복사한다.
    str1 = str2;
    cout << str1 << " " << str2 << "\n";

    return 0;
}