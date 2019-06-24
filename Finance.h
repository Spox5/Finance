#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include "UserMaster.h"
#include "IncomeMaster.h"
#include "ExpenseMaster.h"

using namespace std;

class Finance
{
    UserMaster userMaster;
    IncomeMaster *incomeMaster;
    ExpenseMaster *expenseMaster;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;


public:

    Finance(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
    : userMaster(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses)
    {
        incomeMaster = NULL;
        expenseMaster = NULL;
    };
    ~Finance()
    {
        delete incomeMaster;
        incomeMaster = NULL;
        delete expenseMaster;
        expenseMaster = NULL;
    }
    void registerTheUser();
    void logInTheUser();
    void changeUserPassword();
    int getLoggedUserId();
    void logOutUser();
    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showIncomesFromPreviousMonth();
    void showIncomesFromPeriod();

};

#endif
