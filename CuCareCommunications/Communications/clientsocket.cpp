#include "clientsocket.h"

ClientSocket::ClientSocket(QHostAddress serverIPAddressParam, quint16 serverPortParam)
{
    serverIPAddress = serverIPAddressParam;
    serverPort = serverPortParam;
}


//Note: not yet tested
bool ClientSocket::sendRecieve(string **ppErrString, QString pRequestMessage, QString **pReplyMessage)
{
    char *message;
    try
    {
    sock.connectToHost(serverIPAddress, serverPort);
    sock.write((char *)pRequestMessage.toStdString().c_str(), pRequestMessage.length());
    sock.read(message, 100000);
    }
    catch(char const* pErrStr)
    {
        (*ppErrString) = new string(pErrStr);
        return false;
    }

    (*pReplyMessage) = message;
    return true;
}
