#include "ClientNetworkConnection.h"
#include <iostream>

using namespace std;

ClientNetworkConnection::ClientNetworkConnection()
    : QTcpSocket()
{}


ClientNetworkConnection::ClientNetworkConnection(const ClientNetworkConnection& origin)
    : QTcpSocket()
{}

ClientNetworkConnection& ClientNetworkConnection::operator=(const ClientNetworkConnection& origin)
{}

QByteArray ClientNetworkConnection::sendReceive(QHostAddress serverIP, quint16 serverPort, QByteArray request)
{
    connectToHost(serverIP, serverPort);
    if(!waitForConnected())
    {
        std::cout << "Failed to connect to server. IP: " << serverIP.toString().toStdString() << " Port: " << serverPort << endl;
        throw string("Failed to connect to server");
    }

    write(request);

    if(!waitForReadyRead(SERVER_RESPONSE_WAIT_TIME_MS))
    {
        std::cout << "Timed out waiting for server response" << endl;
        throw string("Timed out waiting for server response");
    }

    QByteArray reply = readAll();
    disconnectFromHost();

    return reply;
}

