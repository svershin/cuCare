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
using namespace std;


int testNumber = 0;

void printStringMap(map<string, string> strMap)
{
    map<string, string>::const_iterator it = strMap.begin();
    while(it != strMap.end())
    {
        cout << it->first << " : " << it->second << endl;
        it++;
    }
    cout << endl;
}

void printStorageObject(StorageObject& store)
{
    cout << store.getTable() << endl;
    cout << store.getIdName() << endl;
    map<string, string> strMap = store.getValues();
    printStringMap(strMap);
    cout << endl;
}





void testCereal()
{
//    cout << "Testing Cerealization..." << endl;
//    map<string, string> objMap, outMap;
//    objMap[string("key1")] = string("value1");
//    objMap[string("key2")] = string("value2");
//    objMap[string("key3")] = string("value3");

    //newMap = AbstractNetworkMessenger::qStringMapToStringMap(AbstractNetworkMessenger::stringMapToQStringMap(origMap));
    //QVariantMap reqQMap = AbstractNetworkMessenger::packRequest(AbstractNetworkMessenger::CREATE, "A Table", "Patient", objMap);
    //qDebug() << reqQMap << endl << endl << endl;


//    QJson::Serializer serial;
//    QByteArray qbar = serial.serialize(reqQMap);
//    QJson::Parser parse;
//    QVariant outQVar = parse.parse(qbar);
//    QVariantMap outQMap = outQVar.toMap();



    //outMap = AbstractNetworkMessenger::qVariantMapToStringMap(outQMap);

    //qDebug() << outQMap << endl;
    //qDebug() << (int) AbstractNetworkMessenger::unpackRequestType(outQMap) << endl;
    //qDebug() << QString::fromStdString(AbstractNetworkMessenger::unpackRequestIdKey(outQMap)) << endl;
    //qDebug() << AbstractNetworkMessenger::stringMapToQVariantMap(AbstractNetworkMessenger::unpackRequestObjectMap(outQMap)) << endl;

//    cout << "finished" << endl;
//    cout << "extra text" << endl;
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
        if(input == "serverStart")
        {
            QCoreApplication consoleApp(argc, argv);
            testNumber = 2;
            cout << "Starting server..." << endl;
            ServerController::makeInstance("1:13:00");
            ServerNetworkInterface sni((quint16)9000);
            //CommsTests::startUpServer();
            return consoleApp.exec();
        }
        else if(input == "clientTests")
        {
            CommsTests::testClientSide();
        }
        else if(input == "sand")
        {
            string *str = new string("hey");
            testSandbox(str);

        }
        else if(input == "serverTests")
        {
            QCoreApplication consoleApp(argc, argv);
            CommsTests::testServerSide();
            return consoleApp.exec();
        }
        else if(input == "basicServer")
        {
            QCoreApplication consoleApp(argc, argv);
            ServerNetworkListener server;
            server.startListening((quint16)9000);
            return consoleApp.exec();
        }
        else if(input == "basicClient")
        {
            QTcpSocket socket;
            socket.connectToHost(QHostAddress(QString("127.0.0.1")), (quint16)9000);
            if(socket.waitForConnected())
            {
                cout << "worked" << endl;
            }
            else
            {
                cout << "didn't work" << endl;
            }
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


