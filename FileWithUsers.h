#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "User.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers: public XMLFile
{

public:
    FileWithUsers(string fileName) : XMLFile(fileName) {};
    vector <User> loadFileWithUsers();
    void saveNewUserToFile(User user);
    void saveNewPasswordToFile(string newPassword, int loggedUserId);

};

#endif
