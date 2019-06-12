#include "FileWithUsers.h"

/*User FileWithUsers::getUserData(string userData)
{
    User user;
    string simplyUserData = "";
    int simplyUserDataNumber = 1;

    for (int charPosition = 0; charPosition < userData.length(); charPosition++)
    {
        if (userData[charPosition] != '|')
        {
            simplyUserData += userData[charPosition];
        }
        else
        {
            switch(simplyUserDataNumber)
            {
            case 1:
                user.setUserId(atoi(simplyUserData.c_str()));
                break;
            case 2:
                user.setUserName(simplyUserData);
                break;
            case 3:
                user.setUserSurname(simplyUserData);
                break;
            case 4:
                user.setUserLogin(simplyUserData);
                break;
            case 5:
                user.setUserPassword(simplyUserData);
                break;
            }
            simplyUserData = "";
            simplyUserDataNumber++;
        }
    }
    return user;
}*/

vector <User> FileWithUsers::loadFileWithUsers()
{
    CMarkup xml;
    User user;
    vector <User> users;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        cout << "Baza uzytkownikow jest pusta." << endl;
    }

    xml.FindElem("Users");
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setUserId(atoi(xml.GetElemContent().c_str()));
        xml.FindElem("UserLogin");
        user.setUserLogin(xml.GetElemContent());
        xml.FindElem("UserPassword");
        user.setUserPassword(xml.GetElemContent());
        xml.FindElem("UserName");
        user.setUserName(xml.GetElemContent());
        xml.FindElem("UserSurname");
        user.setUserSurname(xml.GetElemContent());
        xml.OutOfElem();
        users.push_back(user);

    }

    return users;
}

void FileWithUsers::saveNewUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("UserLogin", user.getUserSurname());
    xml.AddElem("UserPassword", user.getUserId());
    xml.AddElem("UserName", user.getUserName());
    xml.AddElem("UserSurname", user.getUserName());

    xml.Save(XMLFile::getFileName());
}

void FileWithUsers::saveNewPasswordToFile(string newPassword, int loggedUserId)
{
    CMarkup xml;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        cout << "Baza uzytkownikow jest pusta." << endl;
    }

    xml.FindElem("Users");
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if (atoi(xml.GetData().c_str()) == loggedUserId)
        {
           xml.FindElem("UserPassword");
           xml.RemoveElem();
           xml.AddElem("UserPassword", newPassword);
           break;
        }
        xml.OutOfElem();

    }
    xml.Save("Uzytkownicy.xml");
    /*
    fstream fileUsers;
    fileUsers.open(XMLFile::getFileName().c_str(), ios::out);
    for (int j = 0; j <= user.size()-1; j++)
    {
        fileUsers << user[j].getUserId() << "|" << user[j].getUserName() << "|" << user[j].getUserSurname() << "|"
                  << user[j].getUserLogin() << "|" << user[j].getUserPassword() << "|" << endl;
    }
    cout << "Haslo zostalo zmienione." << endl;
    system("pause");
    fileUsers.close();*/
}

/*void PlikZUzytkownikami::dopisz(string tekst)
{
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        if (czyPlikJestPusty())
            plikTekstowy << "To jest poczatek pliku" << endl;
        plikTekstowy << tekst << endl;
    }

    plikTekstowy.close();
}*/
