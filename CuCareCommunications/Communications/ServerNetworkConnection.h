#ifndef SERVERNETWORKCONNECTION_H
#define SERVERNETWORKCONNECTION_H

#define END_OF_TRANSMISSION_CHARACTER (char)4
#define CLIENT_REQUEST_WAIT_TIME_MS 10000

#include <QtNetwork>
#include "ServerNetworkTranslator.h"
#include "ClientNetworkConnection.h"

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
