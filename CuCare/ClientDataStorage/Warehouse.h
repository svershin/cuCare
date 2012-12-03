#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "Factory.h"
#include <list>

using namespace std;

class Warehouse
{
    friend class Factory;
public:
    Warehouse(Factory *parentFactoryParam);

    ~Warehouse();

    AdminAssistant* getAdminAssistant(int index);
    Physician* getPhysician(int index);
    SysAdmin* getSysAdmin(int index);
    Consultation* getConsultation(int index);
    Patient* getPatient(int index);
    MedicalTest* getMedicalTest(int index);
    MedicationRenewal* getMedicationRenewal(int index);
    Referral* getReferral(int index);
    ReturnConsultation* getReturnConsultation(int index);

private:
    Factory *parentFactory;

    void addAdminAssistant(AdminAssistant* newObject);
    void addPhysician(Physician* newObject);
    void addSysAdmin(SysAdmin* newObject);
    void addConsultation(Consultation* newObject);
    void addPatient(Patient* newObject);
    void addMedicalTest(MedicalTest* newObject);
    void addMedicationRenewal(MedicationRenewal* newObject);
    void addReferral(Referral* newObject);
    void addReturnConsultation(ReturnConsultation* newObject);

    map<int, AdminAssistant*> AdminAssistants;
    map<int, Physician*> Physicians;
    map<int, SysAdmin*> SysAdmins;
    map<int, Consultation*> Consultations;
    map<int, Patient*> Patients;
    map<int, MedicalTest*> MedicalTests;
    map<int, MedicationRenewal*> MedicationRenewals;
    map<int, Referral*> Referrals;
    map<int, ReturnConsultation*> ReturnConsultations;
};

#endif // WAREHOUSE_H
