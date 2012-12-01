#ifndef COMMSTESTS_H
#define COMMSTESTS_H

#include "ServerController.h"
#include "ServerNetworkConnection.h"
#include "ServerNetworkInterface.h"
#include "ServerNetworkListener.h"
#include "ServerNetworkRequestInterpreter.h"
#include "ServerNetworkTranslator.h"
#include "ClientNetworkInterface.h"
#include "AbstractNetworkMessenger.h"

class CommsTests
{
public:
    CommsTests();

    static void testServerSide();

    static void testClient1();

    static void testClient2();
};

#endif // COMMSTESTS_H
