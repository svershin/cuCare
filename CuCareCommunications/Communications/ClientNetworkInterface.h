#ifndef CLIENTNETWORKINTERFACE_H
#define CLIENTNETWORKINTERFACE_H

#include <QtNetwork>
#include <string>
#include "AbstractNetworkMessenger.h"
#include "ClientNetworkTranslator.h"

using namespace std;

class ClientNetworkInterface : public AbstractNetworkMessenger
{
public:
    ClientNetworkInterface(string serverIPParam, quint16 serverPortParam);

    bool create(string objectType, map<string, string> *pObjectMap, int *pOutID, string *pErrorString);
    bool push(string objectType, map<string, string> *pObjectMap, string *pErrorString);
    bool pull(string objectType, map<string, string> *pObjectMap, list< map<string, string> *> *pObjectList, string *pErrorString);

private:
    QHostAddress serverIP;
    quint16 serverPort;

    static QHostAddress makeAndCheckQHostAddress(QString IPStr); //wrapper for making a QHostAddress (will throw an exception if it's not properly made)
};

#endif // CLIENTNETWORKINTERFACE_H
