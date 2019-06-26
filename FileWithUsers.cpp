#include "FileWithUsers.h"

vector <User> FileWithUsers::loadFileWithUsers()
{
    CMarkup xml;
    User user;
    vector <User> users;

    bool fileExists = xml.Load(XMLFile::getFileName());

    if (!fileExists)
    {
        cout << "Baza uzytkownikow jest pusta." << endl;
        system("pause");
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
    xml.AddElem("UserLogin", user.getUserLogin());
    xml.AddElem("UserPassword", user.getUserPassword());
    xml.AddElem("UserName", user.getUserName());
    xml.AddElem("UserSurname", user.getUserSurname());

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
    xml.Save(XMLFile::getFileName());
}
