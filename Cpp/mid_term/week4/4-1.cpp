#include <iostream>
using namespace std;
class myclass {
    int data;
public:
    myclass(int x); //생성자
    int get_data(); //접근자
};
myclass::myclass(int x){ //생성자 리턴타입X
    data = x;
}
int myclass::get_data(){
    return data;
}
int main(){
    myclass ob(120); //create instance
    cout<<ob.get_data()<<endl;

    return 0;
}