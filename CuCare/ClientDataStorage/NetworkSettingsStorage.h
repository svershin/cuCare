#ifndef NETWORKSETTINGSSTORAGE_H
#define NETWORKSETTINGSSTORAGE_H

#include <string>
#include <fstream>
#include "../../CuCareModel/Utility.h"

using namespace std;

class NetworkSettingsStorage
{
public:
    NetworkSettingsStorage();

    string getIpAddress();
    int getPortNumber();
private:
    const string settingsPath;
    string ipAddress;
    int portNumber;

    bool settingsFileExists();
};

#endif // NETWORKSETTINGSSTORAGE_H
