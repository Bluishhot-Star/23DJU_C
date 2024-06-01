#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2, str3;

    cout << "첫 번째 문자열을 입력하세요 : ";
    getline(cin, str1);

    cout << "두 번째 문자열을 입력하세요 : ";
    getline(cin, str2);

    cout << '\n';

    cout << str1 << "의 문자열 길이는 " << str1.size() << " 바이트 이다.\n";
    cout << str2 << "의 문자열 길이는 " << str2.size() << " 바이트 이다.\n\n";

    int comp = str1.compare(str2);
    if (comp == 0)
    {
        cout << "두 문자열은 같다.\n";
    }
    else if (comp == -1)
    {
        cout << str1 << "이 " << str2 << "보다 작다.\n";
    }
    else
    {
        cout << str1 << "이 " << str2 << "보다 크다.\n";
    }
    
    str3 = str1.append(str2);
    cout << str3 << "\n";

    str3 = str2 + str1;
    cout << str3 << "\n";

    str2 = str1;
    cout << str1 << " " << str2 << "\n";
    return 0;
}