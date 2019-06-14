#include "IncomeMaster.h"

void IncomeMaster::addIncome()
{
    vector <Income> incomes;
    Income income;
    string item, date, amountString;
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
    cin.sync();
    getline(cin>>ws, item);
    income.setItem(item);

    while(1)
    {
        cout << "Podaj wysokosc przychodu: " << endl;
        cin >> amountString;
        amount = atoi(amountString.c_str());
        if (auxiliaryFunctions.checkAmountIsCorrect(amountString))
        {
            income.setAmount(amount);
            break;
        }
    }
    income.setIncomeId(fileWithIncomes.getLastIncomeIdFromFile());
    incomes.push_back(income);
    cout << "Nowy przychod zostal utworzony" << endl;
    system("pause");

    fileWithIncomes.saveIncomeToFile(income, LOGGED_USER_ID);
}

vector <Income> IncomeMaster::loadIncomesFromMainVectorToSortVector(vector <Income> incomes)
{
    vector <Income> sortVectorWithIncomes;

}
