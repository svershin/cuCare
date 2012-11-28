#include <QtCore>
#include <QtGlobal>
#include <iostream>
#include "ServerNetworkListener.h"
#include "ClientNetworkConnection.h"
#include "AbstractNetworkMessenger.h"
#include "../qjson/src/serializer.h"
#include "../qjson/src/parser.h"
#include <QTime>
#include "Repository.h"
#include "StorageObject.h"
#include "CommsTests.h"

int testNumber = 0;

using namespace std;

bool testClientSocket(quint16 port)
{
    cout << "Testing Client..." << endl;
    ClientNetworkConnection* clie = new ClientNetworkConnection();
    QByteArray toSend = QByteArray("Here's a message!");
    cout << "Message to send: " << QString(toSend).toStdString() << endl;
    QByteArray qba = clie->sendReceive(QHostAddress(QString("127.0.0.1")), port, toSend);
    cout << "Received string: " << QString(qba).toStdString() << endl;
    return 1;
}

void runServerSocket(int argc, char* argv[])
{
    cout << "Testing Server..." << endl;
    ServerNetworkListener *serv = new ServerNetworkListener();
    serv->startListening((quint16)60004);

    return;
}

void testCereal()
{
    cout << "Testing Cerealization..." << endl;
    map<string, string> objMap, outMap;
    objMap[string("key1")] = string("value1");
    objMap[string("key2")] = string("value2");
    objMap[string("key3")] = string("value3");

    //newMap = AbstractNetworkMessenger::qStringMapToStringMap(AbstractNetworkMessenger::stringMapToQStringMap(origMap));
    QVariantMap reqQMap = AbstractNetworkMessenger::packRequest(AbstractNetworkMessenger::CREATE, "A Table", "Patient", objMap);
    qDebug() << reqQMap << endl << endl << endl;


    QJson::Serializer serial;
    QByteArray qbar = serial.serialize(reqQMap);
    QJson::Parser parse;
    QVariant outQVar = parse.parse(qbar);
    QVariantMap outQMap = outQVar.toMap();



    //outMap = AbstractNetworkMessenger::qVariantMapToStringMap(outQMap);

    qDebug() << outQMap << endl;
    //qDebug() << (int) AbstractNetworkMessenger::unpackRequestType(outQMap) << endl;
    //qDebug() << QString::fromStdString(AbstractNetworkMessenger::unpackRequestIdKey(outQMap)) << endl;
    //qDebug() << AbstractNetworkMessenger::stringMapToQVariantMap(AbstractNetworkMessenger::unpackRequestObjectMap(outQMap)) << endl;

    cout << "finished" << endl;
    cout << "extra text" << endl;
}



void testSandbox(string *aStr)
{
    //QTime tim = QTime::fromString("9:45:00", "h:mm:ss");
    delete aStr;
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
        else if(input == "cereal")
        {
            testCereal();
        }
        else if(input == "sand")
        {
            string *str = new string("hey");
            testSandbox(str);

        }
        else if(input == "simpleTests")
        {
            CommsTests testing;

            testing.testServerSide();
        }
        else
        {
            cout << "Invalid Input..." << endl;
            return -1;
        }

    }
    else
    {
        cout << "No arguments provided." << endl;
        return -1;
    }
}


