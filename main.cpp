#include <iostream>
#include "Finance.h"

using namespace std;


int main()
{
    Finance finance("Uzytkownicy.xml");
    //finance.registerTheUser();
    FileWithUsers file("Uzytkownicy.xml");
    file.loadFileWithUsers();

    return 0;
}
