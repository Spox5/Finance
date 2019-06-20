#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

#include <iostream>
#include <sstream>
#include <time.h>
#include <algorithm>
#include "Income.h"
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

    int getUserIdFromData();
    int getIncomeIdFromData();
    string setUserDate();
    bool sortingPredicate(Income i1, Income i2);

    bool checkLeapYear();
    bool checkAmountIsCorrect(string amount);
    bool checkUsersDatesInShowPeriod(string firstDate, string secondDate);

    int getYearFromDateText(string dateToBreak);
    int getMonthFromDateText(string dateToBreak);
    int getDayFromDateText(string dateToBreak);

    int getLastIncomeIdFromFile();


    void showSum();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int konwersjaStringNaInt(string liczba);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

};

#endif
