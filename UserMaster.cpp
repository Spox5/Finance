#include "UserMaster.h"
//#include "AdresatMaster.h"

void UserMaster::registerTheUser ()
{
    User user;
    string userName, userSurname, userLogin, userPassword;

    cout << "Podaj imie uzytkownika: " << endl;
    cin >> userName;
    user.setUserName(userName);
    cout << "Podaj nazwisko uzytkownika: " << endl;
    cin >> userSurname;
    user.setUserSurname(userSurname);
    cout << "Podaj login uzytkownika: " << endl;
    cin >> userLogin;
    if (users.size() != 0)
    {
        int i = 0;
        while (i < users.size())
        {
            if (userLogin == users[i].getUserLogin())
            {
                cout << "Taki login uzytkowniak juz istnieje. Podaj inny login uzytkownika" << endl;
                cin >> userLogin;
                i = 0;
            }
            else
                i++;
        }
    }
    user.setUserLogin(userLogin);

    cout << "Podaj haslo uzytkownika: " << endl;
    cin >> userPassword;
    user.setUserPassword(userPassword);

    if (users.size() == 0)
    {
        user.setUserId(1);
    }
    else
        user.setUserId(users.size() + 1);
    users.push_back(user);
    cout << "Nowy uzytkownik zostal utworzony" << endl;
    system("pause");

    fileWithUsers.saveNewUserToFile(user);

}

/*int UzytkownikMaster::logowanieUzytkownika ()
{
    string nazwaUzytkownika, hasloUzytkownika;

    cout << "Podaj nazwe uzytkownika: " << endl;
    cin >> nazwaUzytkownika;

    int i = 0;
    while (i < uzytkownicy.size())
    {
        if (nazwaUzytkownika == uzytkownicy[i].wypiszNazweUzytkownika())
        {
            for (int proby = 0; proby < 3; proby++)
            {
                cout << "Podaj haslo. Pozostalo prob: " << 3 -  proby << endl;
                cin >> hasloUzytkownika;
                if (hasloUzytkownika == uzytkownicy[i].wypiszHasloUzytkownika())
                {
                    cout << "Zalogowales sie." << endl;
                    system("pause");
                    system("cls");
                    idZalogowanegoUzytkownika = uzytkownicy[i].wypiszIdUzytkownika();
                    return uzytkownicy[i].wypiszIdUzytkownika();
                }
                else
                    cout << "Nieprawidlowe haslo." << endl;;
            }
            cout << "Podales 3 razy bledne haslo. Odczekaj 3 sekundy." << endl;;
            Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma uzytkownika o takiej nazwie." << endl;
    system ("pause");
    return 0;
}

vector <Uzytkownik> UzytkownikMaster::zmianaHaslaUzytkownika()
{
    string noweHaslo;

    cout << "Podaj nowe haslo:" << endl;
    cin >> noweHaslo;
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if (idZalogowanegoUzytkownika == uzytkownicy[i].wypiszIdUzytkownika())
        {
            uzytkownicy[i].ustawHasloUzytkownika(noweHaslo);
            plikZUzytkownikami.zapisanieZmienionegoHaslaDoPliku(uzytkownicy);
        }
    }
    return uzytkownicy;
}

int UzytkownikMaster::wylogowanieUzytkownika()
{
    return idZalogowanegoUzytkownika = 0;
}

bool UzytkownikMaster::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

int UzytkownikMaster::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
*/
