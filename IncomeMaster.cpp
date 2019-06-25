#include "IncomeMaster.h"
#include <algorithm>
void IncomeMaster::addIncome()
{
    Income income;
    string item, date, amountString;
    double amount;

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
        for (int charPosition = 0; charPosition < amountString.length(); charPosition++)
        {
            if (amountString[charPosition] == ',')
                amountString[charPosition] = '.';
        }
        amount = atof(amountString.c_str());
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

void IncomeMaster::showIncomesFromCurrentMonth()
{
    vector <Income> incomesToSort;

    int currentMonth, currentYear;
    currentMonth = auxiliaryFunctions.getMonth();
    currentYear = auxiliaryFunctions.getYear();

    for (int i = 0; i < incomes.size(); i++)
    {
        if (currentMonth == auxiliaryFunctions.getMonthFromDateText(incomes[i].getIncomeDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText()))
        {
            incomesToSort.push_back(incomes[i]);
        }
    }
    sort(incomesToSort.begin(), incomesToSort.end());
    system("cls");
    cout << "Bilans z biezacego miesiaca:" << endl << endl;
    for (int i = 0; i < incomesToSort.size(); i++)
    {
        cout << incomesToSort[i].getIncomeDateText() << " - " << incomesToSort[i].getIncomeItem() << " - "
        << incomesToSort[i].getIncomeAmount() << endl << endl;
    }
    system("pause");
}

void IncomeMaster::showIncomesFromPreviousMonth()
{
    vector <Income> incomesToSort;

    int monthBefore;
    int currentYear;
    monthBefore = auxiliaryFunctions.getMonth() - 1;
    currentYear = auxiliaryFunctions.getYear();

    for (int i = 0; i < incomes.size(); i++)
    {
        if (monthBefore == auxiliaryFunctions.getMonthFromDateText(incomes[i].getIncomeDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText()))
        {
            incomesToSort.push_back(incomes[i]);
        }
    }
    sort(incomesToSort.begin(), incomesToSort.end());
    system("cls");
    cout << "Bilans z poprzedniego miesiaca:" << endl << endl;
    for (int i = 0; i < incomesToSort.size(); i++)
    {
        cout << incomesToSort[i].getIncomeDateText() << " - " << incomesToSort[i].getIncomeItem() << " - "
        << incomesToSort[i].getIncomeAmount() << endl << endl;
    }
    system("pause");
}

void IncomeMaster::showIncomesFromPeriod()
{
    vector <Income> incomesToSort;

    while (1)
    {
        cout << "Podaj date od ktorej rozpoczac wyswietlanie wynikow" << endl;
        string firstDate = auxiliaryFunctions.getDateFromUser();
        cout << "Podaj date na ktorej zakonczyc wyswietlanie wynikow" << endl;
        string secondDate = auxiliaryFunctions.getDateFromUser();

        if (auxiliaryFunctions.checkUsersDatesInShowPeriod(firstDate, secondDate) && auxiliaryFunctions.checkUserDate(firstDate)
                && auxiliaryFunctions.checkUserDate(secondDate))
        {
            int firstDateYear = auxiliaryFunctions.getYearFromDateText(firstDate);
            int firstDateMonth = auxiliaryFunctions.getMonthFromDateText(firstDate);
            int firstDateDay = auxiliaryFunctions.getDayFromDateText(firstDate);
            int secondDateYear = auxiliaryFunctions.getYearFromDateText(secondDate);
            int secondDateMonth = auxiliaryFunctions.getMonthFromDateText(secondDate);
            int secondDateDay = auxiliaryFunctions.getDayFromDateText(secondDate);

            bool checkDates = 0;

            for (int i = 0; i < incomes.size(); i++)
            {
                if (firstDateYear < auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText())
                        && secondDateYear > auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText()))
                         && firstDateMonth < auxiliaryFunctions.getMonthFromDateText(incomes[i].getIncomeDateText())
                         && secondDateMonth > auxiliaryFunctions.getMonthFromDateText(incomes[i].getIncomeDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(incomes[i].getIncomeDateText()))
                         && (firstDateMonth == auxiliaryFunctions.getMonthFromDateText(incomes[i].getIncomeDateText())
                             || secondDateMonth == auxiliaryFunctions.getMonthFromDateText(incomes[i].getIncomeDateText()))
                         && (firstDateDay <= auxiliaryFunctions.getDayFromDateText(incomes[i].getIncomeDateText())
                             || secondDateDay >= auxiliaryFunctions.getDayFromDateText(incomes[i].getIncomeDateText())))
                    checkDates = 1;

                if (checkDates == 1)
                    incomesToSort.push_back(incomes[i]);

                checkDates = 0;

            }
            sort(incomesToSort.begin(), incomesToSort.end());
            system("cls");
            cout << "Bilans z okresu: " << firstDate << " - " << secondDate << endl << endl;
            for (int i = 0; i < incomesToSort.size(); i++)
            {
                cout << incomesToSort[i].getIncomeDateText() << " - " << incomesToSort[i].getIncomeItem() << " - "
                << incomesToSort[i].getIncomeAmount() << endl << endl;
            }
            system("pause");
            return;
        }
        else
        {
            cout << "Podane daty sa w nieprawidlowej kolejnosci lub ich format jest niewlasciwy" << endl;
            system("pause");
            system("cls");
        }
    }
}
