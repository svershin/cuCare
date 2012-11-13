#include "ServerSocket.h"
#include <iostream>


ServerSocket::ServerSocket()
    :QTcpServer()
{
    connect(this, SIGNAL(newConnection()), this, SLOT(handleIncomingConnection()));
}

ServerSocket::ServerSocket(const ServerSocket& origin)
    :QTcpServer()
{
    connect(this, SIGNAL(newConnection()), this, SLOT(handleIncomingConnection()));
}


ServerSocket& ServerSocket::operator=(const ServerSocket& origin)
{}

bool ServerSocket::startListening(quint16 port)
{
    if(!listen(QHostAddress::Any, port))
        {
            close();
            return false;
        }

    waitForNewConnection(-1);
}

bool ServerSocket::stopListening()
{
    close();
}

void ServerSocket::handleIncomingConnection()
{
    QTcpSocket *tempSock = nextPendingConnection();
    tempSock->waitForReadyRead();
    QByteArray requestMessage = tempSock->readAll();

    std::cout << "Received message: " << QString(requestMessage).toStdString() << endl;

    //QByteArray replyMessage = ServerTranslator::interactWithStorage(requestMessage);
    QByteArray replyMessage = QByteArray("Got it!"); //TODO: this line (the the left) is just test code. Something like the line above will be in the real implementation.

    tempSock->write(replyMessage);
    tempSock->disconnectFromHost();
    delete tempSock;
    return;
}
