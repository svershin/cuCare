#ifndef CLIENTNETWORKTRANSLATOR_H
#define CLIENTNETWORKTRANSLATOR_H

#include <QtCore>
#include <QtNetwork>
#include "AbstractNetworkTranslator.h"
#include "ClientNetworkConnection.h"

class ClientNetworkTranslator : public AbstractNetworkTranslator
{
public:
    ClientNetworkTranslator();

    //Function that serializes a request map
    static QVariantMap makeRequest(QHostAddress IP, quint16 port, QVariantMap requestMap);
};

#endif // CLIENTNETWORKTRANSLATOR_H
