#include "ServerNetworkInterface.h"

ServerNetworkInterface::ServerNetworkInterface(quint port)
{
    listener = new ServerNetworkListener();
    listener->startListening(port);
}
