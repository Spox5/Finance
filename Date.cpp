#include "Date.h"
#include <sstream>

string Date::getCurrentDate()
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

    string currentDate = yearString + "-" + monthString + "-" + dayString;
    cout << currentDate;

    return currentDate;

}

void Date::setIncomeDate()
{
    string incomeDate = "";
    int yearOfIncome = 0;
    int monthOfIncome = 0;
    int dayOfIncome = 0;

    cout << "Data przychodu: " << endl;
    cin >> incomeDate;

    string simplyData = "";
    int simplyDataNumber = 1;

    for (int charPosition = 0; charPosition <= incomeDate.length(); charPosition++)
    {
        if (incomeDate[charPosition] != '-' && charPosition != 10)
        {
            simplyData += incomeDate[charPosition];
        }
        else
        {
            switch(simplyDataNumber)
            {
            case 1:
                yearOfIncome = atoi(simplyData.c_str());
                break;
            case 2:
                monthOfIncome = atoi(simplyData.c_str());
                break;
            case 3:
                dayOfIncome = atoi(simplyData.c_str());
                break;
            }
            simplyData = "";
            simplyDataNumber++;
        }
    }
    cout << yearOfIncome << " " << monthOfIncome << " " << dayOfIncome;

}

void Date::checkDaysInMonth()
{
    int year, month, days;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;

    else if (month == 02)
    {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapyear == 0)
            days = 28;
        else
            days = 29;
    }

    else
        days = 31;
}

bool Date::myfunction (Date i,Date j)
{
    return (i.year<j.year);
};


