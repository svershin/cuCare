#include <QtGui/QApplication>



#include "ClientDataStorage/Factory.h"
#include "ClientDataStorage/Warehouse.h"
#include <iostream>

using namespace std;

void testAllTheThings()
{
    Factory *fact = new Factory();
    Warehouse *wh = fact->getWarehouse();

    Patient patient;
    patient.setCountry("MONONONONONOKE");
    patient.setCellPhone("99999999");

    fact->create(&patient);

    cout << "Waiting to modify, check database." << endl;

    string wait;

    cin >> wait;

    patient.setCountry("SOMETHING ELSE");

    fact->modify(&patient);

    cout << "Modified." << endl;

    cin >> wait;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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


