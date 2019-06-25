#include "ExpenseMaster.h"
#include <algorithm>

void ExpenseMaster::addExpense()
{
    Expense expense;
    string item, date, amountString;
    double amount;

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
        amount = atof(auxiliaryFunctions.replaceCommaToDot(amountString).c_str());
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
