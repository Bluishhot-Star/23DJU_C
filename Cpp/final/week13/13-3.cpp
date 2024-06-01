#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

ostream &setup(ostream &stream)
{
    stream << setw(10);
    stream << setprecision(6);
    stream << setfill('#');
    return stream;
}

istream &getpass(istream &stream)
{
    cout << '\007';
    cout << "Enter password : ";
    return stream;
}

int main(void)
{
    string pw;
    do
    {
        cin >> getpass >> pw;
    } while (pw != "password");
    cout << "Login complete\n";
    cout << setup << 123.123456 << '\n';
    return 0;
}