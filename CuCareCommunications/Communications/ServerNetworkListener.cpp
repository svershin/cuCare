#include <iostream>

#include "ServerNetworkListener.h"
#include <QDateTime>

using namespace std;

ServerNetworkListener::ServerNetworkListener()
    : QTcpServer()
{
    connect(this, SIGNAL(newConnection()), this, SLOT(handleIncomingConnection()), Qt::QueuedConnection);
}

ServerNetworkListener::ServerNetworkListener(const ServerNetworkListener& origin)
    :QTcpServer()
{
    connect(this, SIGNAL(newConnection()), this, SLOT(ServerNetworkListener()), Qt::QueuedConnection);
}


ServerNetworkListener& ServerNetworkListener::operator=(const ServerNetworkListener& origin)
{}

bool ServerNetworkListener::startListening(quint16 port)
{
    if(!listen(QHostAddress::Any, port))
    {
        close();
        throw(string("Failed to listen"));
    }
    else
    {
        cout << QDateTime::currentDateTime().toString().toStdString() << ": Listening begun on port " << port << endl;
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
    ServerNetworkConnection connection(nextPendingConnection());
    connection.handleRequest();

    return;
}
