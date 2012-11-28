#ifndef SERVERCONTROLLER_H
#define SERVERCONTROLLER_H

#include <QtCore>
#include <iostream>
#include <string>
#include "ServerController.h"
#include "AuditTimer.h"
#include "../OutsideTester/Repository.h" //TODO:THIS IS A STUB
#include "../OutsideTester/Repository.cpp" //TODO:THIS IS A STUB
#include "../OutsideTester/StorageObject.h" //TODO:THIS IS A STUB
#include "../OutsideTester/StorageObject.cpp" //TODO:THIS IS A STUB

using namespace std;

class ServerController : public QObject
{

    Q_OBJECT

public:

    ~ServerController();

    static bool makeInstance(const string& timeString);  //Singleton creator

    static ServerController *getInstance(); //Singleton accessor


    //Functions dealing with repository access
    bool create(string objectType, map<string, string> *pObjectMap, int *pOutID, string *pErrorString);
    bool push(string objectType, map<string, string> *pObjectMap, string *pErrorString);
    bool pull(string objectType, map<string, string> *pObjectMap, list< map<string, string> *> *pObjectList, string *pErrorString);


public slots:
    void runAudit();

private:
    ServerController(string timeOfDay);
    static bool haveInstance;
    static ServerController *instance;

    AuditTimer ticker;
    Repository repository;
};

#endif // SERVERCONTROLLER_H
