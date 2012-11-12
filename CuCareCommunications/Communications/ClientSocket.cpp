#include "ClientSocket.h"

ClientSocket::ClientSocket(QObject *parent)
    : QTcpSocket(parent)
{

}

QByteArray ClientSocket::sendReceive(QByteArray request)
{

}
