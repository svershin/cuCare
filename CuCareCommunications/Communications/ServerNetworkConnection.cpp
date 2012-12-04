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
        QByteArray request;
        while(!ClientNetworkConnection::containsEOT(request))
        {
            if(!connectedSocket->waitForReadyRead(CLIENT_REQUEST_WAIT_TIME_MS))
            {
                std::cout << "Timed out waiting for client's request" << endl;
                throw(string("Timed out waiting for client's request"));
                return;
            }
            request.append(connectedSocket->readAll());
        }

        request.chop(1);

        wrappedWrite(ServerNetworkTranslator::translateAndHandleRequest(request));

    }
    catch (string errorString)
    {
        wrappedWrite(ServerNetworkTranslator::giveErrorReply(errorString));
    }
    catch (char const *errorString)
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


qint64 ServerNetworkConnection::wrappedWrite(QByteArray reply)
{
    return connectedSocket->write(reply.append(END_OF_TRANSMISSION_CHARACTER));
}
