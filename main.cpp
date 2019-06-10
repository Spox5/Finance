#include <iostream>
#include "Finance.h"

using namespace std;


int main()
{
    Finance finance("Uzytkownicy.xml");
    finance.registerTheUser();

    return 0;
}
