#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QtGlobal>
#include <QtNetwork>
#include <QTcpServer>

class ServerSocket : public QTcpServer
{
public:
    ServerSocket(QObject *parent = 0);

    bool startListening(quint16 port);
    bool stopListening();

private slots:
    void handleIncomingConnection();

};

#endif // SERVERSOCKET_H
