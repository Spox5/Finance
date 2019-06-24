#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Expense
{
    int expenseId, loggedUserId, dateYear, dateMonth, dateDay;
    string expenseItem, expenseDateText;
    int expenseAmount;

public:
    Expense (int expenseId = 0, int loggedUserId = 0, int dateYear = 0, int dateMonth = 0, int dateDay = 0,
            string expenseItem = "", string expenseDateText = "", int expenseAmount = 0)
    {
        this->expenseId = expenseId;
        this->loggedUserId = loggedUserId;
        this->dateYear = dateYear;
        this->dateMonth = dateMonth;
        this->dateDay = dateDay;
        this->expenseItem = expenseItem;
        this->expenseDateText = expenseDateText;
        this->expenseAmount = expenseAmount;
    }

    bool operator<(const Expense& val) const
    {
        if (dateYear < val.dateYear)
            return true;
        else if ((dateYear == val.dateYear) && (dateMonth < val.dateMonth))
            return true;
        else if ((dateYear == val.dateYear) && (dateMonth == val.dateMonth) && dateDay < val.dateDay)
            return true;
        else
            return false;
    }

    void setExpenseId(int newExpenseId);
    int getExpenseId();

    void setLoggedUserId(int newLoggedUserId);
    int getLoggedUserId();

    void setExpenseDateYear(int newDateYear);
    int getExpenseDateYear();

    void setExpenseDateMonth(int newDateMonth);
    int getExpenseDateMonth();

    void setExpenseDateDay(int newDateDay);
    int getExpenseDateDay();

    void setExpenseItem(string newItem);
    string getExpenseItem();

    void setExpenseDateText(string newDateTExt);
    string getExpenseDateText();

    void setExpenseAmount(int newAmount);
    int getExpenseAmount();

};

#endif
