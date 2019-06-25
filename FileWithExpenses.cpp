#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadFileWithExpenses(int loggedUserId)
{
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        cout << "Baza wydatkow jest pusta." << endl;
    }

    xml.FindElem("Expenses");
    xml.IntoElem();

    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if (loggedUserId == atoi(xml.GetElemContent().c_str()))
        {
            expense.setLoggedUserId(atoi(xml.GetElemContent().c_str()));
            xml.FindElem("ExpenseDate");
            expense.setExpenseDateText(xml.GetElemContent());

            expense.setExpenseDateYear(auxiliaryFunctions.getYearFromDateText(expense.getExpenseDateText()));
            expense.setExpenseDateMonth(auxiliaryFunctions.getMonthFromDateText(expense.getExpenseDateText()));
            expense.setExpenseDateDay(auxiliaryFunctions.getDayFromDateText(expense.getExpenseDateText()));

            xml.FindElem("ExpenseId");
            expense.setExpenseId(atoi(xml.GetElemContent().c_str()));
            xml.FindElem("ExpenseItem");
            expense.setExpenseItem(xml.GetElemContent());
            xml.FindElem("ExpenseAmount");
            expense.setExpenseAmount(atof(xml.GetElemContent().c_str()));
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}

void FileWithExpenses::saveExpenseToFile(Expense expense, int loggedUserId)
{
    CMarkup xml;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", loggedUserId);
    xml.AddElem("ExpenseDate", expense.getExpenseDateText());
    xml.AddElem("ExpenseItem", expense.getExpenseItem());
    ostringstream strs;
    strs << expense.getExpenseAmount();
    string str = strs.str();
    xml.AddElem("ExpenseAmount", str);

    xml.Save(XMLFile::getFileName());
}

string FileWithExpenses::getFileWithExpensesName()
{
    string fileName = XMLFile::getFileName();
    return fileName;
}

int FileWithExpenses::getLastExpenseIdFromFile()
{
    CMarkup xml;
    int lastExpenseIdFromFile = 0;

    bool fileExists = xml.Load(getFileWithExpensesName());

    if (!fileExists)
        return 1;
    else
    {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            lastExpenseIdFromFile = atoi(xml.GetElemContent().c_str()) + 1;
            xml.OutOfElem();
        }
    }
    return lastExpenseIdFromFile;
}
