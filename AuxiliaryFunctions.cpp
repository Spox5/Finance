#include "AuxiliaryFunctions.h"

string AuxiliaryFunctions::getCurrentDate()
{
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    struct tm *date = localtime(&now);
    int year = date->tm_year + 1900;
    int month = date->tm_mon + 1;
    int day = date->tm_mday;

    ostringstream ss;
    ss << year;
    string yearString = ss.str();
    ostringstream sd;
    sd << month;
    string monthString = sd.str();
    ostringstream df;
    df << day;
    string dayString = df.str();

    string currentDate = "";
    if (month > 10  && day > 10)
        currentDate = yearString + "-" + monthString + "-" + dayString;
    else if (month < 10 && day > 9)
        currentDate = yearString + "-0" + monthString + "-" + dayString;
    else if (month > 9 && day < 10)
        currentDate = yearString + "-" + monthString + "-0" + dayString;
    else if (month < 10 && day < 10)
        currentDate = yearString + "-0" + monthString + "-0" + dayString;

    return currentDate;
}

int AuxiliaryFunctions::getMonth()
{
    time_t now = time(0);

    char* dt = ctime(&now);

    struct tm *date = localtime(&now);
    int year = date->tm_year + 1900;
    int month = date->tm_mon + 1;
    int day = date->tm_mday;

    return month;
}

int AuxiliaryFunctions::getYear()
{
    time_t now = time(0);

    char* dt = ctime(&now);

    struct tm *date = localtime(&now);
    int year = date->tm_year + 1900;
    int month = date->tm_mon + 1;
    int day = date->tm_mday;

    return year;
}

string AuxiliaryFunctions::getDateFromUser()
{
    string userDate = "";
    cout << "Wpisz date w formacie rrrr-mm-dd: " << endl;
    while (cin >> userDate)
    {
        if (checkUserDate(userDate))
            return userDate;
        else
        {
            cout << "Nieprawidlowa data. Wpisz ponownie date." << endl;
        }
    }
}

bool AuxiliaryFunctions::checkUserDate(string userDate)
{
    string simplyData = "";
    int year = 0;
    int month = 0;
    int day = 0;
    int simplyDataNumber = 1;

    for (int charPosition = 0; charPosition <= userDate.length(); charPosition++)
    {
        if (userDate[charPosition] != '-' && charPosition != 10)
        {
            simplyData += userDate[charPosition];
        }
        else
        {
            switch(simplyDataNumber)
            {
            case 1:
                year = atoi(simplyData.c_str());
                break;
            case 2:
                month = atoi(simplyData.c_str());
                break;
            case 3:
                day = atoi(simplyData.c_str());
                break;
            }
            simplyData = "";
            simplyDataNumber++;
        }
    }
    if (year >= 2000 && (month >= 1 && month <= 12))
    {
        if((month == 4 || month == 6 || month == 9 || month == 11) && (day >= 1 && day <= 30))
                return true;

        else if (month == 2)
        {
            bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

                if (leapyear == 0 && (day >= 1 && day <= 28))
                    return true;
                else if (leapyear == 1 && (day >= 1 && day <= 29))
                    return true;
                else
                    return false;
        }
        else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day >= 1 && day <= 31))
            return true;

        else
            return false;
    }

    else
        return false;
}

bool AuxiliaryFunctions::checkAmountIsCorrect(string amount)
{
    bool isDot = false;
    bool isComma = false;
    for (int charPosition = 0; charPosition < amount.length(); charPosition++)
        {

            if ((amount[charPosition] >= 48 && amount[charPosition] <= 57) || (amount[charPosition] == 46 || amount[charPosition] == 44))
            {
                if ((amount[charPosition] == 46 || amount[charPosition] == 44) && (isDot == false || isComma == false))
                {
                    isDot = true;
                    isComma = true;
                }
                else if (amount[charPosition] == 46 || amount[charPosition] == 44 && (isDot == true || isComma == true))
                {
                    cout << "Podana wysokosc przychodu jest nieprawidlowa." << endl;
                    return 0;
                }

            }
            else
            {
                cout << "Podana wysokosc przychodu jest nieprawidlowa." << endl;
                return 0;
            }
        }
    return 1;
}

bool AuxiliaryFunctions::checkUsersDatesInShowPeriod(string firstDate, string secondDate)
{
    if (getYearFromDateText(firstDate) < getYearFromDateText(secondDate))
        return true;
    else if (getYearFromDateText(firstDate) == getYearFromDateText(secondDate) && getMonthFromDateText(firstDate) < getMonthFromDateText(secondDate))
        return true;
    else if (getYearFromDateText(firstDate) == getYearFromDateText(secondDate) && getMonthFromDateText(firstDate) == getMonthFromDateText(firstDate)
             && getDayFromDateText(firstDate) <= getDayFromDateText(secondDate))
        return true;
    else
        return false;
}

int AuxiliaryFunctions::getYearFromDateText(string dateToBreak)
{
    int year, month, day;
    string simplyData = "";
    int simplyDataNumber = 1;

    for (int charPosition = 0; charPosition <= dateToBreak.length(); charPosition++)
    {
        if (dateToBreak[charPosition] != '-' && charPosition != 10)
        {
            simplyData += dateToBreak[charPosition];
        }
        else
        {
            switch(simplyDataNumber)
            {
            case 1:
                year = atoi(simplyData.c_str());
                break;
            case 2:
                month = atoi(simplyData.c_str());
                break;
            case 3:
                day = atoi(simplyData.c_str());
                break;
            }
            simplyData = "";
            simplyDataNumber++;
        }
    }
    return year;
}

int AuxiliaryFunctions::getMonthFromDateText(string dateToBreak)
{
    int year, month, day;
    string simplyData = "";
    int simplyDataNumber = 1;

    for (int charPosition = 0; charPosition <= dateToBreak.length(); charPosition++)
    {
        if (dateToBreak[charPosition] != '-' && charPosition != 10)
        {
            simplyData += dateToBreak[charPosition];
        }
        else
        {
            switch(simplyDataNumber)
            {
            case 1:
                year = atoi(simplyData.c_str());
                break;
            case 2:
                month = atoi(simplyData.c_str());
                break;
            case 3:
                day = atoi(simplyData.c_str());
                break;
            }
            simplyData = "";
            simplyDataNumber++;
        }
    }
    return month;
}

int AuxiliaryFunctions::getDayFromDateText(string dateToBreak)
{
    int year, month, day;
    string simplyData = "";
    int simplyDataNumber = 1;

    for (int charPosition = 0; charPosition <= dateToBreak.length(); charPosition++)
    {
        if (dateToBreak[charPosition] != '-' && charPosition != 10)
        {
            simplyData += dateToBreak[charPosition];
        }
        else
        {
            switch(simplyDataNumber)
            {
            case 1:
                year = atoi(simplyData.c_str());
                break;
            case 2:
                month = atoi(simplyData.c_str());
                break;
            case 3:
                day = atoi(simplyData.c_str());
                break;
            }
            simplyData = "";
            simplyDataNumber++;
        }
    }
    return day;
}

void AuxiliaryFunctions::showBalance(vector <Income> vector1ToBalance, vector <Expense> vector2ToBalance)
{
    cout << "Przychody: " << endl;
    for (int i = 0; i < vector1ToBalance.size(); i++)
    {
        cout << vector1ToBalance[i].getIncomeDateText() << " - " << vector1ToBalance[i].getIncomeItem() << " - "
             << vector1ToBalance[i].getIncomeAmount() << endl;
    }
    cout << endl;

    cout << "Wydatki: " << endl;
    for (int i = 0; i < vector2ToBalance.size(); i++)
    {
        cout << vector2ToBalance[i].getExpenseDateText() << " - " << vector2ToBalance[i].getExpenseItem() << " - "
             << vector2ToBalance[i].getExpenseAmount() << endl;
    }
    cout << endl;

    double sumVec1 = 0;
    double sumVec2 = 0;
    for (int i = 0; i < vector1ToBalance.size(); i++)
    {
        sumVec1 = sumVec1 + vector1ToBalance[i].getIncomeAmount();
    }

    for (int i = 0; i < vector2ToBalance.size(); i++)
    {
        sumVec2 = sumVec2 + vector2ToBalance[i].getExpenseAmount();
    }

    cout << "Suma przychodow: " << sumVec1 << " zl." << endl;
    cout << "Suma wydatkow: " << sumVec2 << " zl." << endl;

    double balance = sumVec1 - sumVec2;

    cout << "Bilans wynosi: " << balance << " zl." << endl << endl;
    system("pause");
}

string AuxiliaryFunctions::replaceCommaToDot(string stringToReplace)
{
    for (int charPosition = 0; charPosition < stringToReplace.length(); charPosition++)
        {
            if (stringToReplace[charPosition] == 44)
                stringToReplace[charPosition] = 46;
        }
    return stringToReplace;
}
