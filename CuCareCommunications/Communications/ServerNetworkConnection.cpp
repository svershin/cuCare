#include "ServerNetworkConnection.h"

ServerNetworkConnection::ServerNetworkConnection(QTcpSocket *connectedSocketParam)
{
    connectedSocket = connectedSocketParam;
}


ServerNetworkConnection::~ServerNetworkConnection()
{
    delete connectedSocket;
}

void ServerNetworkConnection::handleRequest()
{
    try
    {
    connectedSocket->waitForReadyRead();
    QByteArray requestMessage = connectedSocket->readAll();

    std::cout << "Received message: " << QString(requestMessage).toStdString() << std::endl;

    qint64 written = connectedSocket->write(ServerNetworkTranslator::translateAndHandleRequest(requestMessage));

    std::cout << "Bytes written: " << written << std::endl;
    }
    catch (string errorString)
    {
        connectedSocket->write(ServerNetworkTranslator::giveErrorReply(errorString));
    }
    catch (...)
    {
        connectedSocket->write(ServerNetworkTranslator::giveErrorReply(string("unknown server error")));
    }

    connectedSocket->waitForDisconnected();
}
