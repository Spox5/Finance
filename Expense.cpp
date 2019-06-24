#include "Expense.h"

void Expense::setExpenseId(int newExpenseId)
{
    expenseId = newExpenseId;
}

int Expense::getExpenseId()
{
    return expenseId;
}

void Expense::setLoggedUserId(int newLoggedUseerId)
{
    loggedUserId = newLoggedUseerId;
}

int Expense::getLoggedUserId()
{
    return loggedUserId;
}

void Expense::setExpenseDateYear(int newDateYear)
{
    dateYear = newDateYear;
}

int Expense::getExpenseDateYear()
{
    return dateYear;
}

void Expense::setExpenseDateMonth(int newDateMonth)
{
    dateMonth = newDateMonth;
}

int Expense::getExpenseDateMonth()
{
    return dateMonth;
}

void Expense::setExpenseDateDay(int newDateDay)
{
    dateDay = newDateDay;
}

int Expense::getExpenseDateDay()
{
    return dateDay;
}

void Expense::setExpenseItem(string newItem)
{
    expenseItem = newItem;
}

string Expense::getExpenseItem()
{
    return expenseItem;
}

void Expense::setExpenseDateText(string newDateText)
{
    expenseDateText = newDateText;
}

string Expense::getExpenseDateText()
{
    return expenseDateText;
}

void Expense::setExpenseAmount(int newAmount)
{
    expenseAmount = newAmount;
}

int Expense::getExpenseAmount()
{
    return expenseAmount;
}
