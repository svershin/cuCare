#include <QtGui/QApplication>
#include "GUI/windowcontroller.h"
#include "GuiServices/AccessControl.h"
#include "GuiServices/PatientData.h"



#include "ClientDataStorage/Factory.h"
#include "ClientDataStorage/Warehouse.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AccessControl *ac = new AccessControl();
    PatientData *pd = new PatientData();

    WindowController *wc = new WindowController(ac, pd);

    try
    {
        //Make sure there's something to log in with
        Factory *fact = new Factory();
        Warehouse *wh = fact->getWarehouse();
        if(NULL == wh->getAdminAssistant(1))
        {
            AdminAssistant user;
            user.setUsername("AdminAssistant");

            int uid = fact->create(&user);
        }
        if(NULL == wh->getPhysician(2))
        {
            Physician user;
            user.setUsername("Physician");
            user.setFirstName("Bob");
            user.setLastName("Loblaw");
            user.setPhysicianId(1);

            int uid = fact->create(&user);
        }
        if(NULL == wh->getPhysician(3))
        {
            Physician user;
            user.setUsername("OtherPhysician");
            user.setFirstName("Whirling");
            user.setLastName("Dervish");
            user.setPhysicianId(2);

            int uid = fact->create(&user);
        }

        wc->start();
    }
    catch(string err)
    {
        cout << "FATAL EXCEPTION: " << err << endl;
    }
    catch(char const * err)
    {
        cout << "FATAL EXCEPTION: " << err << endl;
    }

    return 0;
}


