#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "XMLFile.h"
#include "Income.h"
#include "AuxiliaryFunctions.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes: public XMLFile
{
    AuxiliaryFunctions auxiliaryFunctions;
    Income getIncomeData(string incomeData);

public:
    FileWithIncomes(string fileName) : XMLFile(fileName) {};
    //void dopisz(string tekst);
    string getFileWithIncomesName();
    vector <Income> loadFileWithIncomes(int loggedUserId);
    void saveIncomeToFile(Income income, int loggedUserId);
    int getLastIncomeIdFromFile();

};

#endif
