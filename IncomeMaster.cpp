#include "IncomeMaster.h"

void IncomeMaster::addIncome()
{
    vector <Income> incomes;
    Income income;

    string item, date;
    int amount;

    cout << "Czy przychod dotyczy dnia dzisiejszego(t/n)." << endl;
    string dayChoice;
    while (cin >> dayChoice)
    {
        if (dayChoice == "t")
        {
            income.setDateText(auxiliaryFunctions.getCurrentDate());
            break;
        }
        else if (dayChoice == "n")
        {
            income.setDateText(auxiliaryFunctions.getDateFromUser());
            break;
        }
        else
            cout << "Nieprawidlowy wybor." << endl;
    }

    cout << "Podaj czego dotyczy przychod: " << endl;
    cin >> item;
    income.setItem(item);
    cout << "Podaj wysokosc przychodu: " << endl;
    cin >> amount;
    income.setAmount(amount);


    CMarkup xml;

    bool fileExists = xml.Load("Przychody.xml");

    if (!fileExists)
        income.setIncomeId(1);
    else
    {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("IncomeId");
            income.setIncomeId(atoi(xml.GetElemContent().c_str()) + 1);
            xml.OutOfElem();
        }
    }
    incomes.push_back(income);
    cout << "Nowy przychod zostal utworzony" << endl;
    system("pause");

    fileWithIncomes.saveIncomeToFile(income, LOGGED_USER_ID);
}
