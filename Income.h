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
    string item, dateText;
    int amount;

public:
    Income (int incomeId = 0, int loggedUserId = 0, int dateYear = 0, int dateMonth = 0, int dateDay = 0,
            string item = "", string dateText = "", int amount = 0)
    {
        this->incomeId = incomeId;
        this->loggedUserId = loggedUserId;
        this->dateYear = dateYear;
        this->dateMonth = dateMonth;
        this->dateDay = dateDay;
        this->item = item;
        this->dateText = dateText;
        this->amount = amount;
    }

    void setIncomeId(int newIncomeId);
    int getIncomeId();

    void setLoggedUserId(int newLoggedUserId);
    int getLoggedUserId();

    void setDateYear(int newDateYear);
    int getDateYear();

    void setDateMonth(int newDateMonth);
    int getDateMonth();

    void setDateDay(int newDateDay);
    int getDateDay();

    void setItem(string newItem);
    string getItem();

    void setDateText(string newDateTExt);
    string getDateText();

    void setAmount(int newAmount);
    int getAmount();

};

#endif
