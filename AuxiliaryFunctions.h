#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

#include <iostream>
#include <sstream>
#include <time.h>
#include <algorithm>
#include "Markup.h"

using namespace std;

class AuxiliaryFunctions
{

public:

    string getCurrentDate();
    string getDateFromUser();
    bool checkUserDate(string userDate);

    int getUserIdFromData();
    int getIncomeIdFromData();
    string setUserDate();
    bool sortingPredicate();
    void showSum();
    bool checkLeapYear();
    bool checkAmountIsCorrect(string amount);
    int getLastIncomeIdFromFile();

    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int konwersjaStringNaInt(string liczba);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

};

#endif
