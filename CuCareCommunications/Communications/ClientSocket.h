#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtGlobal>
#include <QtNetwork>


class ClientSocket : public QTcpSocket
{
public:
    ClientSocket(QObject *parent = 0);

    QByteArray sendReceive(QHostAddress serverIP, quint16 serverPort, QByteArray request);
};

#endif // CLIENTSOCKET_H
