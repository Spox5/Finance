#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

#include <iostream>
#include <sstream>
#include <time.h>
#include <algorithm>
#include "Income.h"
#include "Expense.h"
#include "Markup.h"

using namespace std;

class AuxiliaryFunctions
{

public:

    string getCurrentDate();
    int getMonth();
    int getYear();
    string getDateFromUser();
    bool checkUserDate(string userDate);
    bool checkAmountIsCorrect(string amount);
    bool checkUsersDatesInShowPeriod(string firstDate, string secondDate);
    int getYearFromDateText(string dateToBreak);
    int getMonthFromDateText(string dateToBreak);
    int getDayFromDateText(string dateToBreak);
    void showBalance(vector <Income> vector1ToSum, vector <Expense> vector2ToSum);
    string replaceCommaToDot(string stringToReplace);
};

#endif
