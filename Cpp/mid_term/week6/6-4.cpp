#include <iostream>
using namespace std;

class Student
{
    int m_score;
public:
    Student(int score)
    {
        m_score = score;
    }
    int Get_Score()
    {
        return m_score;
    }
};
int Square_Score(Student ob)
{
    return (ob.Get_Score() * ob.Get_Score());
}
int main(void)
{
    Student kim(50);
    cout << "점수 = " << kim.Get_Score() << endl;
    cout << "점수 제곱 = " << Square_Score(kim) << endl;
    
    return 0;
}