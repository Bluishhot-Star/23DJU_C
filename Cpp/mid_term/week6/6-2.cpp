#include <iostream>
using namespace std;

class Student
{
private:
    int m_id;
    int m_score;
public:
    Student(int id, int score);
    void Show_Student();
    void Add_Score(int score);
    Student Max_Student(Student &ob);
};

Student::Student(int id, int score)
{
    m_id = id;
    m_score = score;
}

void Student::Show_Student()
{
    cout << "학번 = " << m_id << " : 점수 = " << m_score << "점\n";
}
void Student::Add_Score(int score)
{
    m_score += score;
}
Student Student::Max_Student(Student &ob)
{
    if (m_score > ob.m_score)
    {
        return *this;
    }
    else
    {
        return ob;
    }
}
int main(void)
{
    Student* max = new Student(0,0);
    Student arr[3] = {Student(20101111, 86), Student(20111111, 83), Student(20121111, 92)};
    arr[0].Add_Score(10);

    cout << "--- 배열 arr[] 멤버 데이터 값 ---\n";
    for (int i = 0; i < 3; i++)
    {
        arr[i].Show_Student();
    }

    *max = arr[0];
    for (int i = 0; i < 3; i++)
    {
        *max = max->Max_Student(arr[i]);
    }
    cout << "\n--- 배열 arr[] 객체 중 최대 점수자 ---\n";
    max->Show_Student();

    return 0;
    
    
    return 0;
}