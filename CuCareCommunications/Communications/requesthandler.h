#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include "commsinclude.h"
#include "serversocket.h"

class RequestHandler
{
public:
    RequestHandler();

    void handleRequest(QVariantMap);

private:
    ServerSocket serveSock;
};

void wait();


#endif // REQUESTHANDLER_H
