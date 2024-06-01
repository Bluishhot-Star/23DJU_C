#include <iostream>
using namespace std;

class A
{
private:
    char *s;
public:
    A(){s = NULL;}
    ~A(){if (s) {cout<<1<<endl;   delete(s);}   cout << "FREE"<<endl;}
    void show() {cout << s << "\n";}
    void set(char *str);
};

void A::set(char *str)
{
    s = new char(strlen(str));
    strcpy(s, str);
}

A input()
{
    char s[80]; A str;
    cout << "Enter a string :";
    cin >> s;
    str.set(s);
    return str;
}



int main(void)
{
    A ob;
    ob = input();
    ob.show();
    
   return 0;
}
