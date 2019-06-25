#ifndef EXPENSEMASTER_H
#define EXPENSEMASTER_H

#include "FileWithUsers.h"
#include "FileWithExpenses.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class ExpenseMaster
{
    const int LOGGED_USER_ID;
    FileWithExpenses fileWithExpenses;
    AuxiliaryFunctions auxiliaryFunctions;

public:
    ExpenseMaster(string fileNameWithExpenses, int loggedUserId)
    : fileWithExpenses(fileNameWithExpenses),  LOGGED_USER_ID(loggedUserId)
    {
    expenses = fileWithExpenses.loadFileWithExpenses(LOGGED_USER_ID);
    };
    vector <Expense> expenses;
    void addExpense();
};

#endif
