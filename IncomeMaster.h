#ifndef INCOMEMASTER_H
#define INCOMEMASTER_H

#include "FileWithUsers.h"
#include "FileWithIncomes.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class IncomeMaster
{
    const int LOGGED_USER_ID;
    FileWithIncomes fileWithIncomes;
    AuxiliaryFunctions auxiliaryFunctions;

public:
    IncomeMaster(string fileNameWithIncomes, int loggedUserId)
    : fileWithIncomes(fileNameWithIncomes),  LOGGED_USER_ID(loggedUserId)
    {
    incomes = fileWithIncomes.loadFileWithIncomes(LOGGED_USER_ID);
    };
    vector <Income> incomes;
    void addIncome();
};

#endif
