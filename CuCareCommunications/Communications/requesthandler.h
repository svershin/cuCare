#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include "commsinclude.h"
#include "serversocket.h"
#include "messenger.h"
#include "messageparser.h"
#include "messagegenerator.h"
#include "../CuCareServer/Repository.h"

class RequestHandler : public QObject
{

    Q_OBJECT

public:
    RequestHandler(QObject *parent = 0);

    QByteArray interactWithDatabase(QVariantMap);

    int startListening(quint16);

    int stopListening();

public slots:
    void handleRequest();

private:
    QTcpServer *serveSock;
    Repository *pRepo;
};




#endif // REQUESTHANDLER_H
