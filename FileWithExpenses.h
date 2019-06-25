#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include "XMLFile.h"
#include "Expense.h"
#include "AuxiliaryFunctions.h"

using namespace std;

class FileWithExpenses: public XMLFile
{
    AuxiliaryFunctions auxiliaryFunctions;
    string getFileWithExpensesName();

public:
    FileWithExpenses(string fileName) : XMLFile(fileName) {};
    vector <Expense> loadFileWithExpenses(int loggedUserId);
    void saveExpenseToFile(Expense expense, int loggedUserId);
    int getLastExpenseIdFromFile();

};

#endif
