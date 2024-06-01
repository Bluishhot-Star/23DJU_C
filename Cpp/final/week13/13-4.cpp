#include <iostream>
using namespace std;

int main(void)
{
    cout << 123.23 << " hello " << 100 << '\n';
    cout << 10 << ' ' << -10 << '\n';
    cout << 100.0 << "\n\n";

    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout.setf(ios::scientific);
    cout << 123.23 << " hello " << 100 << '\n';
    cout.setf(ios::showpos);
    cout << 10 << ' ' << -10 << '\n';
    cout.unsetf(ios::scientific);
    cout.setf(ios::showpoint | ios::fixed);
    cout << 100.0 << "\n\n";

    cout.setf(ios::uppercase | ios::showbase);
    cout.setf(ios::hex);
    cout << 88 << '\n';
    cout.unsetf(ios::uppercase);
    cout << 88 << "\n\n";
    cout.unsetf(ios::showpos | ios::showpoint | ios::fixed);

    cout.width(10);
    cout << "Hello" << '\n';
    cout.fill('#');
    cout.setf(ios::left);
    cout.width(10);
    cout << "Hello" << '\n';
    cout.width(10);
    cout.precision(8);
    cout << 123.230045 << '\n';
    cout.width(10);
    cout.precision(6);
    cout << 0.003456789 << '\n';


    return 0;
}