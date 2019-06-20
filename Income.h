#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class Income
{
    int incomeId, loggedUserId, dateYear, dateMonth, dateDay;
    string incomeItem, incomeDateText;
    int incomeAmount;

public:
    Income (int incomeId = 0, int loggedUserId = 0, int dateYear = 0, int dateMonth = 0, int dateDay = 0,
            string incomeItem = "", string incomeDateText = "", int incomeAmount = 0)
    {
        this->incomeId = incomeId;
        this->loggedUserId = loggedUserId;
        this->dateYear = dateYear;
        this->dateMonth = dateMonth;
        this->dateDay = dateDay;
        this->incomeItem = incomeItem;
        this->incomeDateText = incomeDateText;
        this->incomeAmount = incomeAmount;
    }

    void setIncomeId(int newIncomeId);
    int getIncomeId();

    void setLoggedUserId(int newLoggedUserId);
    int getLoggedUserId();

    void setIncomeDateYear(int newDateYear);
    int getIncomeDateYear();

    void setIncomeDateMonth(int newDateMonth);
    int getIncomeDateMonth();

    void setIncomeDateDay(int newDateDay);
    int getIncomeDateDay();

    void setIncomeItem(string newItem);
    string getIncomeItem();

    void setIncomeDateText(string newDateTExt);
    string getIncomeDateText();

    void setIncomeAmount(int newAmount);
    int getIncomeAmount();

};

#endif
