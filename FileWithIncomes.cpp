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
        xml.FindElem("IncomeId");
        income.setIncomeId(atoi(xml.GetElemContent().c_str()));
        xml.FindElem("UserId");
        income.setLoggedUserId(atoi(xml.GetElemContent().c_str()));
        xml.FindElem("IncomeDate");
        income.setDateText(xml.GetElemContent());
        xml.FindElem("IncomeItem");
        income.setItem(xml.GetElemContent());
        xml.FindElem("IncomeAmount");
        income.setAmount(atoi(xml.GetElemContent().c_str()));
        xml.OutOfElem();
        incomes.push_back(income);
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
    xml.AddElem("Date", income.getDateText());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());

    xml.Save(XMLFile::getFileName());
}
