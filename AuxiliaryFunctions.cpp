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

    string currentDate = yearString + "-" + monthString + "-" + dayString;

    return currentDate;
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
