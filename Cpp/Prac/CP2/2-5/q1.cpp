#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point* Add = new Point;
    Add->xpos = p1.xpos + p2.xpos;
    Add->ypos = p1.ypos + p2.ypos;
    return *Add;
    // 반환형이 참조자일 때에는 return에 공간을 써주어야 한다.
    // 따라서 return 값으로 참조변수를 넣어줄 수 있다.
    // 이때 함수 내부에서 동적할당한 변수는 힙메모리에 있으므로 해당 변수를 참조하여 반환해도 된다.
    // (지역 변수일 경우에는 스택에서 해제가 되지만. 힙메모리는 함수를 종료해도 살아있다.)
}

int& Ref(int &ref)
{
    ref++;
    return ref;
}

int main(void)
{
    Point* A = new Point;
    A->xpos = 3;
    A->ypos = 20;
    Point* B = new Point;
    B->xpos = 5;
    B->ypos = 10;

    Point &pref = PntAdder(*A, *B);
    cout << pref.xpos << ' ' << pref.ypos << endl;

    
    return 0;
}