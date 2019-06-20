#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
    incomeId = newIncomeId;
}

int Income::getIncomeId()
{
    return incomeId;
}

void Income::setLoggedUserId(int newLoggedUseerId)
{
    loggedUserId = newLoggedUseerId;
}

int Income::getLoggedUserId()
{
    return loggedUserId;
}

void Income::setIncomeDateYear(int newDateYear)
{
    dateYear = newDateYear;
}

int Income::getIncomeDateYear()
{
    return dateYear;
}

void Income::setIncomeDateMonth(int newDateMonth)
{
    dateMonth = newDateMonth;
}

int Income::getIncomeDateMonth()
{
    return dateMonth;
}

void Income::setIncomeDateDay(int newDateDay)
{
    dateDay = newDateDay;
}

int Income::getIncomeDateDay()
{
    return dateDay;
}

void Income::setIncomeItem(string newItem)
{
    incomeItem = newItem;
}

string Income::getIncomeItem()
{
    return incomeItem;
}

void Income::setIncomeDateText(string newDateText)
{
    incomeDateText = newDateText;
}

string Income::getIncomeDateText()
{
    return incomeDateText;
}

void Income::setIncomeAmount(int newAmount)
{
    incomeAmount = newAmount;
}

int Income::getIncomeAmount()
{
    return incomeAmount;
}
