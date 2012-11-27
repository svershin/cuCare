#include "AbstractNetworkTranslator.h"

QByteArray AbstractNetworkTranslator::serializeMessage(const QVariantMap& inMessage)
{
    QJson::Serializer cerealizer;
    return cerealizer.serialize(inMessage);
}

QVariantMap AbstractNetworkTranslator::deserializeMessage(const QByteArray& inMessage)
{
    QJson::Parser parser;
    return parser.parse(inMessage).toMap();
}
