#include <iostream>
#include "Finance.h"

using namespace std;


int main()
{
    Finance finance("Uzytkownicy.xml", "Przychody.xml");
    finance.logInTheUser();
    finance.addIncome();



    return 0;
}
