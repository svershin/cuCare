#ifndef SERVERNETWORKREQUESTINTERPRETER_H
#define SERVERNETWORKREQUESTINTERPRETER_H

#include <QtCore>
#include "ServerController.h"
#include "BaseNetworkMessenger.h"

class ServerNetworkRequestInterpreter : public BaseNetworkMessenger
{
public:
    virtual ~ServerNetworkRequestInterpreter() = 0;

    static QVariantMap interpretAndHandleRequest(QVariantMap);

    static QVariantMap giveErrorReply(const string& errorString);
};

#endif // SERVERNETWORKREQUESTINTERPRETER_H
