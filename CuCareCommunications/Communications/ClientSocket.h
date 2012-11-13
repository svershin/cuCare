#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtGlobal>
#include <QtNetwork>
#include <QTcpSocket>


class ClientSocket : public QTcpSocket
{
    Q_OBJECT

public:
    ClientSocket();
    ClientSocket(const ClientSocket& origin);
    ClientSocket& operator=(const ClientSocket& origin);

    //sendReceive is a high level function that attempts to send a request to the destination host (the cuCare server, in this case) and wait for a reply.
    QByteArray sendReceive(QHostAddress serverIP, quint16 serverPort, QByteArray request);

private slots:
    quint64 writeRequest();

private:
    QByteArray requestMessage;
};

#endif // CLIENTSOCKET_H
