#include <iostream>
#include "atm.h"
using namespace std;


int main(void)
{
    Acclist* Bank = createlist();
    int program = 1;
    while (program)
    {
        int choice = ShowMenu();
        switch (choice)
        {
        case 1:
        {
            node* newAcc = createnode();
            newAcc->acc = createAcc();
            Bank->appendAcc(newAcc);
            break;
        }
        case 2:
        {
            node* tempnode = Bank->searchAcc();
            if (tempnode)
                tempnode->acc->inputCash();
            else
                noneAccAlert();
            break;
        }
        case 3:
        {
            node* tempnode = Bank->searchAcc();
            if (tempnode)
                tempnode->acc->outputCash();
            else
                noneAccAlert();
            break;
        }
        case 4:
        {
            node* tempnode = Bank->searchAcc();
            if (tempnode)
                tempnode->acc->printAcc();
            else
                noneAccAlert();
            break;
        }
        case 5:
        {
            cout << "프로그램을 종료합니다."<< endl;
            program = 0;
            break;
        }
        case 0:
        {
            Bank->printList();
            break;
        }
        default:
        {
            cout << "다시 입력하세요!" << endl;
            break;
        }
        }
    }
    return 0;

    Bank->ReleaseList();
}

