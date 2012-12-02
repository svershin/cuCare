#ifndef SERVERNETWORKTRANSLATOR_H
#define SERVERNETWORKTRANSLATOR_H

#include <QtCore>
#include <QtNetwork>
#include "AbstractNetworkTranslator.h"

using namespace std;

class ServerNetworkTranslator : public AbstractNetworkTranslator
{

public:
    virtual ~ServerNetworkTranslator() = 0;

    static QByteArray translateAndHandleRequest(const QByteArray& message);
    static QByteArray giveErrorReply(const string& errorString);
};

#endif // SERVERNETWORKTRANSLATOR_H
