#include "AbstractNetworkMessenger.h"

using namespace std;

AbstractNetworkMessenger::~AbstractNetworkMessenger(){}

void AbstractNetworkMessenger::stringMapToQVariantMap(const map<string, string>& inMap, QVariantMap *pOutMap)
{
    if(! pOutMap->empty())  { throw (string("non-empty QVariantMap passed in stringMapToQVariantMap")); }

    map<string, string>::const_iterator it = inMap.begin();
    while(it != inMap.end())
    {
        (*pOutMap)[QString::fromStdString(it->first)] = QVariant(QString::fromStdString(it->second));
        it++;
    }

    return;
}

QVariantMap AbstractNetworkMessenger::stringMapToQVariantMap(const map<string, string> &inMap)
{
    QVariantMap outMap;
    stringMapToQVariantMap(inMap, &outMap);
    return outMap;
}


void AbstractNetworkMessenger::qVariantMapToStringMap(const QVariantMap& inMap, map<string, string> *pOutMap)
{
    if(! pOutMap->empty())  { throw (string("non-empty map passed in qVariantMapToStringMap")); }

    QVariantMap::const_iterator it = inMap.begin();
    while(it != inMap.end())
    {
        (*pOutMap)[((QString)it.key()).toStdString()] = ((QVariant)it.value()).toString().toStdString();
        it++;
    }
    return;
}

map<string, string> AbstractNetworkMessenger::qVariantMapToStringMap(const QVariantMap &inMap)
{
    map<string, string> outMap;
    qVariantMapToStringMap(inMap, &outMap);
    return outMap;
}


void AbstractNetworkMessenger::mapListToQVariantList(const list< map<string, string>* >& inList, QVariantList *pOutList)
{
    if(! pOutList->empty())  { throw (string("non-empty list passed in mapListToQVariantList")); }

    list< map<string, string> *>::const_iterator it = inList.begin();
    while(it != inList.end())
    {
        QVariantMap tempMap;
        stringMapToQVariantMap((*(*it)), &tempMap);
        pOutList->push_back(tempMap);
        it++;
    }

    return;
}

QVariantList AbstractNetworkMessenger::mapListToQVariantList(const list< map<string, string> *>& inList)
{
    QVariantList outList;
    mapListToQVariantList(inList, &outList);
    return outList;
}


void AbstractNetworkMessenger::qVariantListToMapList(const QVariantList& inList, list< map<string, string>* >* pOutList)
{
    if(! pOutList->empty())  { throw (string("non-empty list passed in qVariantListToMapList")); }

    QVariantList::const_iterator it = inList.begin();
    while(it != inList.end())
    {
        map<string, string>* tempMap = new map<string, string>();
        qVariantMapToStringMap(it->toMap(), tempMap);
        pOutList->push_back(tempMap);
        it++;
    }

    return;
}

list< map<string, string> *> AbstractNetworkMessenger::qVariantListToMapList(const QVariantList& inList)
{
    list< map<string, string> *> outList;
    qVariantListToMapList(inList, &outList);
    return outList;
}


QVariantMap AbstractNetworkMessenger::packRequest(RequestType requestType, string objectType, const map<string, string>& objectMap)
{
    QVariantMap outMap;

    outMap[QString(REQUEST_TYPE_KEY)] = QVariant(QString::number(requestType) );
    outMap[QString(REQUEST_OBJECT_TYPE_KEY)] = QVariant (QString::fromStdString(objectType) );

    QVariantMap variantObjectMap;
    stringMapToQVariantMap(objectMap, &variantObjectMap);
    outMap[QString(REQUEST_OBJECT_MAP_KEY)] = QVariant (variantObjectMap);

    return outMap;
}

QVariantMap AbstractNetworkMessenger::packCreateReply(const int& id)
{
    QVariantMap outMap;

    outMap[QString(REPLY_STATUS_KEY)] = QVariant(SUCCESS_REPLY);
    outMap[QString(REPLY_ID_KEY)] = QVariant(id);

    return outMap;
}

QVariantMap AbstractNetworkMessenger::packPushReply()
{
    QVariantMap outMap;

    outMap[QString(REPLY_STATUS_KEY)] = QVariant(SUCCESS_REPLY);

    return outMap;
}

QVariantMap AbstractNetworkMessenger::packPullReply(const list< map<string, string > *>& pInList)
{
    QVariantMap outMap;

    outMap[QString(REPLY_STATUS_KEY)] = QVariant(SUCCESS_REPLY);

    QVariantList variantObjectMapList;
    mapListToQVariantList(pInList, &variantObjectMapList);
    outMap[REPLY_OBJECT_MAP_LIST_KEY] = QVariant(variantObjectMapList);

    return outMap;
}

QVariantMap AbstractNetworkMessenger::packErrorReply(const string& errorString)
{
    QVariantMap outMap;

    outMap[QString(REPLY_STATUS_KEY)] = QVariant(FAILURE_REPLY);
    outMap[QString(REPLY_ERROR_MESSAGE_KEY)] = QVariant(QString::fromStdString(errorString));

    return outMap;
}

//Functions to unpack pieces of a request
AbstractNetworkMessenger::RequestType AbstractNetworkMessenger::unpackRequestType(const QVariantMap& requestMap)
{
    QString messageKey(REQUEST_TYPE_KEY);
    if(requestMap.contains(messageKey))
    {
        return (RequestType)requestMap[messageKey].toInt();
    }
    else
    {
        throw(string("request is missing ")+= string(REQUEST_TYPE_KEY)+= string(" field"));
    }
}

string AbstractNetworkMessenger::unpackRequestObjectType(const QVariantMap& requestMap)
{
    QString messageKey(REQUEST_OBJECT_TYPE_KEY);
    if(requestMap.contains(messageKey))
    {
        return requestMap[messageKey].toString().toStdString();
    }
    else
    {
        throw(string("request is missing ")+= string(REQUEST_OBJECT_TYPE_KEY)+= string(" field"));
    }
}


    void AbstractNetworkMessenger::unpackRequestObjectMap(const QVariantMap& requestMap, map<string, string> *pOutMap)
{
    QString messageKey(REQUEST_OBJECT_MAP_KEY);
    if(requestMap.contains(messageKey))
    {
        qVariantMapToStringMap(requestMap[QString(REQUEST_OBJECT_MAP_KEY)].toMap(), pOutMap);
        return;
    }
    else
    {
        throw(string("request is missing ")+= string(REQUEST_OBJECT_MAP_KEY)+= string(" field"));
    }
}


//Function to unpack pieces of a reply
AbstractNetworkMessenger::ReplyStatus AbstractNetworkMessenger::unpackReplyStatus(const QVariantMap& replyMap)
{
    QString messageKey(REPLY_STATUS_KEY);
    if(replyMap.contains(messageKey))
    {
        return (ReplyStatus)replyMap[messageKey].toInt();
    }
    else
    {
        throw(string("server reply is missing ")+= string(REPLY_STATUS_KEY)+= string(" field"));
    }

}

int AbstractNetworkMessenger::unpackCreateReplyContents(const QVariantMap& replyMap)
{
    QString messageKey(REPLY_ID_KEY);
    if(replyMap.contains(messageKey))
    {
        return replyMap[messageKey].toInt();
    }
    else
    {
        throw(string("server reply is missing ")+= string(REPLY_ID_KEY)+= string(" field"));
    }
}


void AbstractNetworkMessenger::unpackPullReplyContents(const QVariantMap& replyMap, list< map<string, string>* > *pOutList)
{
    QString messageKey(REPLY_OBJECT_MAP_LIST_KEY);
    if(replyMap.contains(messageKey))
    {
        qVariantListToMapList(replyMap[messageKey].toList(), pOutList);
        return;
    }
    else
    {
        throw(string("server reply is missing ")+= string(REPLY_OBJECT_MAP_LIST_KEY)+= string(" field"));
    }
}

string AbstractNetworkMessenger::unpackErrorReplyContents(const QVariantMap& replyMap)
{
    QString messageKey(REPLY_ERROR_MESSAGE_KEY);
    if(replyMap.contains(messageKey))
    {
        return ( replyMap[messageKey].toString().toStdString() );
    }
    else
    {
        throw(string("server reply is missing ")+= string(REPLY_ERROR_MESSAGE_KEY)+= string(" field"));
    }
}
