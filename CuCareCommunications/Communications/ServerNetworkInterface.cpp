#include "ServerNetworkInterface.h"

ServerNetworkInterface::ServerNetworkInterface(quint16 port)
{
    listener = new ServerNetworkListener();
    listener->startListening(port);
}

ServerNetworkInterface::~ServerNetworkInterface()
{
    delete listener;
}
