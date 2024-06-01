#include <iostream>
using namespace std;

int main(){
    int arr[5];
    int sum = 0;
    int i;

    cout << "5개의 정수를 입력하세요 : ";
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
        sum += arr[i];
    }
    double average = (double) sum / 5.0;
    cout << "배열의 내용 : ";
    for (  i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << "\n합계 : " << sum << "\n평균 : " << average << endl;
    return 0;
}