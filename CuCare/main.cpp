#include <QtGui/QApplication>



#include "ClientDataStorage/Factory.h"
#include "ClientDataStorage/Warehouse.h"
#include <iostream>

using namespace std;

void testUser(Factory *fact, Warehouse *wh)
{
    AdminAssistant user;
    user.setCity("MONONONONONOKE");
    user.setCellPhone("99999999");

    cout << "Sending create." << endl;

    int uid = fact->create(&user);

    cout << "Waiting to modify, check database." << endl;

    string wait;

    cin >> wait;

    user.setId(uid);

    user.setCity("SOMETHING ELSE");

    fact->modify(&user);

    cout << "Modified." << endl;

    cin >> wait;

    AdminAssistant *pulled = wh->getAdminAssistant(uid);

    cout << "Pulled city: " << pulled->getCity() << endl;

    cout << "Pulled." << endl;

    cin >> wait;
}

void testPatient(Factory *fact, Warehouse *wh)
{
    Patient patient;
    patient.setCity("MONONONONONOKE");
    patient.setCellPhone("99999999");

    cout << "Sending create." << endl;

    int uid = fact->create(&patient);

    cout << "Waiting to modify, check database." << endl;

    string wait;

    cin >> wait;

    patient.setId(uid);

    patient.setCity("SOMETHING ELSE");

    fact->modify(&patient);

    cout << "Modified." << endl;

    cin >> wait;

    Patient *pulled = wh->getPatient(uid);

    cout << "Pulled city: " << pulled->getCity() << endl;

    cout << "Pulled." << endl;

    cin >> wait;
}

void testConsultation(Factory *fact, Warehouse *wh)
{
    Consultation consult;
    consult.setReason("MONONONONONOKE");

    cout << "Sending create." << endl;

    int uid = fact->create(&consult, 1);

    cout << "Waiting to modify, check database." << endl;

    string wait;

    cin >> wait;

    consult.setId(uid);

    consult.setReason("SOMETHING ELSE");

    fact->modify(&consult);

    cout << "Modified." << endl;

    cin >> wait;

    Consultation *pulled = wh->getConsultation(uid);

    cout << "Pulled reason: " << pulled->getReason() << endl;

    cout << "Pulled." << endl;

    cin >> wait;
}

void testAllTheThings()
{
    cout << "Starting test." << endl;
    Factory *fact = new Factory();
    Warehouse *wh = fact->getWarehouse();

    testPatient(fact, wh);
    testConsultation(fact, wh);
    testUser(fact, wh);
}

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);

    try
    {
        testAllTheThings();
    }
    catch(char const * err)
    {
        cout << err << endl;
    }
    catch(string err)
    {
        cout << err << endl;
    }

    return 0;
}


