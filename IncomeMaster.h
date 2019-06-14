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
    int getLastIncomeIdFromFile();
    vector <Income> incomes;


public:
    IncomeMaster(string fileNameWithIncomes, int loggedUserId)
    : fileWithIncomes(fileNameWithIncomes),  LOGGED_USER_ID(loggedUserId)
    {
    incomes = fileWithIncomes.loadFileWithIncomes(LOGGED_USER_ID);
    };

    void addIncome();
    vector <Income> loadIncomesFromMainVectorToSortVector(vector <Income> incomes);


};

#endif*/
