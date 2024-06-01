#include <iostream>
using namespace std;

void swap(int* num1, int* num2);
void swap(char* c1, char* c2);
void swap(double* d1, double* d2);

int main(void)
{
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    cout << num1 << ' ' << num2 << endl;

    char c1 = 'A', c2 = 'B';
    swap(&c1, &c2);
    cout << c1 << ' ' << c2 << endl;

    double d1 = 1.111, d2 = 5.555;
    swap(&d1, &d2);
    cout << d1 << ' ' << d2 << endl;



    return 0;
}

void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void swap(char* c1, char* c2)
{
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}
void swap(double* d1, double* d2)
{
    double temp = *d1;
    *d1 = *d2;
    *d2 = temp;
}