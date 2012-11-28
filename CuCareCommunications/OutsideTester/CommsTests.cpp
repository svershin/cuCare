#include "CommsTests.h"

using namespace std;

extern int testNumber;

CommsTests::CommsTests()
{}

void CommsTests::testServerSide()
{
    cout << "Beginning server-side tests..." << endl;
    ServerController::makeInstance(string("13:00:00"));

    ServerController *control = ServerController::getInstance();
    control->runAudit();


    map<string, string> patmap;
    int id;
    int *pId = &id;
    string errorString;

    control->create(string("Patient"), &patmap, pId, &errorString);
    if(!((*pId) == 654321)) {cout << "id mismatch in ServerController" << endl;}
    cout << *pId << endl;

    testNumber = 1; // TEST NUMBER SHIFT!!

    control->create(string("Patient"), &patmap, pId, &errorString);
    if(string("test create mess-up") != errorString) {cout << "create did not error properly" << endl;}

    testNumber = 0; // TEST NUMBER SHIFT!!

    control->push(string("Patient"), &patmap, &errorString);

    list< map<string, string> *> objectList;
    if(!control->pull(string("Patient"), &patmap, &objectList, &errorString))
    {
        cout << "pull failure in server control test" << endl;
    }

    if(string("John") != (*(objectList.front()))["Name"]) {cout << "pull failed to populate list properly in ServerController test" << endl;}
}


