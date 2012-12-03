#include <QtCore/QCoreApplication>
#include <iostream>
#include "Tests.h"
#include "../CuCareCommunications/Communications/ServerController.h"
#include "../CuCareCommunications/Communications/ServerNetworkInterface.h"

using namespace std;

int main(int argc, char *argv[])
{


    if(argc != 3)
    {
        cout << "ERROR: Invalid Parameters - you must pass a port number and then a 24-hour time of format hh:mm:ss (eg 19:00:00)." << endl;
    }

    cout << "Starting Server ...." << endl;


    try
    {
    QCoreApplication app(argc, argv);

    ServerController::makeInstance(argv[2]);
    ServerNetworkInterface sni((quint16)QString(argv[1]).toInt());

    return app.exec();
    }

    catch(string errStr)
    {
        cout << "Server Exception: " << errStr << " ... exiting ..." << endl;
        return -1;
    }
    catch(char const* errChars)
    {
        cout << "Server Exception: " << errChars << " ... exiting ..." << endl;
        return -1;
    }
    catch(...)
    {
        cout << "Unknown Server Error ... exiting ..." << endl;
        return -1;
    }
}


