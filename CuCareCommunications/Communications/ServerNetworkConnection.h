#ifndef SERVERNETWORKCONNECTION_H
#define SERVERNETWORKCONNECTION_H

#define END_OF_TRANSMISSION_CHARACTER (char)4

#include <QtNetwork>
#include "ServerNetworkTranslator.h"

class ServerNetworkConnection
{
public:
    ServerNetworkConnection(QTcpSocket *connectedSocketParam);
    ~ServerNetworkConnection();

    void handleRequest();

private:
    QTcpSocket *connectedSocket;
    qint64 wrappedWrite(QByteArray message);
};

#endif // SERVERNETWORKCONNECTION_H
