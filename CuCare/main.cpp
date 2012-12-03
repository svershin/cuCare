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
        ClientData cd = ClientData::getInstance();
        if(NULL == cd.getAdminAssistant(1))
        {
            AdminAssistant user;
            user.setUsername("AdminAssistant");

            cd.create(&user);
        }
        if(NULL == cd.getPhysician(2))
        {
            Physician user;
            user.setUsername("Physician");
            user.setFirstName("Bob");
            user.setLastName("Loblaw");
            user.setPhysicianId(1);

            cd.create(&user);
        }
        if(NULL == cd.getPhysician(3))
        {
            Physician user;
            user.setUsername("OtherPhysician");
            user.setFirstName("Whirling");
            user.setLastName("Dervish");
            user.setPhysicianId(2);

            cd.create(&user);
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


