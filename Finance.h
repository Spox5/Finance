#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include "UserMaster.h"
//#include "AdresatMaster.h"

using namespace std;

class Finance
{
    UserMaster userMaster;
    //AdresatMaster *adresatMaster;
    //const string NAZWA_PLIKU_Z_ADRESATAMI;


public:
    Finance(string fileWithUsersName)
    : userMaster(fileWithUsersName){};
    /*KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMaster(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMaster = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMaster;
        adresatMaster = NULL;
    }*/
    void registerTheUser();

    /*void logowanieUzytkownika();
    void zmianaHaslaUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();

    void dodajAdresata();
    void listaAdresatow();
    void wyszukajAdresataPoImieniu();
    void wyszukajAdresataPoNazwisku();
    void usuniecieAdresata ();
    void edycjaAdresata ();
    void wylogowanieUzytkownika();*/

};

#endif
