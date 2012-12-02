#ifndef BASENETWORKTRANSLATOR_H
#define BASENETWORKTRANSLATOR_H

#include <QtCore>
#include <QtNetwork>
#include <iostream>
#include "../qjson/src/serializer.h"
#include "../qjson/src/parser.h"


class BaseNetworkTranslator
{
public:
    virtual ~BaseNetworkTranslator() = 0;

#ifndef QT_DEBUG
protected:
#endif //QT_DEBUG

    static QByteArray serializeMessage(const QVariantMap& inMessage);
    static QVariantMap deserializeMessage(const QByteArray& inMessage);
};

#endif // BASENETWORKTRANSLATOR_H

