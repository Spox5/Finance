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

void Income::setDateYear(int newDateYear)
{
    dateYear = newDateYear;
}

int Income::getDateYear()
{
    return dateYear;
}

void Income::setDateMonth(int newDateMonth)
{
    dateMonth = newDateMonth;
}

int Income::getDateMonth()
{
    return dateMonth;
}

void Income::setDateDay(int newDateDay)
{
    dateDay = newDateDay;
}

int Income::getDateDay()
{
    return dateDay;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

string Income::getItem()
{
    return item;
}

void Income::setDateText(string newDateText)
{
    dateText = newDateText;
}

string Income::getDateText()
{
    return dateText;
}

void Income::setAmount(int newAmount)
{
    amount = newAmount;
}

int Income::getAmount()
{
    return amount;
}
