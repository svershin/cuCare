#include "ServerNetworkRequestInterpreter.h"
#include "AbstractNetworkMessenger.h"

ServerNetworkRequestInterpreter::ServerNetworkRequestInterpreter()
{}

QVariantMap ServerNetworkRequestInterpreter::interpretAndHandleRequest(QVariantMap requestMessage)
{
    RequestType reqType = unpackRequestType(requestMessage);
    string objectType = unpackRequestObjectType(requestMessage);
    map<string, string> objectMap; unpackRequestObjectMap(requestMessage, &objectMap);
    string errorString;
    QVariantMap returnMap;

    switch(reqType)
    {
        case CREATE:
        {
            int outID = -1;
            if(ServerController::getInstance()->create(objectType, &objectMap, &outID, &errorString))
            {
                 returnMap = packCreateReply(outID);
            }
            else
            {
                throw(errorString);
            }
            break;
        }

        case PUSH:
        {
            if(ServerController::getInstance()->push(objectType, &objectMap, &errorString))
            {
                returnMap = packPushReply();
            }
            else
            {
                throw(errorString);
            }
            break;
        }

        case PULL:
        {
            list< map<string, string> *> outMap;
            if(ServerController::getInstance()->pull(objectType, &objectMap, &outMap, &errorString))
            {
                returnMap = packPullReply(outMap);
                AbstractNetworkMessenger::destroyListContents(outMap);
            }
            else
            {
                throw(errorString);
            }
            break;
        }
        default:
        {
            throw(string("invalid status field found in request on server"));
        }
    }

    return returnMap;
}

QVariantMap ServerNetworkRequestInterpreter::giveErrorReply(const string &errorString)
{
    return packErrorReply(errorString);
}
