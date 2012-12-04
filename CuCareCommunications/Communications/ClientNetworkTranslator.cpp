#include "ClientNetworkTranslator.h"

using namespace std;

ClientNetworkTranslator::~ClientNetworkTranslator(){}

QVariantMap ClientNetworkTranslator::makeRequest(QHostAddress IP, quint16 port, QVariantMap requestMap)
{
    ClientNetworkConnection connection;
    QByteArray requestBytes, replyBytes;
    QVariantMap replyMap;

    try
    {
        requestBytes = serializeMessage(requestMap);
    }
    catch(...)
    {
        throw(string("An error occurred during serialization of the request"));
    }

    replyBytes = connection.sendReceive(IP, port, requestBytes);

    try
    {

        replyMap = deserializeMessage(replyBytes);
    }
    catch(...)
    {
        throw(string("An error occurred during de-serialization of the server's reply"));
    }

    return replyMap;
}
