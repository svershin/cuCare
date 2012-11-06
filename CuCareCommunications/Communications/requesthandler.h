#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include "commsinclude.h"
#include "serversocket.h"
#include "messenger.h"
#include "messageparser.h"
#include "messagegenerator.h"
#include "../CuCareServer/Repository.h"

class RequestHandler
{
public:
    RequestHandler();



private:

    QByteArray handleRequest(QVariantMap);

    ServerSocket serveSock;
    Repository *pRepo;
};

void wait();


#endif // REQUESTHANDLER_H
