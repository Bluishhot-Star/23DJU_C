#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    ofstream fout;
    fout.open("test.txt", ios::out | ios::binary);
    if(!fout)
    {
        cout << "파일 열기 오류";
        return 0;
    }

    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    double phi = 3.14;
    fout.write((char*)&arr, sizeof(int)*10);
    fout.close();

    for (int i = 0; i < 10; i++)
    {
        arr[i] = 55;
    }
    phi = 8.14;

    cout << "*** 임의로 변경 후 내용 출력 ***" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl << phi << endl << endl;

    ifstream fin("test.txt", ios::in | ios::binary);
    if (!fin)
    {
        cout << "파일 읽기 오류";
        return 0;
    }
    fin.read((char*)&arr, sizeof(int)*10);
    fin.read((char*)&phi, sizeof(double));
    cout << "*** 파일에 저장된 내용 출력 ***" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl << phi << endl;

    fin.close();

    return 0;
}
