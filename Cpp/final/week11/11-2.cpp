#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    enum SEX { male, female };
    string m_name;
    int m_age;
    SEX m_sex;
public:
    Person();
    Person( string name, int age, SEX sex);
    void Print_Info();
};

Person::Person()
{
    m_age = 0;
    m_sex = male;
}

Person::Person( string name, int age, SEX sex)
{
    m_name = name;
    m_age = age;
    m_sex = sex;
}
void Person::Print_Info()
{
    cout << "이름 : " << m_name << ", " << "나이 : " << m_age;
}

class Man : public Person
{
public:
    Man() {}
    Man(string name, int age);
    void Print_Info();
};
Man::Man(string name, int age) : Person(name, age, male){}

void Man::Print_Info()
{
    Person::Print_Info();
    cout << ", 성별 : M \n";
}

class Woman: public Person
{
public:
    Woman() {}
    Woman(string name, int age);
    void Print_Info();
};
Woman::Woman(string name, int age) : Person(name, age, female){}

void Woman::Print_Info()
{
    Person::Print_Info();
    cout << ", 성별 : F \n";
}

int main(void)
{
    Man m1("정우성", 49);
    m1.Print_Info();

    Woman w1("이효리", 43);
    w1.Print_Info();
    return 0;
}