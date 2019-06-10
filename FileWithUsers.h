#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "User.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers: public XMLFile
{
    //void dopisz(string tekst);

public:
    FileWithUsers(string fileName) : XMLFile(fileName) {};

    vector <User> loadFileWithUsers();

    User getUserData(string userData);

    void saveNewUserToFile(User user);
    void saveNewPasswordToFile(vector <User> users);

};

#endif
