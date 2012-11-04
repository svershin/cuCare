#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "commsinclude.h"

class ClientSocket
{
public:
    ClientSocket(QHostAddress serverIPAddressParam, quint16 serverPortParam);
    ~ClientSocket();

    bool sendRecieve(string **ppErrString, QString pRequestMessage, QString **pReplyMessage);

private:
    QTcpSocket sock;
    QHostAddress serverIPAddress;
    quint16 serverPort;
};

#endif // CLIENTSOCKET_H
