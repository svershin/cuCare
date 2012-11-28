#include <iostream>

#include "ServerNetworkListener.h"

ServerNetworkListener::ServerNetworkListener()
    :QTcpServer()
{
    connect(this, SIGNAL(newConnection()), this, SLOT(handleIncomingConnection()));
}

ServerNetworkListener::ServerNetworkListener(const ServerNetworkListener& origin)
    :QTcpServer()
{
    connect(this, SIGNAL(newConnection()), this, SLOT(ServerNetworkListener()));
}


ServerNetworkListener& ServerNetworkListener::operator=(const ServerNetworkListener& origin)
{}

bool ServerNetworkListener::startListening(quint16 port)
{
    if(!listen(QHostAddress::Any, port))
        {
            close();
            return false;
        }
    return true;
}

bool ServerNetworkListener::stopListening()
{
    close();
    return true;
}

void ServerNetworkListener::handleIncomingConnection()
{
    std::cout << "New Connection initiated" << std::endl;
    ServerNetworkConnection connection(nextPendingConnection());
    connection.handleRequest();
    return;
}
