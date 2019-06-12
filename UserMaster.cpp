#include "UserMaster.h"
#include "IncomeMaster.h"

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

int UserMaster::logInTheUser()
{
    string userLogin, userPassword;

    cout << "Podaj login uzytkownika: " << endl;
    cin >> userLogin;

    int i = 0;
    while (i < users.size())
    {
        if (userLogin == users[i].getUserLogin())
        {
            for (int signInAttempt = 0; signInAttempt < 3; signInAttempt++)
            {
                cout << "Podaj haslo. Pozostalo prob: " << 3 -  signInAttempt << endl;
                cin >> userPassword;
                if (userPassword == users[i].getUserPassword())
                {
                    cout << "Zalogowales sie." << endl;
                    system("pause");
                    system("cls");
                    loggedUserId = users[i].getUserId();
                    return users[i].getUserId();
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

vector <User> UserMaster::changeUserPassword()
{
    string newPassword;

    cout << "Podaj nowe haslo:" << endl;
    cin >> newPassword;
    for (int i = 0; i < users.size(); i++)
    {
        if (loggedUserId == users[i].getUserId())
        {
            users[i].setUserPassword(newPassword);
            fileWithUsers.saveNewPasswordToFile(newPassword, loggedUserId);
        }
    }
    return users;
}

int UserMaster::getLoggedUserId()
{
    return loggedUserId;
}

int UserMaster::logOutUser()
{
    return loggedUserId = 0;
}

bool UserMaster::checkIfUserIsLogIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}
