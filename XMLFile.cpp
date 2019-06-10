#include "XMLFile.h"

string XMLFile::getFileName()
{
    return FILE_NAME;
}

bool XMLFile::fileIsEmpty()
{
    bool fileIsEmpty = true;
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            fileIsEmpty = false;
    }

    textFile.close();
    return fileIsEmpty;
}
