#include "ClientNetworkConnection.h"
#include <iostream>

using namespace std;

ClientNetworkConnection::ClientNetworkConnection()
    :QTcpSocket()
{}


ClientNetworkConnection::ClientNetworkConnection(const ClientNetworkConnection& origin)
    :QTcpSocket()
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

    wrappedWrite(request);

    QByteArray reply;
    while(!containsEOT(reply))
    {
        if(!waitForReadyRead(SERVER_RESPONSE_WAIT_TIME_MS))
        {
            std::cout << "Timed out waiting for server response" << endl;
            throw string("Timed out waiting for server response");
        }
        reply.append(readAll());
    }

    disconnectFromHost();

    reply.chop(1);
    return reply;
}


bool ClientNetworkConnection::containsEOT(QByteArray message)
{
    return message.endsWith(END_OF_TRANSMISSION_CHARACTER);
}


qint64 ClientNetworkConnection::wrappedWrite(QByteArray request)
{
    return write(request.append(END_OF_TRANSMISSION_CHARACTER));
}
