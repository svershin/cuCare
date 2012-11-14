#include <QtCore>
#include <QtGlobal>
#include <iostream>
#include "ServerSocket.h"
#include "ClientSocket.h"
//#include "../qjson/src/parser.h"
//#include "../qjson/src/serializer.h"
//#include "../qjson/src/qobjecthelper.h"


using namespace std;

bool testClientSocket(quint16 port)
{
    cout << "Testing Client..." << endl;
    ClientSocket* clie = new ClientSocket();
    QByteArray toSend = QByteArray("Here's a message!");
    cout << "Message to send: " << QString(toSend).toStdString() << endl;
    QByteArray qba = clie->sendReceive(QHostAddress(QString("127.0.0.1")), port, toSend);
    cout << "Received string: " << QString(qba).toStdString() << endl;
    return 1;
}

int runServerSocket(int argc, char* argv[])
{
    cout << "Testing Server..." << endl;
    ServerSocket *serv = new ServerSocket();
    serv->startListening((quint16)60004);

}

int main(int argc, char* argv[])
{


    if(argc > 1)
    {
        string input = string(argv[1]);
        if(input == "server")
        {
            QCoreApplication consoleApp(argc, argv);
            runServerSocket(argc, argv);
            return consoleApp.exec();
        }
        else if(input == "client")
        {
            testClientSocket((quint16)60004);
        }
        else
        {
            cout << "Invalid Input..." << endl;
            return -1;
        }
    }
    else
    {
        cout << "No arguments provided. Must specify either \"client\" or \"server\"" << endl;
        return -1;
    }
}


