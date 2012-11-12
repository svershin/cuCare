#include "ServerSocket.h"

ServerSocket::ServerSocket(QObject *parent)
    :QTcpServer(parent)
{
    connect(this, SIGNAL(newConnection()), this, SLOT(handleIncomingConnection()));
}

bool ServerSocket::startListening(quint16 port)
{
    if(listen(QHostAddress::Any, port))
        {
           return true;
        }
        else
        {
            return false;
            close();
        }
}

bool ServerSocket::stopListening()
{
    close();
}

void ServerSocket::handleIncomingConnection()
{
    QTcpSocket *tempSock = nextPendingConnection();
    QByteArray requestMessage = tempSock->readAll();

    //QByteArray replyMessage = ServerTranslator::interactWithStorage(requestMessage);
    QByteArray replyMessage = requestMessage; //TODO: this line (the the left) is just test code. Something like the line above will be in the real implementation.

    tempSock->write(replyMessage);
    tempSock->disconnectFromHost();
    delete tempSock;
    return;
}
