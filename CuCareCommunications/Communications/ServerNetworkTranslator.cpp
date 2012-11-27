#include "ServerNetworkTranslator.h"
#include "ServerNetworkRequestInterpreter.h"

ServerNetworkTranslator::ServerNetworkTranslator()
{
}

QByteArray ServerNetworkTranslator::translateAndHandleRequest(const QByteArray& requestBytes)
{
    QVariantMap requestMap, replyMap;
    QByteArray replyBytes;
    try
    {
        requestMap = deserializeMessage(requestBytes);
    }
    catch(...)
    {
        throw(string("an error occurred on the server during de-serialization of the request"));
    }

    replyMap = ServerNetworkRequestInterpreter::interpretAndHandleRequest(requestMap);

    try
    {
        replyBytes = serializeMessage(replyMap);
    }
    catch(...)
    {
        throw(string("an error occurred on the server during serialization of the reply"));
    }

    return replyBytes;
}

QByteArray ServerNetworkTranslator::giveErrorReply(const string& errorString)
{
    return serializeMessage(ServerNetworkRequestInterpreter::giveErrorReply(errorString));
}
