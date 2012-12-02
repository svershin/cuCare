#include "ServerNetworkRequestInterpreter.h"
#include "BaseNetworkMessenger.h"

ServerNetworkRequestInterpreter::~ServerNetworkRequestInterpreter(){}

QVariantMap ServerNetworkRequestInterpreter::interpretAndHandleRequest(QVariantMap requestMessage)
{
    RequestType reqType = unpackRequestType(requestMessage);
    string tableName = unpackRequestTableName(requestMessage);
    string idKey = unpackRequestIdKey(requestMessage);
    map<string, string> objectMap; unpackRequestObjectMap(requestMessage, &objectMap);
    string errorString;
    QVariantMap returnMap;

    //cout << "Here's your stuff: " << endl;
    //qDebug() << requestMessage;

    switch(reqType)
    {
        case CREATE:
        {
            int outID = -1;
            if(ServerController::getInstance()->create(tableName, idKey, &objectMap, &outID, &errorString))
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
            if(ServerController::getInstance()->push(tableName, idKey, &objectMap, &errorString))
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
            if(ServerController::getInstance()->pull(tableName, idKey, &objectMap, &outMap, &errorString))
            {
                returnMap = packPullReply(outMap);
                BaseNetworkMessenger::destroyListContents(outMap);
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
    //cout << "Server error encountered: " << errorString << endl;
    return packErrorReply(errorString);
}
