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

    int currentMonth;
    int currentYear;
    currentMonth = auxiliaryFunctions.getMonth();
    currentYear = auxiliaryFunctions.getYear();

    for (int i = 0; i < incomeMaster->incomes.size(); i++)
    {
        if (currentMonth == auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
        {
            incomesToSort.push_back(incomeMaster->incomes[i]);
        }
    }
    sort(incomesToSort.begin(), incomesToSort.end());

    for (int i = 0; i < expenseMaster->expenses.size(); i++)
    {
        if (currentMonth == auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
        {
            expensesToSort.push_back(expenseMaster->expenses[i]);
        }
    }
    sort(expensesToSort.begin(), expensesToSort.end());

    system("cls");
    cout << "Bilans z biezacego miesiaca:" << endl << endl;

    cout << "Przychody: " << endl;
    for (int i = 0; i < incomesToSort.size(); i++)
    {
        cout << incomesToSort[i].getIncomeDateText() << " - " << incomesToSort[i].getIncomeItem() << " - "
             << incomesToSort[i].getIncomeAmount() << endl;
    }
    cout << endl;

    cout << "Wydatki: " << endl;
    for (int i = 0; i < expensesToSort.size(); i++)
    {
        cout << expensesToSort[i].getExpenseDateText() << " - " << expensesToSort[i].getExpenseItem() << " - "
             << expensesToSort[i].getExpenseAmount() << endl;
    }
    cout << endl;

    auxiliaryFunctions.showBalance(incomesToSort, expensesToSort);

    cout << endl;
    system("pause");
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

    cout << "Przychody: " << endl;
    for (int i = 0; i < incomesToSort.size(); i++)
    {
        cout << incomesToSort[i].getIncomeDateText() << " - " << incomesToSort[i].getIncomeItem() << " - "
             << incomesToSort[i].getIncomeAmount() << endl;
    }
    cout << endl;

    cout << "Wydatki: " << endl;
    for (int i = 0; i < expensesToSort.size(); i++)
    {
        cout << expensesToSort[i].getExpenseDateText() << " - " << expensesToSort[i].getExpenseItem() << " - "
             << expensesToSort[i].getExpenseAmount() << endl;
    }
    cout << endl;

    auxiliaryFunctions.showBalance(incomesToSort, expensesToSort);

    cout << endl;
    system("pause");
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
            int firstDateYear = auxiliaryFunctions.getYearFromDateText(firstDate);
            int firstDateMonth = auxiliaryFunctions.getMonthFromDateText(firstDate);
            int firstDateDay = auxiliaryFunctions.getDayFromDateText(firstDate);
            int secondDateYear = auxiliaryFunctions.getYearFromDateText(secondDate);
            int secondDateMonth = auxiliaryFunctions.getMonthFromDateText(secondDate);
            int secondDateDay = auxiliaryFunctions.getDayFromDateText(secondDate);

            bool checkDates = 0;

            for (int i = 0; i < incomeMaster->incomes.size(); i++)
            {
                if (firstDateYear < auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                        && secondDateYear > auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                         && firstDateMonth < auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                         && secondDateMonth > auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                         && (firstDateMonth == auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                             || secondDateMonth == auxiliaryFunctions.getMonthFromDateText(incomeMaster->incomes[i].getIncomeDateText()))
                         && (firstDateDay <= auxiliaryFunctions.getDayFromDateText(incomeMaster->incomes[i].getIncomeDateText())
                         && secondDateDay >= auxiliaryFunctions.getDayFromDateText(incomeMaster->incomes[i].getIncomeDateText())))
                    checkDates = 1;

                if (checkDates == 1)
                    incomesToSort.push_back(incomeMaster->incomes[i]);

                checkDates = 0;
            }
            sort(incomesToSort.begin(), incomesToSort.end());

            for (int i = 0; i < expenseMaster->expenses.size(); i++)
            {
                if (firstDateYear < auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                        && secondDateYear > auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                         && firstDateMonth < auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                         && secondDateMonth > auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                         && (firstDateMonth == auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                             || secondDateMonth == auxiliaryFunctions.getMonthFromDateText(expenseMaster->expenses[i].getExpenseDateText()))
                         && (firstDateDay <= auxiliaryFunctions.getDayFromDateText(expenseMaster->expenses[i].getExpenseDateText())
                         && secondDateDay >= auxiliaryFunctions.getDayFromDateText(expenseMaster->expenses[i].getExpenseDateText())))
                    checkDates = 1;

                if (checkDates == 1)
                    expensesToSort.push_back(expenseMaster->expenses[i]);

                checkDates = 0;
            }
            sort(expensesToSort.begin(), expensesToSort.end());

            system("cls");
            cout << "Bilans z okresu: " << firstDate << " - " << secondDate << endl << endl;

            cout << "Przychody: " << endl;
            for (int i = 0; i < incomesToSort.size(); i++)
            {
                cout << incomesToSort[i].getIncomeDateText() << " - " << incomesToSort[i].getIncomeItem() << " - "
                     << incomesToSort[i].getIncomeAmount() << endl;
            }
            cout << endl;

            cout << "Wydatki: " << endl;
            for (int i = 0; i < expensesToSort.size(); i++)
            {
                cout << expensesToSort[i].getExpenseDateText() << " - " << expensesToSort[i].getExpenseItem() << " - "
                     << expensesToSort[i].getExpenseAmount() << endl;
            }
            cout << endl;

            auxiliaryFunctions.showBalance(incomesToSort, expensesToSort);

            cout << endl;
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

void Finance::logOutUser()
{
    userMaster.logOutUser();
    delete incomeMaster;
    incomeMaster = NULL;
    delete expenseMaster;
    expenseMaster = NULL;
}
