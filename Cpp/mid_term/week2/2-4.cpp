#include <iostream>
using namespace std;

int main() {
    int n;
    for ( n = 0; n > -10; n=n-7)
        cout << "n equals " << n << endl;
    cout << endl;

    int abc;
    for (  abc = 2; abc < 8; abc = abc + 2)
    {
        switch (abc)
        {
        case 4:
            cout << "Four" << endl;
        case 5:
            cout << "Five" << endl;
            break;
        case 6:
            cout << "Six" << endl;
            break;
        case 7:
            cout << "Seven" << endl;
            break;
        case 8:
            cout << "Eight" << endl;
            break;
        
        default:
            cout << "No Figures" << endl;
            break;
        }
    }
    cout << endl;

    int box[6] = {2,8,9,7,3,6}, x = 6; //6일 때 어짜피 continue돼서 indexing 오류 상관 없음
    while (x>0)
    {
        if (!(x%2))
        {
            x = x-1;
            continue;
        }
        cout << box[x] << endl;
        x = x-1;
    }

    return 0;
} 