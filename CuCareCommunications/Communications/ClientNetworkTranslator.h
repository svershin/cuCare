#ifndef CLIENTNETWORKTRANSLATOR_H
#define CLIENTNETWORKTRANSLATOR_H

#include <QtCore>
#include <QtNetwork>
#include "BaseNetworkTranslator.h"
#include "ClientNetworkConnection.h"

class ClientNetworkTranslator : public BaseNetworkTranslator
{
public:
    virtual ~ClientNetworkTranslator() = 0;

    //Function that serializes a request map
    static QVariantMap makeRequest(QHostAddress IP, quint16 port, QVariantMap requestMap);
};

#endif // CLIENTNETWORKTRANSLATOR_H
