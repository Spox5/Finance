#include "Finance.h"

using namespace std;

void Finance::registerTheUser()
{
    userMaster.registerTheUser();
}

void Finance::logInTheUser()
{
    userMaster.logInTheUser();
    if (userMaster.checkIfUserIsLogIn())
    {
        incomeMaster = new IncomeMaster(FILE_NAME_WITH_INCOMES, userMaster.getLoggedUserId());
        expenseMaster = new ExpenseMaster(FILE_NAME_WITH_EXPENSES, userMaster.getLoggedUserId());
    }
}

void Finance::changeUserPassword()
{
    userMaster.changeUserPassword();
}

int Finance::getLoggedUserId()
{
    userMaster.getLoggedUserId();
}

void Finance::addIncome()
{
    incomeMaster->addIncome();
}

void Finance::addExpense()
{
    expenseMaster->addExpense();
}

void Finance::showBalanceFromCurrentMonth()
{
    AuxiliaryFunctions auxiliaryFunctions;
    vector <Income> incomesToSort;
    vector <Expense> expensesToSort;

    for (int i = 0; i < incomeMaster->incomes.size(); i++)
    {
        if (auxiliaryFunctions.getMonth() == auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                && auxiliaryFunctions.getYear() == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
        {
            incomesToSort.push_back(incomeMaster->incomes[i]);
        }
    }
    sort(incomesToSort.begin(), incomesToSort.end());

    for (int i = 0; i < expenseMaster->expenses.size(); i++)
    {
        if (auxiliaryFunctions.getMonth() == auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                && auxiliaryFunctions.getYear() == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
        {
            expensesToSort.push_back(expenseMaster->expenses[i]);
        }
    }
    sort(expensesToSort.begin(), expensesToSort.end());

    system("cls");
    cout << "Bilans z biezacego miesiaca:" << endl << endl;

    auxiliaryFunctions.showBalance(incomesToSort, expensesToSort);
}

void Finance::showIncomesFromPreviousMonth()
{
    AuxiliaryFunctions auxiliaryFunctions;
    vector <Income> incomesToSort;
    vector <Expense> expensesToSort;

    int monthBefore;
    int currentYear;
    monthBefore = auxiliaryFunctions.getMonth() - 1;
    currentYear = auxiliaryFunctions.getYear();

    for (int i = 0; i < incomeMaster->incomes.size(); i++)
    {
        if (monthBefore == auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
        {
            incomesToSort.push_back(incomeMaster->incomes[i]);
        }
    }
    sort(incomesToSort.begin(), incomesToSort.end());

    for (int i = 0; i < expenseMaster->expenses.size(); i++)
    {
        if (monthBefore == auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
        {
            expensesToSort.push_back(expenseMaster->expenses[i]);
        }
    }
    sort(expensesToSort.begin(), expensesToSort.end());

    system("cls");
    cout << "Bilans z poprzedniego miesiaca:" << endl << endl;

    auxiliaryFunctions.showBalance(incomesToSort, expensesToSort);
}

void Finance::showIncomesFromPeriod()
{
    AuxiliaryFunctions auxiliaryFunctions;
    vector <Income> incomesToSort;
    vector <Expense> expensesToSort;

    while (1)
    {
        cout << "Podaj date od ktorej rozpoczac wyswietlanie wynikow" << endl;
        string firstDate = auxiliaryFunctions.getDateFromUser();
        cout << "Podaj date na ktorej zakonczyc wyswietlanie wynikow" << endl;
        string secondDate = auxiliaryFunctions.getDateFromUser();

        if (auxiliaryFunctions.checkUsersDatesInShowPeriod(firstDate, secondDate) && auxiliaryFunctions.checkUserDate(firstDate)
                && auxiliaryFunctions.checkUserDate(secondDate))
        {

            bool checkDates = 0;

            for (int i = 0; i < incomeMaster->incomes.size(); i++)
            {
                if (auxiliaryFunctions.getYearFromDateText(firstDate) < auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                        && auxiliaryFunctions.getYearFromDateText(secondDate) > auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                    checkDates = 1;
                else if ((auxiliaryFunctions.getYearFromDateText(firstDate) == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                          || auxiliaryFunctions.getYearFromDateText(secondDate) == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                         && auxiliaryFunctions.getMonthFromDateText(firstDate) < auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                         && auxiliaryFunctions.getMonthFromDateText(secondDate) > auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                    checkDates = 1;
                else if ((auxiliaryFunctions.getYearFromDateText(firstDate) == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                          || auxiliaryFunctions.getYearFromDateText(secondDate) == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                         && (auxiliaryFunctions.getMonthFromDateText(firstDate) == auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                             || auxiliaryFunctions.getMonthFromDateText(secondDate) == auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                         && (auxiliaryFunctions.getDayFromDateText(firstDate) <= auxiliaryFunctions.getDayFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                         && auxiliaryFunctions.getDayFromDateText(secondDate) >= auxiliaryFunctions.getDayFromDateText(incomeMaster->incomes[i].getIncomeDateText())))
                    checkDates = 1;

                if (checkDates == 1)
                    incomesToSort.push_back(incomeMaster->incomes[i]);

                checkDates = 0;
            }
            sort(incomesToSort.begin(), incomesToSort.end());

            for (int i = 0; i < expenseMaster->expenses.size(); i++)
            {
                if (auxiliaryFunctions.getYearFromDateText(firstDate) < auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                        && auxiliaryFunctions.getYearFromDateText(secondDate) > auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                    checkDates = 1;
                else if ((auxiliaryFunctions.getYearFromDateText(firstDate) == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                          || auxiliaryFunctions.getYearFromDateText(secondDate) == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                         && auxiliaryFunctions.getMonthFromDateText(firstDate) < auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                         && auxiliaryFunctions.getMonthFromDateText(secondDate) > auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                    checkDates = 1;
                else if ((auxiliaryFunctions.getYearFromDateText(firstDate) == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                          || auxiliaryFunctions.getYearFromDateText(secondDate) == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                         && (auxiliaryFunctions.getMonthFromDateText(firstDate) == auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                             || auxiliaryFunctions.getMonthFromDateText(secondDate) == auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                         && (auxiliaryFunctions.getDayFromDateText(firstDate) <= auxiliaryFunctions.getDayFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                         && auxiliaryFunctions.getDayFromDateText(secondDate) >= auxiliaryFunctions.getDayFromDateText(expenseMaster->expenses[i].getExpenseDateText())))
                    checkDates = 1;

                if (checkDates == 1)
                    expensesToSort.push_back(expenseMaster->expenses[i]);

                checkDates = 0;
            }
            sort(expensesToSort.begin(), expensesToSort.end());

            system("cls");
            cout << "Bilans z okresu: " << firstDate << " - " << secondDate << endl << endl;

            auxiliaryFunctions.showBalance(incomesToSort, expensesToSort);
        }
        else
        {
            cout << "Podane daty sa w nieprawidlowej kolejnosci lub ich format jest niewlasciwy" << endl;
            system("pause");
            system("cls");
        }
    }
}

void Finance::logOutUser()
{
    userMaster.logOutUser();
    delete incomeMaster;
    incomeMaster = NULL;
    delete expenseMaster;
    expenseMaster = NULL;
}
