#pragma once
#include <iostream>
#include <string>
using namespace std;

int ShowMenu();
//==================(Account)
class Account
{
private:
    int ID;
    string name;
    int money;
public:
    void printAcc();
    int getID();
    void setAcc(int ID, string name, int money);
    void outputCash();
    void inputCash();
};
inline int Account::getID()
{
    return ID;
}

//계좌 생성
Account* createAcc();

//==================(node)
class node
{
public:
    Account* acc;
    node* link;
    node();
    // void createnode();
};


node* createnode();


//==================(Acclist)
class Acclist
{
private:
    node* head;
    int count;
public:
    Acclist();
    void appendAcc(node* newAcc);
    node* searchAcc();
    void printList();
    void ReleaseList();
};


Acclist* createlist();

void noneAccAlert();