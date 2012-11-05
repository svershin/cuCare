#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include "commsinclude.h"

class MessageParser
{
public:
    MessageParser();

    bool parseCreateReply(string **ppErrString, QString reply, int **ppUid);
    bool parsePushReply(string **ppErrString, QString reply);

    //TODO: pull functions
};

#endif // MESSAGEPARSER_H
