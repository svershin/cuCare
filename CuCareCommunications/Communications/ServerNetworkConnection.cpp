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

    qint64 written = wrappedWrite(ServerNetworkTranslator::translateAndHandleRequest(requestMessage));

    }
    catch (string errorString)
    {
        wrappedWrite(ServerNetworkTranslator::giveErrorReply(errorString));
    }
    catch (char const * errorString)
    {
        wrappedWrite(ServerNetworkTranslator::giveErrorReply(errorString));
    }
    catch (...)
    {
        wrappedWrite(ServerNetworkTranslator::giveErrorReply(string("unknown server error")));
    }

    connectedSocket->waitForDisconnected();
    connectedSocket->disconnect();

    return;
}


qint64 ServerNetworkConnection::wrappedWrite(QByteArray message)
{
    return connectedSocket->write(message.append(END_OF_TRANSMISSION_CHARACTER));
}
