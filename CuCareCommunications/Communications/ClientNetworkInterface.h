#ifndef CLIENTNETWORKINTERFACE_H
#define CLIENTNETWORKINTERFACE_H

#include <QtNetwork>
#include <string>
#include "BaseNetworkMessenger.h"
#include "ClientNetworkTranslator.h"

using namespace std;

class ClientNetworkInterface : public BaseNetworkMessenger
{
public:
    ClientNetworkInterface(string serverIPParam, quint16 serverPortParam);

    bool create(string tableName, string idKey, map<string, string> *pObjectMap, int *pOutID, string *pErrorString);
    bool push(string tableName, string idKey, map<string, string> *pObjectMap, string *pErrorString);
    bool pull(string tableName, string idKey, map<string, string> *pObjectMap, list< map<string, string> *> *pObjectList, string *pErrorString);

private:
    QHostAddress serverIP;
    quint16 serverPort;
};

#endif // CLIENTNETWORKINTERFACE_H
