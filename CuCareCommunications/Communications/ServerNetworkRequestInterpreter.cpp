#include "ServerNetworkRequestInterpreter.h"
#include "AbstractNetworkMessenger.h"

ServerNetworkRequestInterpreter::ServerNetworkRequestInterpreter()
{}

ServerNetworkRequestInterpreter::interpretAndHandleRequest(QVariantMap requestMessage)
{
    RequestType reqType = unpackRequestType(requestMessage);
    string objectType = unpackRequestObjectType(requestMessage);
    map<string, string> objectMap; unpackRequestObjectMap(requestMessage, &objectMap);
    string errorString;

    switch(reqType)
    {
    case CREATE:
        int outID = -1;
        if(ServerController::create(objectType, &objectMap, &ID, &errorString))
        {
            return packCreateReply(outID);
        }
        else
        {
            throw(errorString);
        }
        break;

    case PUSH:
        if(ServerController::push(objectType, &objectMap, &errorString))
        {
            return packPushReply();
        }
        else
        {
            throw(errorString);
        }
        break;

    case PULL:
        list< map<string, string> *> outMap;
        if(ServerController::pull(objectType, &objectMap, &outMap, &errorString))
        {
            return packPullReply(outMap);
        }
        else
        {
            throw(errorString);
        }
        break;

    default:
        throw(string("invalid status field found in request on server"));
    }
}

ServerNetworkRequestInterpreter::giveErrorReply(const string &errorString)
{
    return packErrorReply(errorString);
}
