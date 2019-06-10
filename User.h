#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class User
{
    int userId;
    string userName;
    string userSurname;
    string userLogin;
    string userPassword;

public:

    void setUserId(int nnewId);
    int getUserId();

    void setUserName(string newUserName);
    string getUserName();

    void setUserSurname(string newUserSurname);
    string getUserSurname();

    void setUserLogin(string newUserLogin);
    string getUserLogin();

    void setUserPassword(string newUserPassword);
    string getUserPassword();

};

#endif
