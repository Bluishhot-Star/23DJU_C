#include <iostream>
#include <string>
using namespace std;

class Dogs
{
private:
    string m_breed;
protected:
    int m_age;
public:
    Dogs(string breed, int age)
    {
        m_breed = breed;
        m_age = age;
    }
    string Get_Breed()
    {
        return m_breed;
    }
};

class Name
{
protected:
    string m_name;
    string m_parent;
    char m_gender;
    void Print_Name();
public:
    Name(string name, string parent, char gender)
    {
        m_name = name;
        m_parent = parent;
        m_gender = gender;
    }
};

void Name::Print_Name()
{
    cout << "이름 : " << m_name << endl;
}

class PetDogs : public Dogs, protected Name
{
private:
    double m_weight;
    int m_lifespan;
public:
    PetDogs(string breed, int age, string name, string parent, char gender, double weight, int lifespan) : Dogs(breed, age), Name(name, parent, gender)
    {
        m_weight = weight;
        m_lifespan = lifespan;
    }
    void Print_Pet();
};

void PetDogs::Print_Pet()
{
    string gender_type[2] = {"암컷", "수컷"};
    cout << "품 종 : " << Get_Breed() << endl;
    cout << "나 이 : " << m_age << endl;
    Print_Name();
    cout << "성 별 : ";
    switch (m_gender)
    {
    case 'F':
        cout << gender_type[0] << endl;
        break;
    case 'M':
        cout << gender_type[1] << endl;
    }
    cout << "평균수명 : " << m_lifespan << "년\n";
    cout << "부 모 : " << m_parent << '\n';
    cout << "몸무게 : " << m_weight << "Kg" << endl;
}

int main()
{
    PetDogs pug("퍼그", 4, "퍼글이", "퍼야+퍼냐", 'M', 2.5, 13);

    pug.Print_Pet();

    return 0;
}