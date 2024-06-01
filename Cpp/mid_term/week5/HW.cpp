#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Employee
{
private:
    string m_name, m_position; // 이름, 직급
    int m_position_level; // 직급 레벨
    int m_years; // 총 근무연수
    int m_allowance; // 수당
    int m_basic_salary[6], m_gross_salary; // 기본급, 총 급여
public:
    Employee();
    Employee(string name, string position, int year);
    void Set_Name(string name);
    bool Set_Position(string position );
    void Set_Year(int Year);
    string Get_Name();
    string Get_Postion();
    int Get_Year();
    int Get_Salary();
    int Compute_Salary();
    void Print_Result();
};

Employee::Employee()
{
    m_allowance = 100000;
    int salary = 2000000;
    for (int i = 0; i < 6; i++)
    {
        m_basic_salary[i] = salary;
        salary += 500000;
    }
}

Employee::Employee(string name, string position, int year)
{
    m_name = name, Set_Position(position), m_years = year;
    m_allowance = 100000;
    int salary = 2000000;
    for (int i = 0; i < 6; i++)
    {
        m_basic_salary[i] = salary;
        salary += 500000;
    }
}

void Employee::Set_Name(string name)
{
    m_name = name;
}

bool Employee::Set_Position(string position)
{
    string position_list[6] = {"사원", "대리", "과장", "차장", "부장", "이사"};
    for (int i = 0; i < 6; i++)
    {
        if(position == position_list[i])
        {
            m_position_level = i;
            break;
        }
        else
        {
            m_position_level = -1;
        }   
    }
    if (m_position_level >= 0)
    {
        m_position = position;
        return true;
    }
    else {
        return false;

    }
}

void Employee::Set_Year(int Year)
{
    m_years = Year;
}

string Employee::Get_Name()
{
    return m_name;
}

string Employee::Get_Postion()
{
    return m_position;
}

int Employee::Get_Year()
{
    return m_years;
}

int Employee::Get_Salary()
{
    return m_gross_salary;
}

int Employee::Compute_Salary()
{
    if (m_years >= 5 && m_years < 10)
    {
        m_allowance *= 5;
    }
    else if (m_years >= 10 && m_years < 20)
    {
        m_allowance *= 10;
    }
    else if (m_years >= 20 && m_years < 30)
    {
        m_allowance *= 20;
    }
    else if (m_years >= 30)
    {
        m_allowance *= 30;
    }
    m_gross_salary = m_basic_salary[m_position_level] + (50000 * m_years) + m_allowance;  
    return m_gross_salary; 
}

void Employee::Print_Result()
{
    cout << m_name << " " << m_position <<"의 총 근무 년수는 "<< m_years << "년입니다.\n";
    cout << m_name << " " << m_position <<"의 봉급은 "<< m_gross_salary << "원 입니다.\n";
}

int main(){
    Employee ob1[3] = {Employee("홍길동", "과장", 17), Employee("장길산", "부장", 23), Employee("임꺽정", "이사", 34) };
    Employee *ob2;
    ob2 = new Employee;
    Employee *P;
    P = ob1;
    string name, position;
    int years;

    for (int i = 0; i < 3; i++)
    {
        P->Compute_Salary();
        P++->Print_Result();
        cout<<endl;
    }
    
    cout << "종업원의 이름을 입력하세요. : ";
    cin >> name;
    ob2->Set_Name(name);
    
    cout << "종업원의 직급을 입력하세요. : ";
    cin >> position;
    while (ob2->Set_Position(position) == false)
    {
        cout << "** 에러 발생. 사원, 대리, 과장, 차장, 부장, 이사 중에서 입력하세요 **" << endl << endl;
        cout << "종업원의 직급을 입력하세요. : ";
        cin >> position;
    }
    
    cout << "종업원의 근무 년수를 입력하세요. : ";
    cin >> years;
    ob2->Set_Year(years);

    cout << ob2->Get_Name() <<" "<<ob2->Get_Postion()<<"의 총 근무 년수는 "<<ob2->Get_Year()<<"년 입니다.\n";
    cout << ob2->Get_Name() <<" "<<ob2->Get_Postion()<<"의 봉급은 "<<ob2->Compute_Salary()<<"원 입니다.\n";
    
    delete ob2;
    
    return 0;
}
