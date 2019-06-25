#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include "XMLFile.h"
#include "Income.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class FileWithIncomes: public XMLFile
{
    AuxiliaryFunctions auxiliaryFunctions;
    string getFileWithIncomesName();

public:
    FileWithIncomes(string fileName) : XMLFile(fileName) {};
    vector <Income> loadFileWithIncomes(int loggedUserId);
    void saveIncomeToFile(Income income, int loggedUserId);
    int getLastIncomeIdFromFile();

};

#endif
