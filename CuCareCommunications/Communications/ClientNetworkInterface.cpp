#include "ClientNetworkInterface.h"

ClientNetworkInterface::ClientNetworkInterface(string serverIPParam, quint16 serverPortParam)
    :
      serverIP(makeAndCheckQHostAddress(QString::fromStdString(serverIPParam))),
      serverPort(serverPortParam)
{}

bool ClientNetworkInterface::create(string tableName, string idKey, map<string, string> *pObjectMap, int *pOutID, string *pErrorString)
{
    QVariantMap requestMessage, replyMessage;

    try
    {
        requestMessage = packRequest(CREATE, tableName, idKey, *pObjectMap);

        replyMessage = ClientNetworkTranslator::makeRequest(serverIP, serverPort, requestMessage);

        if(SUCCESS_REPLY == unpackReplyStatus(replyMessage))
        {
            unpackCreateReplyContents(replyMessage);

            *pOutID = unpackCreateReplyContents(replyMessage);

            return true;
        }
        else if(FAILURE_REPLY == unpackReplyStatus(replyMessage))
        {
            *pErrorString = unpackErrorReplyContents(replyMessage);

            return false;
        }
        else
        {
            throw(string("invalid status field in server reply"));
        }
    }
    catch(string errStr)
    {
        *pErrorString = errStr;
        return false;
    }
}

bool ClientNetworkInterface::push(string tableName, string idKey, map<string, string> *pObjectMap, string *pErrorString)
{
    QVariantMap requestMessage, replyMessage;

    try
    {
        requestMessage = packRequest(PUSH, tableName, idKey, *pObjectMap);
        replyMessage = ClientNetworkTranslator::makeRequest(serverIP, serverPort, requestMessage);
        if(SUCCESS_REPLY == unpackReplyStatus(replyMessage))
        {
            return true;
        }
        else if(FAILURE_REPLY == unpackReplyStatus(replyMessage))
        {
            *pErrorString = unpackErrorReplyContents(replyMessage);
            return false;
        }
        else
        {
            throw(string("invalid status field in server reply"));
        }
    }
    catch(string errStr)
    {
        *pErrorString = errStr;
        return false;
    }
}

bool ClientNetworkInterface::pull(string tableName, string idKey, map<string, string> *pObjectMap, list< map<string, string> *> *pObjectList, string *pErrorString)
{

    try
    {
        QVariantMap requestMessage = packRequest(PULL, tableName, idKey, *pObjectMap);
        QVariantMap replyMessage = ClientNetworkTranslator::makeRequest(serverIP, serverPort, requestMessage);
        if(SUCCESS_REPLY == unpackReplyStatus(replyMessage))
        {
            unpackPullReplyContents(replyMessage, pObjectList);
            return true;
        }
        else if(FAILURE_REPLY == unpackReplyStatus(replyMessage))
        {
            *pErrorString = unpackErrorReplyContents(replyMessage);
            return false;
        }
        else
        {
            throw(string("invalid status field in server reply"));
        }
    }
    catch(string errStr)
    {
        *pErrorString = errStr;
        return false;
    }
}



