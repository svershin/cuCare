#ifndef COMMSTESTS_H
#define COMMSTESTS_H

#include "ServerController.h"
#include "ServerNetworkConnection.h"
#include "ServerNetworkInterface.h"
#include "ServerNetworkListener.h"
#include "ServerNetworkRequestInterpreter.h"
#include "ServerNetworkTranslator.h"

class CommsTests
{
public:
    CommsTests();

    void testServerSide();
};

#endif // COMMSTESTS_H
