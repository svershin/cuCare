#include "ClientSocket.h"
#include <iostream>

ClientSocket::ClientSocket()
    : QTcpSocket()
{
    connect(this, SIGNAL(connected()), this, SLOT(writeRequest()));
}

ClientSocket::ClientSocket(const ClientSocket& origin)
    : QTcpSocket()
{}

ClientSocket& ClientSocket::operator=(const ClientSocket& origin)
{}

quint64 ClientSocket::writeRequest()
{
    return write(requestMessage);
}

QByteArray ClientSocket::sendReceive(QHostAddress serverIP, quint16 serverPort, QByteArray request)
{
    requestMessage = request;
    connectToHost(serverIP, serverPort);
    if(!waitForConnected())
    {
        std::cout << "Failed to connect to server" << endl;
        throw "Failed to connect to server";
    }
    waitForReadyRead();
    return readAll();
}
