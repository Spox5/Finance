#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadFileWithIncomes(int loggedUserId)
{
    CMarkup xml;
    Income income;
    vector <Income> incomes;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        cout << "Baza wydatkow jest pusta." << endl;
    }

    xml.FindElem("Incomes");
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if (loggedUserId == atoi(xml.GetElemContent().c_str()))
        {
            income.setLoggedUserId(atoi(xml.GetElemContent().c_str()));
            xml.FindElem("IncomeDate");
            income.setIncomeDateText(xml.GetElemContent());

            income.setIncomeDateYear(auxiliaryFunctions.getYearFromDateText(income.getIncomeDateText()));
            income.setIncomeDateMonth(auxiliaryFunctions.getMonthFromDateText(income.getIncomeDateText()));
            income.setIncomeDateDay(auxiliaryFunctions.getDayFromDateText(income.getIncomeDateText()));

            xml.FindElem("IncomeId");
            income.setIncomeId(atoi(xml.GetElemContent().c_str()));
            xml.FindElem("IncomeItem");
            income.setIncomeItem(xml.GetElemContent());
            xml.FindElem("IncomeAmount");
            income.setIncomeAmount(atoi(xml.GetElemContent().c_str()));
            incomes.push_back(income);
        }

        xml.OutOfElem();
    }
    return incomes;
}

void FileWithIncomes::saveIncomeToFile(Income income, int loggedUserId)
{
    CMarkup xml;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", loggedUserId);
    xml.AddElem("IncomeDate", income.getIncomeDateText());
    //xml.AddElem("IncomeDateYear", income.getIncomeDateYear());
    //xml.AddElem("IncomeDateMonth", income.getIncomeDateMonth());
    //xml.AddElem("IncomeDateDay", income.getIncomeDateDay());
    xml.AddElem("IncomeItem", income.getIncomeItem());
    xml.AddElem("IncomeAmount", income.getIncomeAmount());

    xml.Save(XMLFile::getFileName());
}

string FileWithIncomes::getFileWithIncomesName()
{
    string fileName = XMLFile::getFileName();
    return fileName;
}

int FileWithIncomes::getLastIncomeIdFromFile()
{
    CMarkup xml;
    int lastIncomeIdFromFile = 0;

    bool fileExists = xml.Load(getFileWithIncomesName());

    if (!fileExists)
        return 1;
    else
    {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            lastIncomeIdFromFile = atoi(xml.GetElemContent().c_str()) + 1;
            xml.OutOfElem();
        }
    }
    return lastIncomeIdFromFile;
}
