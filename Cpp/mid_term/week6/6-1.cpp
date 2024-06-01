#include <iostream>
using namespace std;

class myclass
{
private:
    int n;
public:
    myclass(int i);
    void Set_n(int i);
    int Get_n();
};

myclass::myclass(int i)
{
    n = i;
}

void myclass::Set_n(int i)
{
    n = i;
}
int myclass::Get_n()
{
    return n;
}

void Sqr_It_Address(myclass *ob)
{
    ob->Set_n(ob->Get_n() * ob->Get_n());
    cout << "ob 복사본의 n 값은 " << ob->Get_n() << "\n";
}

void Sqr_It_Reference(myclass &ob)
{
    ob.Set_n(ob.Get_n() * ob.Get_n());
    cout << "ob 복사본의 n 값은 " << ob.Get_n() << "\n";
}

void Sqr_It_Value(myclass ob)
{
    ob.Set_n(ob.Get_n() * ob.Get_n());
    cout << "ob 복사본의 n 값은 " << ob.Get_n() << "\n";
}

int main(void)
{
    myclass ob(10);
    
    Sqr_It_Value(ob);
    cout << "값 인도 후 ob의 n값은 " << ob.Get_n() << "\n";
    
    Sqr_It_Address(&ob);
    cout << "주소 인도 후 ob의 n값은 " << ob.Get_n() << "\n";
    
    ob.Set_n(10);
    Sqr_It_Reference(ob);
    cout << "참조 인도 후 ob의 n값은 " << ob.Get_n() << "\n";
    
    return 0;
}