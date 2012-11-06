#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include "commsinclude.h"

class MessageParser
{
public:
    MessageParser();

    enum RequestCode
    {
        CREATE_PHYSICIAN,           // 0
        CREATE_ADMIN_ASSISTANT,     // 1
        CREATE_SYS_ADMIN,           // 2
        CREATE_PATIENT,             // 3
        CREATE_CONSULTATION,        // 4
        CREATE_REFERRAL,            // 5
        CREATE_MEDICAL_TEST,        // 6
        CREATE_RETURN_CONSULTATION, // 7
        CREATE_MEDICATION_RENEWAL,  // 8

        PUSH_USER,                  // 9
        PUSH_PATIENT,               //10
        PUSH_CONSULTATION,          //11
        PUSH_REFERRAL,              //12
        PUSH_MEDICAL_TEST,          //13
        PUSH_RETURN_CONSULTATION,   //14
        PUSH_MEDICATION_RENEWAL,    //15

        PULL_PHYSICIAN,             //16
        PULL_ADMIN_ASSISTANT,       //17
        PULL_SYS_ADMIN,             //18
        PULL_PATIENT,               //19
        PULL_CONSULTATION,          //20
        PULL_REFERRAL,              //21
        PULL_MEDICAL_TEST,          //22
        PULL_RETURN_CONSULTATION,   //23
        PULL_MEDICATION_RENEWAL     //24
    };


    enum ReplyCode
    {
        FAILURE,    //0
        SUCCESS     //1
    };

    static QVariantMap qByteArrayToqvMap(QByteArray);
    static ModelObject qVariantMapToModelObject(QVariantMap);

    static bool parseCreateReply(string **ppErrString, QString reply, int **ppUid);
    static bool parsePushReply(string **ppErrString, QString reply);
};

#endif // MESSAGEPARSER_H
