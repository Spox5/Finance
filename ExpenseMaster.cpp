#include "ExpenseMaster.h"
#include <algorithm>
void ExpenseMaster::addExpense()
{
    Expense expense;
    string item, date, amountString;
    int amount;

    cout << "Czy wydatek dotyczy dnia dzisiejszego(t/n)." << endl;
    string dayChoice;
    while (cin >> dayChoice)
    {
        if (dayChoice == "t")
        {
            expense.setExpenseDateText(auxiliaryFunctions.getCurrentDate());
            expense.setExpenseDateYear(auxiliaryFunctions.getYearFromDateText(expense.getExpenseDateText()));
            expense.setExpenseDateMonth(auxiliaryFunctions.getMonthFromDateText(expense.getExpenseDateText()));
            expense.setExpenseDateDay(auxiliaryFunctions.getDayFromDateText(expense.getExpenseDateText()));
            break;
        }
        else if (dayChoice == "n")
        {
            expense.setExpenseDateText(auxiliaryFunctions.getDateFromUser());
            expense.setExpenseDateYear(auxiliaryFunctions.getYearFromDateText(expense.getExpenseDateText()));
            expense.setExpenseDateMonth(auxiliaryFunctions.getMonthFromDateText(expense.getExpenseDateText()));
            expense.setExpenseDateDay(auxiliaryFunctions.getDayFromDateText(expense.getExpenseDateText()));
            break;
        }
        else
            cout << "Nieprawidlowy wybor." << endl;
    }

    cout << "Podaj czego dotyczy wydatek: " << endl;
    cin.sync();
    getline(cin>>ws, item);
    expense.setExpenseItem(item);

    while(1)
    {
        cout << "Podaj wysokosc wydatku: " << endl;
        cin >> amountString;
        amount = atoi(amountString.c_str());
        if (auxiliaryFunctions.checkAmountIsCorrect(amountString))
        {
            expense.setExpenseAmount(amount);
            break;
        }
    }
    expense.setExpenseId(fileWithExpenses.getLastExpenseIdFromFile());
    expenses.push_back(expense);
    cout << "Nowy wydatek zostal utworzony" << endl;
    system("pause");

    fileWithExpenses.saveExpenseToFile(expense, LOGGED_USER_ID);
}

void ExpenseMaster::showExpensesFromCurrentMonth()
{
    vector <Expense> expensesToSort;

    int currentMonth, currentYear;
    currentMonth = auxiliaryFunctions.getMonth();
    currentYear = auxiliaryFunctions.getYear();

    for (int i = 0; i < expenses.size(); i++)
    {
        if (currentMonth == auxiliaryFunctions.getMonthFromDateText(expenses[i].getExpenseDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText()))
        {
            expensesToSort.push_back(expenses[i]);
        }
    }
    sort(expensesToSort.begin(), expensesToSort.end());
    system("cls");
    cout << "Bilans z biezacego miesiaca:" << endl << endl;
    for (int i = 0; i < expensesToSort.size(); i++)
    {
        cout << expensesToSort[i].getExpenseDateText() << " - " << expensesToSort[i].getExpenseItem() << " - "
        << expensesToSort[i].getExpenseAmount() << endl << endl;
    }
    system("pause");
}

void ExpenseMaster::showExpensesFromPreviousMonth()
{
    vector <Expense> expensesToSort;

    int monthBefore;
    int currentYear;
    monthBefore = auxiliaryFunctions.getMonth() - 1;
    currentYear = auxiliaryFunctions.getYear();

    for (int i = 0; i < expenses.size(); i++)
    {
        if (monthBefore == auxiliaryFunctions.getMonthFromDateText(expenses[i].getExpenseDateText())
                && currentYear == auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText()))
        {
            expensesToSort.push_back(expenses[i]);
        }
    }
    sort(expensesToSort.begin(), expensesToSort.end());
    system("cls");
    cout << "Bilans z poprzedniego miesiaca:" << endl << endl;
    for (int i = 0; i < expensesToSort.size(); i++)
    {
        cout << expensesToSort[i].getExpenseDateText() << " - " << expensesToSort[i].getExpenseItem() << " - "
        << expensesToSort[i].getExpenseAmount() << endl << endl;
    }
    system("pause");
}

void ExpenseMaster::showExpensesFromPeriod()
{
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

            for (int i = 0; i < expenses.size(); i++)
            {
                if (firstDateYear < auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText())
                        && secondDateYear > auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText()))
                         && firstDateMonth < auxiliaryFunctions.getMonthFromDateText(expenses[i].getExpenseDateText())
                         && secondDateMonth > auxiliaryFunctions.getMonthFromDateText(expenses[i].getExpenseDateText()))
                    checkDates = 1;
                else if ((firstDateYear == auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText())
                          || secondDateYear == auxiliaryFunctions.getYearFromDateText(expenses[i].getExpenseDateText()))
                         && (firstDateMonth == auxiliaryFunctions.getMonthFromDateText(expenses[i].getExpenseDateText())
                             || secondDateMonth == auxiliaryFunctions.getMonthFromDateText(expenses[i].getExpenseDateText()))
                         && (firstDateDay <= auxiliaryFunctions.getDayFromDateText(expenses[i].getExpenseDateText())
                             || secondDateDay >= auxiliaryFunctions.getDayFromDateText(expenses[i].getExpenseDateText())))
                    checkDates = 1;

                if (checkDates == 1)
                    expensesToSort.push_back(expenses[i]);

                checkDates = 0;

            }
            sort(expensesToSort.begin(), expensesToSort.end());
            system("cls");
            cout << "Bilans z okresu: " << firstDate << " - " << secondDate << endl << endl;
            for (int i = 0; i < expensesToSort.size(); i++)
            {
                cout << expensesToSort[i].getExpenseDateText() << " - " << expensesToSort[i].getExpenseItem() << " - "
                << expensesToSort[i].getExpenseAmount() << endl << endl;
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
