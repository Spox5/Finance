#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Date
{
    public:

    string dateText;
    int year;
    int month;
    int day;

    string getCurrentDate();
    void setIncomeDate();
    void checkDaysInMonth();
    bool myfunction(Date i, Date j);
    void comparingDates();

};

#endif
