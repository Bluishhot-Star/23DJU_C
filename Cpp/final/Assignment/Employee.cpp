#include <iostream>
#include <string>
using namespace std;

/*=======================(Employee)=======================*/
class Employee
{
protected:
    string m_name;
    int m_payRate;
    float m_hoursWorked;
public:
    Employee(string name = "NONE", int payRate = 0, float hoursWorked = 0.0);
    void Set_Name(string name);
    void Set_PayRate(int payRate);
    void Set_hoursWorked(float hoursWorked);

    string Get_Name();
    int Get_PayRate();
    float Get_hoursWorked();

    float Compute_Salary();
    void Print_Info();
};
Employee::Employee(string name, int payRate, float hoursWorked)
{
    m_name = name;    m_payRate = payRate;    m_hoursWorked = hoursWorked;
}
void Employee::Set_Name(string name) {m_name = name;}
void Employee::Set_PayRate(int payRate) {m_payRate = payRate;}
void Employee::Set_hoursWorked(float hoursWorked){m_hoursWorked = hoursWorked;}

string Employee::Get_Name(){return m_name;}
int Employee::Get_PayRate(){return m_payRate;}
float Employee::Get_hoursWorked(){return m_hoursWorked;}

float Employee::Compute_Salary(){return m_payRate * m_hoursWorked;}
void Employee::Print_Info()
{
    cout << "이름 : "<< m_name << endl;
    cout << "시간당 급여 : "<< m_payRate << "원" << endl;
    cout << "근무시간 : "<< m_hoursWorked << "시간" << endl;
}

/*=======================(Manager)=======================*/
class Manager : public Employee
{
    bool m_fullTime;
public:
    Manager(){m_fullTime = true;}
    Manager(string name, int payRate, float hoursWorked, bool fullTime):Employee(name, payRate, hoursWorked)
    {
        m_fullTime = fullTime;
    }

    bool Get_FullTime();
    void Set_FullTime(bool fullTime);
    float Compute_Salary();
    void Print_Info();
};

bool Manager::Get_FullTime(){return m_fullTime;}
void Manager::Set_FullTime(bool fullTime){m_fullTime = fullTime;}

float Manager::Compute_Salary()
{
    if(Get_FullTime())
    {
        m_hoursWorked = 40;
        return m_hoursWorked * m_payRate * 2;
    }
    else
    {
        return m_hoursWorked * m_payRate * 1.5;
    }
}
void Manager::Print_Info()
{
    cout << "이름 : "<< m_name << endl;
    cout << "시간당 급여 : "<< m_payRate << "원" << endl;
    if(Get_FullTime())
    {
        cout << "정규직 매니저" << endl;
        cout << "근무시간 40시간 고정" << endl;
    }
    else
    {
        cout << "비정규직 매니저" << endl;
        cout << "근무시간 : "<< m_hoursWorked << "시간" << endl;    
    }
    cout << "주급 : " << Compute_Salary() << "원" << endl;
}

int main(void)
{
    Employee arr[] = { Employee("홍길동", 7000, 34.0), Employee("장길산", 8000, 30.0), Employee("임꺽정", 9000, 27.0) };
    Employee* ptr = arr;
    cout << "<종업원 1, 2, 3>" << endl;
    for (int i = 0; i < 3; i++)
    {
        ptr->Print_Info();
        cout << "주급 : " << ptr->Compute_Salary() << "원" << endl << endl;
        ptr++;
    }
    
    cout << "<매니저1>" << endl;
    Manager *m1 = new Manager("정약용", 10000, 28.0, true);
    m1->Print_Info();
    cout << endl;
    
    cout << "***** 종업원2 PayRate 및 hours 변경 *****" << endl;
    arr[1].Set_PayRate(8500);
    arr[1].Set_hoursWorked(40.0);
    cout << "시간당 급여 : " << arr[1].Get_PayRate() << "원" << endl;
    cout << "근무 시간 : " << arr[1].Get_hoursWorked() << "시간" << endl;
    cout << "주급 : " << arr[1].Compute_Salary() << "원" << endl << endl;

    cout << "***** 매니저1 PayRate 및 hours 변경 *****" << endl;
    m1->Set_PayRate(11500);
    m1->Set_hoursWorked(35.0);
    m1->Compute_Salary();
    cout << "시간당 급여 : " << m1->Get_PayRate() << "원" << endl;
    cout << "근무 시간 " << m1->Get_hoursWorked() << "시간 고정" << endl;
    cout << "주급 : " << m1->Compute_Salary() << "원" << endl << endl;

    cout << "<매니저2>" << endl;
    Manager m2;
    m2.Print_Info();
    cout << endl;

    cout << "***** 매니저2 이름, PayRate 및 hours 변경 *****" << endl;
    m2.Set_Name("박문수");
    m2.Set_PayRate(12000);
    m2.Set_hoursWorked(26.5);
    m2.Set_FullTime(false);
    m2.Print_Info();

    delete m1;

    return 0;
}