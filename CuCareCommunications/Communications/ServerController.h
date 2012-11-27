#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include <iostream>
#include <string>
#include "ServerController.h"

using namespace std;

class ServerController
{
public:

    ~ServerController();

    static ServerController getInstance();

    bool create(string objectType, map<string, string> *pObjectMap, int *pOutID, string *pErrorString);
    bool push(string objectType, map<string, string> *pObjectMap, string *pErrorString);
    bool pull(string objectType, map<string, string> *pObjectMap, list< map<string, string> *> *pObjectList, string *pErrorString);

private:
    ServerController();
    static bool haveInstance;
    static ServerController *instance;
    //Repository repo;
};

#endif // SERVERCONTROLLER_H
