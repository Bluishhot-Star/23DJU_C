#include <iostream>
#include <string>
using namespace std;

class Student
{
    static int m_count;
    string m_gender;
    int m_age;
public:
    Student(string gender = "NONE", int age = 0);
    ~Student();
    Student(const Student &s);
    int Get_Age(){return m_age;}
    string Get_Gender(){return m_gender;}
};

Student::Student(string gender, int age)
{
    m_count++;
    m_gender = gender;
    m_age = age;
    cout << m_gender << " 출석, 순번 : " << m_count << endl;
}

Student::Student(const Student &s)
{
    m_count++;
    m_gender = s.m_gender;
    m_age = s.m_age;
    cout << m_gender << " 복사생성자 호출됨, 순번 : " << m_count << endl;
}
Student::~Student()
{
    m_count--;
    cout << m_gender << " 소멸 : 남은 학생 수 : " << m_count << endl;
}

void Print_Student(Student s, string str)
{
    cout << "\n--- Print_Student() 함수 시작 ---\n";
    cout << str << " 객체는 (" << s.Get_Gender() << ")입니다.\n";
    cout << " 나이는 " << s.Get_Age() << "살 입니다.\n";
    cout << "--- Print_Student() 함수 종료 ---\n\n";
}
int Student::m_count = 0;
int main()
{
    Student stud1;
    Student stud2("여학생", 21);
    Student stud3("남학생", 23);
    cout << "\n--- main() 함수 시작 ---\n";

    cout << "stud1 객체의 성별은 (" << stud1.Get_Gender() << ")입니다.\n";
    Print_Student(stud1, "stud1");

    cout << "stud2 객체의 성별은 (" << stud2.Get_Gender() << ")입니다.\n";
    Print_Student(stud2, "stud2");

    cout << "stud3 객체의 성별은 (" << stud3.Get_Gender() << ")입니다.\n";
    Print_Student(stud3, "stud3");

    cout << "\n--- main() 함수 끝 ---\n";
    
    return 0;
}