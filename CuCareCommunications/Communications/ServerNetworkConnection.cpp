#include "ServerNetworkConnection.h"

ServerNetworkConnection::ServerNetworkConnection(QTcpSocket *connectedSocketParam)
    : connectedSocket(connectedSocketParam)
{}


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

    qint64 written = connectedSocket->write(ServerNetworkTranslator::translateAndHandleRequest(requestMessage));

    }
    catch (string errorString)
    {
        connectedSocket->write(ServerNetworkTranslator::giveErrorReply(errorString));
    }
    catch (char const * errorString)
    {
        connectedSocket->write(ServerNetworkTranslator::giveErrorReply(errorString));
    }
    catch (...)
    {
        connectedSocket->write(ServerNetworkTranslator::giveErrorReply(string("unknown server error")));
    }

    connectedSocket->waitForDisconnected();
    connectedSocket->disconnect();

    return;
}
