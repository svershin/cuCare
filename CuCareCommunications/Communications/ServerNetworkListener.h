#ifndef SERVERNETWORKLISTENER_H
#define SERVERNETWORKLISTENER_H

#include <QtNetwork>
#include <QTcpServer>
#include "ServerNetworkConnection.h"

class ServerNetworkListener : public QTcpServer
{
    Q_OBJECT

public:
    ServerNetworkListener();
    ServerNetworkListener(const ServerNetworkListener& origin);
    ServerNetworkListener& operator=(const ServerNetworkListener& origin);

    bool startListening(quint16 port);
    bool stopListening();

private slots:
    void handleIncomingConnection();

};

#endif // SERVERNETWORKLISTENER_H
