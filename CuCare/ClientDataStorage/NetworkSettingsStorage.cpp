#include "NetworkSettingsStorage.h"

NetworkSettingsStorage::NetworkSettingsStorage()
    : settingsPath ("../CuCare/NetworkSettings.init"),
      ipAddress ("192.168.0.1"),
      portNumber (60003)
{
    if(settingsFileExists())
    {
        string ip, port;
        ifstream infile;
        infile.open (settingsPath.c_str());
        getline(infile,ip);
        getline(infile,port);
        infile.close();

        ipAddress = ip;
        port = Utility::stoi(port);
    }
}

string NetworkSettingsStorage::getIpAddress()
{
    return ipAddress;
}

int NetworkSettingsStorage::getPortNumber()
{
    return portNumber;
}

bool NetworkSettingsStorage::settingsFileExists()
{
    ifstream settings(settingsPath.c_str());
    return settings; //Casts to true if file exists.
}
