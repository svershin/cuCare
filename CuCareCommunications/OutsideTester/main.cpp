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



void testSandbox()
{
    QVariantMap inMap, outMap;
    inMap.insert("First Thing", "Second Thing");

    QJson::Serializer ser;
    QJson::Parser par;

    QByteArray jsonData = ser.serialize(inMap);

    outMap = par.parse(jsonData).toMap();

    qDebug() << outMap;
}



int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        string input = string(argv[1]);

        // SIMPLE SERVER TESTS
        if(input == "serverTest")
        {
            QCoreApplication consoleApp(argc, argv);
            CommsTests::testServerSide();
            return consoleApp.exec();
        }

        // START RUNNING A SERVER ON PORT
        else if(input == "serverStart1")
        {
            try
            {
            QCoreApplication consoleApp(argc, argv);
            testNumber = 2;
            cout << "Starting server..." << endl;

            ServerController::makeInstance("1:13:00");
            ServerNetworkInterface sni((quint16)60003);


            //CommsTests::startUpServer();
            return consoleApp.exec();
            }
            catch(string err)
            {
                cout << "Error: " << err << endl;
                return -1;
            }
        }

        else if(input == "serverStart2")
        {
            try
            {
            QCoreApplication consoleApp(argc, argv);
            testNumber = 1;
            cout << "Starting server..." << endl;

            ServerController::makeInstance("1:13:00");
            ServerNetworkInterface sni((quint16)60003);


            //CommsTests::startUpServer();
            return consoleApp.exec();
            }
            catch(string err)
            {
                cout << "Error: " << err << endl;
                return -1;
            }
        }

        else if(input == "clientTest1")
        {
            CommsTests::testClient1();
        }

        else  if(input == "clientTest2")
        {
            CommsTests::testClient2();
        }

        else if(input == "sand")
        {
            testSandbox();
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


