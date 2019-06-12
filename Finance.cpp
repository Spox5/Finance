#include "Finance.h"

using namespace std;

void Finance::registerTheUser()
{
    userMaster.registerTheUser();
}

void Finance::logInTheUser()
{
    userMaster.logInTheUser();
    //if (userMaster.checkIfUserIsSignIn())
    //{
    //    adresatMaster = new AdresatMaster(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMaster.pobierzIdZalogowanegoUzytkownika());
    //}
}

void Finance::changeUserPassword()
{
    userMaster.changeUserPassword();
}

int Finance::getLoggedUserId()
{
    userMaster.getLoggedUserId();
}

/*

void KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMaster.wylogowanieUzytkownika();
    delete adresatMaster;
    adresatMaster = NULL;
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMaster->dodajAdresata();
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
