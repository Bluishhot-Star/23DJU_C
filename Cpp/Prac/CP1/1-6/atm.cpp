#include <iostream>
#include "atm.h"
using namespace std;

int ShowMenu()
{
    int choice = 0;
    cout << "\n------Menu------" << endl;
    cout << "1. 계좌개설\n2. 입 금\n3. 출 금\n4. 계좌정보 출력\n5. 프로그램 종료" << endl;
    cin >> choice;
    cout << endl;
    return choice;
}

Account* createAcc()
{
    int ID, money;
    string name;
    Account* p = new Account;
    cout << "\n[계좌개설]\n";
    cout << "계좌ID: ";
    cin >> ID;
    cout << "이  름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> money;
    p->setAcc(ID, name, money);
    cout << endl;
    return p;
}

void Account::setAcc(int ID, string name, int money)
{
    this->ID = ID, this->name = name, this->money = money;
}
void Account::printAcc()
{
    cout << "\n[계좌정보]\n";
    cout << "계좌ID: " << ID << endl;
    cout << "이  름: " << name << endl;
    cout << "입금액: " << money << endl;
}
void Account::inputCash()
{
    cout << "\n[입금]\n";
    int money = 0;
    cout << "입금액을 입력하세요: ";
    cin >> money;
    this->money += money;
    cout << "입금액: " << money << endl;
    cout << "잔  액: " << this->money<<endl;
}
void Account::outputCash()
{
    cout << "\n[출금]\n";
    int money = 0;
    cout << "출금액을 입력하세요: ";
    cin >> money;
    if (this-> money < money)
    {
        cout << "잔액이 부족합니다." << endl;
        cout << "잔  액: " << this->money;
        return;
    }
    else
    {
        this->money -= money;
        cout << "출금액: " << money <<endl;
        cout << "잔  액: " << this->money <<endl;
    }
}


//==================(Acclist)
Acclist::Acclist()
{
    head = nullptr;
    count = 0;
}

void Acclist::appendAcc(node* newAcc)
{
    if(newAcc != nullptr)
    {
        node* pNode = head;
        if (pNode == nullptr) //항이 없을 때
        {
            head = newAcc;
            count++;
        }
        else
        {
            while (pNode->link != nullptr)
            {
                pNode = pNode->link;
            }
            pNode->link = newAcc;
            count++;
        }
    }
}

node* Acclist::searchAcc()
{
    int tempID;
    cout << "계좌ID를 입력하세요 : ";
    cin >> tempID;
    node* pNode = head;
    while (pNode != nullptr)
    {
        if (tempID == pNode->acc->getID())
        {
            return pNode; //현재 노드 주소 반환
        }
        pNode = pNode->link;
    }
    return nullptr; // 널 반환
}


node::node()
{
    acc = nullptr;
    link = nullptr;
}

Acclist* createlist()
{
    Acclist* pList = new Acclist;
    return pList;
}

node* createnode()
{
    node* pNode = new node;
    return pNode;
}

void noneAccAlert()
{
    cout << endl << "=====에러=====" << endl;
    cout << "계좌를 찾을 수 없습니다." << endl;
}

void Acclist::printList()
{
    node* pNode = head;
    cout << "===모든 계좌 정보===";
    while (pNode != nullptr)
    {
        pNode->acc->printAcc();
        pNode = pNode->link;
    }
    getchar();
}

void Acclist::ReleaseList()
{
    node* pDelete = head;
    node* pNext = nullptr;
    while (pDelete)
    {
        pNext = pDelete->link;
        free(pDelete);
        pDelete = pNext;
    }
}