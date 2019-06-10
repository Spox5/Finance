#include "FileWithUsers.h"

User FileWithUsers::getUserData(string userData)
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
}

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
        users.push_back(user);




        /*if (xml.GetData() == "2")
        {
            xml.FindElem("UserName");
            string amount = xml.GetElemContent();
            cout << amount << endl;
        }
        xml.OutOfElem();*/
    }
    for (int i = 0; i <= users.size(); i++)
    {
        cout << users[i].getUserPassword() << endl;
    }
    /*User user;
    vector <User> users;
    fstream fileUsers;
    string usersData;

    fileUsers.open(XMLFile::getFileName().c_str(), ios::in);

    if (fileUsers.good() == true)
    {
        while (getline(fileUsers, usersData))
        {
            if (usersData[0] > 48 && usersData[0] < 58)
            {
                user = getUserData(usersData);
                users.push_back(user);
            }
        }
        fileUsers.close();
    }
    else
    {
        cout << "Baza uzytkownikow jest pusta." << endl;
        system("pause");
        system("cls");
    }

    return users;*/
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
    /*
    fstream fileUsers;
    fileUsers.open(TextFile::getFileName().c_str(), ios::app);
    if (fileUsers.good() == true)
    {
        fileUsers << user.getUserId() << "|" << user.getUserName() << "|" << user.getUserSurname() << "|"
        << user.getUserLogin() << "|" << user.getUserPassword() << "|" << endl;
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku " << TextFile::getFileName().c_str() << " i zapisac uzytkownika." << endl;
        system("pause");
    }
    fileUsers.close();*/
}

/*void FileWithUsers::saveNewPasswordToFile(vector <User> user)
{
    fstream fileUsers;
    fileUsers.open(XMLFile::getFileName().c_str(), ios::out);
    for (int j = 0; j <= user.size()-1; j++)
    {
        fileUsers << user[j].getUserId() << "|" << user[j].getUserName() << "|" << user[j].getUserSurname() << "|"
                  << user[j].getUserLogin() << "|" << user[j].getUserPassword() << "|" << endl;
    }
    cout << "Haslo zostalo zmienione." << endl;
    system("pause");
    fileUsers.close();
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
