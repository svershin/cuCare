#ifndef SERVERNETWORKTRANSLATOR_H
#define SERVERNETWORKTRANSLATOR_H

#include <QtCore>
#include <QtNetwork>
#include "BaseNetworkTranslator.h"

using namespace std;

class ServerNetworkTranslator : public BaseNetworkTranslator
{

public:
    virtual ~ServerNetworkTranslator() = 0;

    static QByteArray translateAndHandleRequest(const QByteArray& message);
    static QByteArray giveErrorReply(const string& errorString);
};

#endif // SERVERNETWORKTRANSLATOR_H
