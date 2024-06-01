#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(void)
{
    ofstream fout("test.txt");
    if(!fout)
    {
        cout << "출력 파일 열기 실패\n";
        return 1;
    }
    fout << 123.23 << " hello " << 100 << endl;
    fout.setf(ios::showpos);
    fout.setf(ios::fixed);
    fout << 100.0 << endl;
    fout << "abc\n" << endl;
    fout.unsetf(ios::fixed);
    fout << setw(6) << "ABCD" << setw(8) << "abcd\n";
    fout << setw(6) << 123 << endl;
    fout << setw(8) << setprecision(5) << 1.234567 << endl;

    fout << setw(5) << setfill('0') << 15 << endl;
    fout << hex << 123 << endl;
    fout.close();

    ifstream fin;
    fin.open("test.txt");

    if(!fin)
    {
        cout << "입력 파일 열기 실패\n";
        return 1;
    }
    int c;
    while ((c = fin.get()) != EOF)
    {
        cout << (char) c;
    }
    cout << endl;
    fin.close();
    return 0;
}