#include "CommsTests.h"

using namespace std;

extern int testNumber;
extern void printStringMap(map<string, string> inMap);

CommsTests::CommsTests()
{}

void CommsTests::testServerSide()
{
    map<string, string> patmap;
    patmap["Name"] = "Oswald";
    patmap["Gender"] = "Scree";
    string idKey("AnIdKey");
    string tableName("ATableName");
    int id = -1;
    int *pId = &id;
    string errorString;

    //TEST SERVER CONTROLLER:


    testNumber = 0; // TEST NUMBER SHIFT!!

    cout << "Running server-side tests..." << endl;
    ServerController::makeInstance(string("13:00:00"));

    ServerController *control = ServerController::getInstance();

    control->runAudit();


    control->create(tableName, idKey, &patmap, pId, &errorString);
    if(!((*pId) == 654321)) {cout << "id mismatch in ServerController" << endl;}


    testNumber = 1; // TEST NUMBER SHIFT!!

    control->create(tableName, idKey, &patmap, pId, &errorString);
    if(string("test create mess-up") != errorString) {cout << "create did not error properly" << endl;}

    testNumber = 0; // TEST NUMBER SHIFT!!

    control->push(tableName, idKey, &patmap, &errorString);

    list< map<string, string> *> objectList;
    if(!control->pull(tableName, idKey, &patmap, &objectList, &errorString))
    {
        cout << "pull failure in server control test" << endl;
    }

    if(string("John") != (*(objectList.front()))["Name"]) {cout << "pull failed to populate list properly in ServerController test" << endl;}


    //TEST SERVER NETWORK REQUEST INTERPRETER:
    //Note: need to temporarily un-protect all functions from ServerNetworkMessenger to run these. Tried to look for the Q_DEBUG define, but it didn't work...



    QVariantMap createReq = AbstractNetworkMessenger::packRequest(AbstractNetworkMessenger::CREATE, tableName, idKey, patmap);
    QVariantMap pushReq = AbstractNetworkMessenger::packRequest(AbstractNetworkMessenger::PUSH, tableName, idKey, patmap);
    QVariantMap pullReq = AbstractNetworkMessenger::packRequest(AbstractNetworkMessenger::PULL, tableName, idKey, patmap);

    QVariantMap interpretResult1 = ServerNetworkRequestInterpreter::interpretAndHandleRequest(createReq);
    if(!654321 == AbstractNetworkMessenger::unpackCreateReplyContents(interpretResult1)){cout << "bad return value for create in ServerNetworkRequestInterpreter" << endl;}



    return;
}


void CommsTests::testClient1()
{
    testNumber = 0;

    map<string, string> patmap;
    patmap["Name"] = "Oswald";
    patmap["Gender"] = "Scree";
    string idKey("AnIdKey");
    string tableName("ATableName");
    int id = -1;
    int *pId = &id;
    string errorString;


    //ClientNetworkConnection cnc;
    //cnc.sendReceive(QHostAddress(QString::fromStdString(string("127.0.0.1"))), (quint16)60003, QVariant(QString("Hi")).toByteArray());

    ClientNetworkInterface cni(string("127.0.0.1"), (quint16)60003);

    cni.create(tableName, idKey, &patmap, pId, &errorString);
    /*
    //printStringMap(patmap);

    if(!((*pId) == 654321)) {cout << "id mismatch in ServerController" << endl;}

    cni.push(string("Patient"), string("aKeyName"), &patmap, &errorString);

    list< map<string, string> *> objectList;
    if(!cni.pull(tableName, string("aKeyName"), &patmap, &objectList, &errorString))
    {
        cout << "pull failure in server control test" << endl;
    }

    if(string("John") != (*(objectList.front()))["Name"]) {cout << "pull failed to populate list properly in ServerController test" << endl;}

    //printStringMap((*(objectList.front())));
    //printStringMap((*(objectList.back())));
    */
}

void CommsTests::testClient2()
{
    map<string, string> patmap;
    patmap["Name"] = "Oswald";
    patmap["Gender"] = "Scree";
    string idKey("AnIdKey");
    string tableName("ATableName");
    int id = -1;
    int *pId = &id;
    string errorString;

    ClientNetworkInterface cni(string("127.0.0.1"), (quint16)60003);

    if(! cni.create(tableName, idKey, &patmap, pId, &errorString))
    {
        cout << "Successfully failed! " << "Output string: " << errorString << endl;
    }
    else
    {
        cout << "Unsuccessful failure!" << endl;
    }


}
