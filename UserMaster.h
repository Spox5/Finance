#ifndef USERMASTER_H
#define USERMASTER_H

#include "FileWithUsers.h"

using namespace std;

class UserMaster
{
    FileWithUsers fileWithUsers;
    vector <User> users;
    int loggedUserId;


public:
    UserMaster(string fileWithUsersName) : fileWithUsers(fileWithUsersName)
    {
        loggedUserId = 0;
        users = fileWithUsers.loadFileWithUsers();
    };

    void registerTheUser();
    int logInTheUser();
    vector <User> changeUserPassword();
    int logOutUser();
    bool checkIfUserIsLogIn();
    int getLoggedUserId();
};

#endif
