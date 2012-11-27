#include "ServerController.h"
#include "iostream"
#include <QtCore>

using namespace std;

ServerController::ServerController()//Repository repoParam
{

}

ServerController::~ServerController()
{
    haveInstance = false;
}

ServerController *ServerController::getInstance()
{
    if(haveInstance)
    {
        return instance;
    }
    else
    {
        instance = new ServerController();
        haveInstance = true;
        return instance;
    }
}

bool ServerController::create(string objectType, map<string, string> *pObjectMap, int *pOutID, string *pErrorString)
{
    (*pOutID) = 9000;
    return true;
}

bool ServerController::push(string objectType, map<string, string> *pObjectMap, string *pErrorString)
{
    return true;
}

bool ServerController::pull(string objectType, map<string, string> *pObjectMap, list< map<string, string> *> *pObjectList, string *pErrorString)
{
    map<string, string> *newMap = new map<string, string>();
    newMap[string("first one key")] = string("first one value");
    newMap[string("second one key")] = string("second one value");
    pObjectList->push_back(newMap);
    return true;
}
