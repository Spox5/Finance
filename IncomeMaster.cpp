#include "IncomeMaster.h"
#include <algorithm>

void IncomeMaster::addIncome()
{
    Income income;
    string item, date, amountString;
    double amount = 0;

    cout << "Czy przychod dotyczy dnia dzisiejszego(t/n)." << endl;
    string dayChoice;
    while (cin >> dayChoice)
    {
        if (dayChoice == "t")
        {
            income.setIncomeDateText(auxiliaryFunctions.getCurrentDate());
            income.setIncomeDateYear(auxiliaryFunctions.getYearFromDateText(income.getIncomeDateText()));
            income.setIncomeDateMonth(auxiliaryFunctions.getMonthFromDateText(income.getIncomeDateText()));
            income.setIncomeDateDay(auxiliaryFunctions.getDayFromDateText(income.getIncomeDateText()));
            break;
        }
        else if (dayChoice == "n")
        {
            income.setIncomeDateText(auxiliaryFunctions.getDateFromUser());
            income.setIncomeDateYear(auxiliaryFunctions.getYearFromDateText(income.getIncomeDateText()));
            income.setIncomeDateMonth(auxiliaryFunctions.getMonthFromDateText(income.getIncomeDateText()));
            income.setIncomeDateDay(auxiliaryFunctions.getDayFromDateText(income.getIncomeDateText()));
            break;
        }
        else
            cout << "Nieprawidlowy wybor." << endl;
    }

    cout << "Podaj czego dotyczy przychod: " << endl;
    cin.sync();
    getline(cin>>ws, item);
    income.setIncomeItem(item);

    while(1)
    {
        cout << "Podaj wysokosc przychodu: " << endl;
        cin >> amountString;
        amount = atof(auxiliaryFunctions.replaceCommaToDot(amountString).c_str());
        if (auxiliaryFunctions.checkAmountIsCorrect(amountString))
        {
            income.setIncomeAmount(amount);
            break;
        }
    }
    income.setIncomeId(fileWithIncomes.getLastIncomeIdFromFile());
    incomes.push_back(income);
    cout << "Nowy przychod zostal utworzony" << endl;
    system("pause");

    fileWithIncomes.saveIncomeToFile(income, LOGGED_USER_ID);
}
