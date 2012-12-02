#ifndef BASENETWORKMESSENGER_H
#define BASENETWORKMESSENGER_H

#include <QtGlobal>
#include <QtCore>
#include <QtNetwork>

using namespace std;

#define REQUEST_TYPE_KEY "RequestType"
#define REQUEST_TABLE_NAME_KEY "TableName"
#define REQUEST_ID_KEY_KEY "ID_Key"
#define REQUEST_OBJECT_MAP_KEY "ObjectMap"

#define REPLY_STATUS_KEY "Status"
#define REPLY_ID_KEY "ObjectID"
#define REPLY_OBJECT_MAP_LIST_KEY "ObjectMapList"
#define REPLY_ERROR_MESSAGE_KEY "ErrorMessage"

class BaseNetworkMessenger
{
public:
    virtual ~BaseNetworkMessenger() = 0;

#ifndef QT_DEBUG
//protected:
#endif //QT_DEBUG

    // ENUMS to track request types and reply types (ints will be sent in a message accross the network)
    //
    enum RequestType {CREATE,   //0
                      PUSH,     //1
                      PULL      //2
                     };

    enum ReplyStatus {FAILURE_REPLY,  //0
                      SUCCESS_REPLY   //1
                     };


    // HELPER FUNCTIONS for converting between formats
    //
    static void qVariantMapToStringMap(const QVariantMap& inMap, map<string, string> *pOutMap);
    static map<string, string> qVariantMapToStringMap(const QVariantMap& inMap);

    static void mapListToQVariantList(const list< map<string, string> *>& inList, QVariantList *pOutList);
    static QVariantList mapListToQVariantList(const list< map<string, string> *>& inList);

    static void qVariantListToMapList(const QVariantList& inList, list< map<string, string>* >* pOutList);
    static list< map<string, string> *> qVariantListToMapList(const QVariantList& inList);



    // FUNCTIONS FOR PACKAGING REQUESTS AND REPLIES
    //
    static QVariantMap packRequest(RequestType requestType, string tableName, string idKey, const map<string, string>& objectMap);

    static QVariantMap packCreateReply(const int& id);
    static QVariantMap packPushReply();
    static QVariantMap packPullReply(const list< map<string, string > *>& pInList);
    static QVariantMap packErrorReply(const string& errorString);


    //Functions to unpack pieces of a request
    static  RequestType unpackRequestType(const QVariantMap& requestMap);
    static  string unpackRequestTableName(const QVariantMap& requestMap);
    static  string unpackRequestIdKey(const QVariantMap& requestMap);
    static  void unpackRequestObjectMap(const QVariantMap& requestMap, map<string, string>* pOutMap);

    //Function to unpack pieces of a reply
    static ReplyStatus unpackReplyStatus(const QVariantMap& replyMap);
    static int unpackCreateReplyContents(const QVariantMap& replyMap);
    static void unpackPullReplyContents(const QVariantMap& replyMap, list< map<string, string>* > *pOutList);
    static string unpackErrorReplyContents(const QVariantMap& replyMap);

    static void stringMapToQVariantMap(const map<string, string>& inMap, QVariantMap *pOutMap);
    static QVariantMap stringMapToQVariantMap(const map<string, string>& inMap);

    static void destroyListContents(list< map<string, string> *> offList);

    static QHostAddress makeAndCheckQHostAddress(QString IPStr); //wrapper for making a QHostAddress (will throw an exception if it's not properly made)

};

#endif // BASENETWORKMESSENGER_H

