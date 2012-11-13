#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QtNetwork>
#include <QTcpServer>

class ServerSocket : public QTcpServer
{
    Q_OBJECT

public:
    ServerSocket();
    ServerSocket(const ServerSocket& origin);
    ServerSocket& operator=(const ServerSocket& origin);

    bool startListening(quint16 port);
    bool stopListening();

private slots:
    void handleIncomingConnection();

};

#endif // SERVERSOCKET_H
