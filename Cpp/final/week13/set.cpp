#include <iostream>
#include <iomanip>
using namespace std;

ostream& setup(ostream &stream)
{
    stream.width(10);
    stream.precision(6);
    stream << setfill('#');
    return stream;
}

int main()
{
    cout << setup << 0.012345678;
    return 0;
}