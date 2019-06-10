#include "User.h"

void User::setUserId(int newUserId)
{
    userId = newUserId;
}

int User::getUserId()
{
    return userId;
}

void User::setUserName(string newUserName)
{
    userName = newUserName;
}

string User::getUserName()
{
    return userName;
}

void User::setUserSurname(string newUserSurname)
{
    userSurname = newUserSurname;
}

string User::getUserSurname()
{
    return userSurname;
}

void User::setUserLogin(string newUserLogin)
{
    userLogin = newUserLogin;
}

string User::getUserLogin()
{
    return userLogin;
}

void User::setUserPassword(string newUserPassword)
{
    userPassword = newUserPassword;
}

string User::getUserPassword()
{
    return userPassword;
}
