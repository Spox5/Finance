#include <iostream>
#include "Finance.h"

using namespace std;


int main()
{
    Finance finance("Uzytkownicy.xml", "Przychody.xml", "Wydatki.xml");

    while (true)
    {
        if (finance.getLoggedUserId() == 0)
        {
            char choice;

            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> choice;

            switch (choice)
            {
            case '1':
                finance.registerTheUser();
                break;
            case '2':
                finance.logInTheUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            char choiceUserMenu;

            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. Dodaj wydatek" << endl;
            cout << "3. Bilans z biezacego miesiaca" << endl;
            cout << "4. Bilans z poprzedniego miesiaca" << endl;
            cout << "5. Bilans z wybranego okresu - nie dziala" << endl;
            cout << "---------------------------" << endl;
            cout << "6. Zmien haslo" << endl;
            cout << "7. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin >> choiceUserMenu;

            switch (choiceUserMenu)
            {
            case '1':
                finance.addIncome();
                break;
            case '2':
                finance.addExpense();
                break;
            case '3':
                finance.showBalanceFromCurrentMonth();
                break;
            case '4':
                finance.showIncomesFromPreviousMonth();
                break;
            case '5':
                finance.showIncomesFromPeriod();
                break;
            case '6':
                finance.changeUserPassword();
                break;
            case '7':
                finance.logOutUser();
                break;
            case '8':
                break;
            }
        }
    }

    return 0;
}
