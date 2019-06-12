#include "Finance.h"

using namespace std;

void Finance::registerTheUser()
{
    userMaster.registerTheUser();
}

void Finance::logInTheUser()
{
    userMaster.logInTheUser();
    if (userMaster.checkIfUserIsLogIn())
    {
        incomeMaster = new IncomeMaster(FILE_NAME_WITH_INCOMES, userMaster.getLoggedUserId());
    }
}

void Finance::changeUserPassword()
{
    userMaster.changeUserPassword();
}

int Finance::getLoggedUserId()
{
    userMaster.getLoggedUserId();
}

void Finance::addIncome()
{
    incomeMaster->addIncome();
}

/*void Finance::logOutUser()
{
    userMaster.logOutUser();
    delete adresatMaster;
    adresatMaster = NULL;
}



void KsiazkaAdresowa::listaAdresatow()
{
    adresatMaster->listaAdresatow();
}

void KsiazkaAdresowa::wyszukajAdresataPoImieniu()
{
    adresatMaster->wyszukajAdresataPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresataPoNazwisku()
{
    adresatMaster->wyszukajAdresataPoNazwisku();
}

void KsiazkaAdresowa::usuniecieAdresata()
{
    adresatMaster->usuniecieAdresata();
}

void KsiazkaAdresowa::edycjaAdresata ()
{
    adresatMaster->edycjaAdresata();
}*/
