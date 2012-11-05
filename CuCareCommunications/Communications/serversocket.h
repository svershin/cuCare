#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "commsinclude.h"
#include <QtNetwork>
#include <QTcpSocket>

class ServerSocket : public QTcpSocket
{
public:
    ServerSocket(QObject  *parent = 0);

};

#endif // SERVERSOCKET_H
