#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include "UserMaster.h"
#include "IncomeMaster.h"

using namespace std;

class Finance
{
    UserMaster userMaster;
    IncomeMaster *incomeMaster;
    const string FILE_NAME_WITH_INCOMES;


public:
    Finance(string fileWithUsersName)
    : userMaster(fileWithUsersName){};
    Finance(string fileNameWithUsers, string fileNameWithIncomes)
    : userMaster(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes)
    {
        incomeMaster = NULL;
    };
    ~Finance()
    {
        delete incomeMaster;
        incomeMaster = NULL;
    }
    void registerTheUser();
    void logInTheUser();
    void changeUserPassword();
    int getLoggedUserId();
    void logOutUser();
    void addIncome();
    /*
    void listaAdresatow();

    ;*/

};

#endif
