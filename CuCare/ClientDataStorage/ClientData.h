#ifndef CLIENTDATA_H
#define CLIENTDATA_H

#include <list>
using namespace std;
#include "Warehouse.h"
#include "Factory.h"
#include "../../CuCareModel/ModelObject.h"

class ClientData
{
public:
    ClientData();

    static ClientData& getInstance();

    // Warehouse

    AdminAssistant* getAdminAssistant(int index);
    Physician* getPhysician(int index);
    SysAdmin* getSysAdmin(int index);
    Consultation* getConsultation(int index);
    Patient* getPatient(int index);
    MedicalTest* getMedicalTest(int index);
    MedicationRenewal* getMedicationRenewal(int index);
    Referral* getReferral(int index);
    ReturnConsultation* getReturnConsultation(int index);

    // Factory

    int create(ModelObject *object, int parentId = -1);
    void modify(ModelObject *object);
    list<int> pull(ModelObject *filteredObject, int parentId = -1);
    list<int> pullPatientsByFollowupStatus(ModelObject::FollowupStatus status);

private:
    Factory factory;
    Warehouse* warehouse;
    static ClientData* instance;
};

#endif // CLIENTDATA_H
