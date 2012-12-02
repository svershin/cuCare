#include "BaseNetworkTranslator.h"

BaseNetworkTranslator::~BaseNetworkTranslator() {}

QByteArray BaseNetworkTranslator::serializeMessage(const QVariantMap& inMessage)
{
    QJson::Serializer cerealizer;
    return cerealizer.serialize(inMessage);
}

QVariantMap BaseNetworkTranslator::deserializeMessage(const QByteArray& inMessage)
{
    QJson::Parser parser;
    return parser.parse(inMessage).toMap();
}
