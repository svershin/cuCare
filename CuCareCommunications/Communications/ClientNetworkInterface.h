#ifndef CLIENTNETWORKINTERFACE_H
#define CLIENTNETWORKINTERFACE_H

#include <QtNetwork>
#include <string>

using namespace std;

class ClientNetworkInterface
{
public:
    ClientNetworkInterface(string serverIPParam, quint16 serverPortParam);

    //Currently, I am presuming that the caller will take care of deletion for these three following functions
    int create(string *pErrorString, map<string, string> *pInputMap, int * pID);
    int push(string *pErrorString, map<string, string> *pInputMap);
    int pull(string *pErrorString, map<string, string> *pInputMap); // TODO: need to agree on what format to use for the output here


private:
    QHostAddress serverIP;
    quint16 serverPort;
};

#endif // CLIENTNETWORKINTERFACE_H
