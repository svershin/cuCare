#ifndef CLIENTNETWORKCONNECTION_H
#define CLIENTNETWORKCONNECTION_H

#include <QtGlobal>
#include <QtNetwork>
#include <QTcpSocket>
#include "ServerNetworkConnection.h"

#define SERVER_RESPONSE_WAIT_TIME_MS 10000



class ClientNetworkConnection : public QTcpSocket
{
    Q_OBJECT

public:
    ClientNetworkConnection();
    ClientNetworkConnection(const ClientNetworkConnection& origin);
    ClientNetworkConnection& operator=(const ClientNetworkConnection& origin);

    //sendReceive is a high level function that attempts to send a request to the destination host (the cuCare server, in this case) and wait for a reply.
    QByteArray sendReceive(QHostAddress serverIP, quint16 serverPort, QByteArray request);

private:
    static bool containsEOT(QByteArray message);
};

#endif // CLIENTNETWORKCONNECTION_H
