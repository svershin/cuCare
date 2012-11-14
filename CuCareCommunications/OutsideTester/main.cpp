#include <QtGlobal>
#include <iostream>
#include "ServerSocket.h"
#include "ClientSocket.h"
//#include "../qjson/src/parser.h"
//#include "../qjson/src/serializer.h"
//#include "../qjson/src/qobjecthelper.h"


using namespace std;

bool testClientSocket()
{
    ClientSocket* clie = new ClientSocket();
    QByteArray toSend = QByteArray("Here's a message!");
    cout << "Message to send: " << QString(toSend).toStdString() << endl;
    QByteArray qba = clie->sendReceive(QHostAddress(QString("127.0.0.1")), (quint16)60004, toSend);
    cout << "Received string: " << QString(qba).toStdString() << endl;
    return 1;
}

bool runServerSocket()
{
    ServerSocket *serv = new ServerSocket();
    serv->startListening((quint16)60004);

    return 1;
}

int main(int argc, char* argv[])
{
    cout << argc << endl;
    string input = "";
    if(argc > 1)
    {
    input = argv[1];
    }


    if(input == "serve")
    {
        runServerSocket();
    }
    else
    {
        testClientSocket();
    }
    //cout << input << endl;
    //testClientSocket();


    return 1;
}


