#include <iostream>
#include <string>
using namespace std;

int func(int i){
    i = 5;
    cout <<"\n i에 5를 대입"<<endl;
    return 2*i + 3;
}

int main(){
    int i,j;
    i =3;
    cout<<"i = "<<i;
    j = func(i);
    cout <<"i = "<<i<<endl;
    cout <<"j = "<<j<<endl;
    return 0;
}