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
    int getLastExpenseIdFromFile();

    void breakExpenseDateText();
    vector <Expense> loadExpensesFromMainVectorToSortVector(vector <Expense> expenses);
    int getYearFromDateText(string dateToBreak);
    int getMonthFromDateText (string dateToBreak);
    int getDayFromDateText (string dateToBreak);


public:
    ExpenseMaster(string fileNameWithExpenses, int loggedUserId)
    : fileWithExpenses(fileNameWithExpenses),  LOGGED_USER_ID(loggedUserId)
    {
    expenses = fileWithExpenses.loadFileWithExpenses(LOGGED_USER_ID);
    };
    vector <Expense> expenses;
    void addExpense();
    void showExpensesFromCurrentMonth();
    void showExpensesFromPreviousMonth();
    void showExpensesFromPeriod();

};

#endif
