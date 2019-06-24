#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include "XMLFile.h"
#include "Expense.h"
#include "AuxiliaryFunctions.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses: public XMLFile
{
    AuxiliaryFunctions auxiliaryFunctions;
    Expense getExpenseData(string expenseData);

public:
    FileWithExpenses(string fileName) : XMLFile(fileName) {};
    //void dopisz(string tekst);
    string getFileWithExpensesName();
    vector <Expense> loadFileWithExpenses(int loggedUserId);
    void saveExpenseToFile(Expense expense, int loggedUserId);
    int getLastExpenseIdFromFile();

};

#endif
