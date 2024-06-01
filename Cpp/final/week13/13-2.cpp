#include <iostream>
using namespace std;

template <class T>
class MyStack
{
private:
    int m_top_index;
    T m_data[20];
public:
    MyStack();
    void Push(T element);
    T Pop();
    T Peek();
};

template <class T>
MyStack<T>::MyStack()
{
    m_top_index = 0;
}

template <class T>
void MyStack<T>::Push(T element)
{
    if (m_top_index == 20)
    {
        cout << "The stack is full";
        return;
    }
    m_data[m_top_index++] = element;
}

template <class T>
T MyStack<T>::Pop()
{
    if (m_top_index == 0)
    {
        cout << "The stack is empty";
        return 0;
    }
    return m_data[--m_top_index];
}

template <class T>
T MyStack<T>::Peek()
{
    if (m_top_index == 0)
    {
        cout << "The stack is empty";
        return 0;
    }
    return m_data[m_top_index-1];
}


int main(void)
{
    MyStack<int> iStack;
    iStack.Push(4);
    iStack.Push(7);
    cout << iStack.Peek() << endl;
    cout << iStack.Pop() << endl;

    MyStack<double> *p = new MyStack<double>;
    p->Push(5.4);
    cout << p->Pop() << endl;
    cout << p->Peek() << endl;
    delete p;

    MyStack<char> cStack;
    cStack.Push('h');
    cout << cStack.Pop() << endl;
    return 0;
}