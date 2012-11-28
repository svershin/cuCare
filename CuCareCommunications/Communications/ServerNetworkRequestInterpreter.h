#ifndef SERVERNETWORKREQUESTINTERPRETER_H
#define SERVERNETWORKREQUESTINTERPRETER_H

#include <QtCore>
#include "ServerController.h"
#include "AbstractNetworkMessenger.h"

class ServerNetworkRequestInterpreter : public AbstractNetworkMessenger
{
public:
    ServerNetworkRequestInterpreter();

    static QVariantMap interpretAndHandleRequest(QVariantMap);

    static QVariantMap giveErrorReply(const string& errorString);
};

#endif // SERVERNETWORKREQUESTINTERPRETER_H
