#ifndef ABSTRACTNETWORKMESSENGER_H
#define ABSTRACTNETWORKMESSENGER_H

#include <QtGlobal>
#include <QtCore>

using namespace std;

#define REQUEST_TYPE_KEY "RequestType"
#define REQUEST_OBJECT_TYPE_KEY "ObjectType"
#define REQUEST_OBJECT_MAP_KEY "ObjectMap"

#define REPLY_STATUS_KEY "Status"
#define REPLY_ID_KEY "ObjectID"
#define REPLY_OBJECT_MAP_LIST_KEY "ObjectMapList"
#define REPLY_ERROR_MESSAGE_KEY "ErrorMessage"

class AbstractNetworkMessenger
{
public:
    virtual ~AbstractNetworkMessenger() = 0;

//protected:
    enum RequestType {CREATE,   //0
                      PUSH,     //1
                      PULL      //2
                     };

    enum ReplyStatus {FAILURE_REPLY,  //0
                      SUCCESS_REPLY   //1
                     };

    static QVariantMap packRequest(RequestType requestType, string objectType, const map<string, string>& objectMap);

    static QVariantMap packCreateReply(const int& id);
    static QVariantMap packPushReply();
    static QVariantMap packPullReply(const list< map<string, string > *>& pInList);
    static QVariantMap packErrorReply(const string& errorString);

    //Functions to unpack pieces of a request
    static  RequestType unpackRequestType(const QVariantMap& requestMap);
    static  string unpackRequestObjectType(const QVariantMap& requestMap);
    static  void unpackRequestObjectMap(const QVariantMap& requestMap, map<string, string>* pOutMap);

    //Function to unpack pieces of a reply
    static ReplyStatus unpackReplyStatus(const QVariantMap& replyMap);
    static int unpackCreateReplyContents(const QVariantMap& replyMap);
    static void unpackPullReplyContents(const QVariantMap& replyMap, list< map<string, string>* > *pOutList);
    static string unpackErrorReplyContents(const QVariantMap& replyMap);


//private:

    static void stringMapToQVariantMap(const map<string, string>& inMap, QVariantMap *pOutMap);
    static QVariantMap stringMapToQVariantMap(const map<string, string>& inMap);

    static void qVariantMapToStringMap(const QVariantMap& inMap, map<string, string> *pOutMap);
    static map<string, string> qVariantMapToStringMap(const QVariantMap& inMap);

    static void mapListToQVariantList(const list< map<string, string> *>& inList, QVariantList *pOutList);
    static QVariantList mapListToQVariantList(const list< map<string, string> *>& inList);

    static void qVariantListToMapList(const QVariantList& inList, list< map<string, string>* >* pOutList);
    static list< map<string, string> *> qVariantListToMapList(const QVariantList& inList);

};

#endif // ABSTRACTNETWORKMESSENGER_H

