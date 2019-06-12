#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

#include <sstream>
#include <fstream>
#include "Markup.h"

using namespace std;

class AuxiliaryFunctions
{

public:

    int getUserIdFromData();
    int getIncomeIdFromData();
    string getCurrentDate();
    string setUserDate();
    bool checkUserDate();
    int checkNubmerOfDaysInMonth();
    bool sortingPredicate();
    void showSum();
    bool checkLeapYear();

    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int konwersjaStringNaInt(string liczba);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

};

#endif
