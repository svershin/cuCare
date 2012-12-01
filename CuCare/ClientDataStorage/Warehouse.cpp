#include "Warehouse.h"
#include "../../CuCareModel/Property.h"

Warehouse::Warehouse(Factory *parentFactoryParam)
    : parentFactory (parentFactoryParam)
{
}

Warehouse::~Warehouse()
{
    for(map<int, AdminAssistant*>::iterator it = AdminAssistants.begin(); it != AdminAssistants.end(); ++it)
        delete it->second;
    AdminAssistants.clear();

    for(map<int, SysAdmin*>::iterator it = SysAdmins.begin(); it != SysAdmins.end(); ++it)
        delete it->second;
    SysAdmins.clear();

    for(map<int, Physician*>::iterator it = Physicians.begin(); it != Physicians.end(); ++it)
        delete it->second;
    Physicians.clear();

    for(map<int, Consultation*>::iterator it = Consultations.begin(); it != Consultations.end(); ++it)
        delete it->second;
    Consultations.clear();

    for(map<int, Patient*>::iterator it = Patients.begin(); it != Patients.end(); ++it)
        delete it->second;
    Patients.clear();

    for(map<int, Referral*>::iterator it = Referrals.begin(); it != Referrals.end(); ++it)
        delete it->second;
    Referrals.clear();

    for(map<int, ReturnConsultation*>::iterator it = ReturnConsultations.begin(); it != ReturnConsultations.end(); ++it)
        delete it->second;
    ReturnConsultations.clear();

    for(map<int, MedicationRenewal*>::iterator it = MedicationRenewals.begin(); it != MedicationRenewals.end(); ++it)
        delete it->second;
    MedicationRenewals.clear();

    for(map<int, MedicalTest*>::iterator it = MedicalTests.begin(); it != MedicalTests.end(); ++it)
        delete it->second;
    MedicalTests.clear();
}

AdminAssistant* Warehouse::getAdminAssistant(int index)
{
    if(0 == AdminAssistants.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        AdminAssistant filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return AdminAssistants[index];
}

SysAdmin* Warehouse::getSysAdmin(int index)
{
    if(0 == SysAdmins.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        SysAdmin filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return SysAdmins[index];
}

Physician* Warehouse::getPhysician(int index)
{
    if(0 == Physicians.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        Physician filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return Physicians[index];
}

Consultation* Warehouse::getConsultation(int index)
{
    if(0 == Consultations.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        Consultation filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return Consultations[index];
}

Patient* Warehouse::getPatient(int index)
{
    if(0 == Patients.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        Patient filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return Patients[index];
}

Referral* Warehouse::getReferral(int index)
{
    if(0 == Referrals.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        Referral filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return Referrals[index];
}

ReturnConsultation* Warehouse::getReturnConsultation(int index)
{
    if(0 == ReturnConsultations.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        ReturnConsultation filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return ReturnConsultations[index];
}

MedicationRenewal* Warehouse::getMedicationRenewal(int index)
{
    if(0 == MedicationRenewals.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        MedicationRenewal filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return MedicationRenewals[index];
}

MedicalTest* Warehouse::getMedicalTest(int index)
{
    if(0 == MedicalTests.count(index))
    {   //If the index is not in the map, pull it from the database

        //Here we are setting up a filter with only the id property in it.
        MedicalTest filterObject;
        filterObject.setId(index);
        list<Property*> *filters = filterObject.getProperties();
        Property *idProp = NULL;
        for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
            if(User::ID_NAME == (*it)->getName())
                idProp = (*it);
        filters->clear();
        filters->push_back(idProp);

        parentFactory->pull(&filterObject);
    }
    return MedicalTests[index];
}

void Warehouse::addSysAdmin(SysAdmin *newObject)
{
    if(1 == SysAdmins.count(newObject->getId()))
    {
        SysAdmin *obsolete = SysAdmins[newObject->getId()];
        SysAdmins[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        SysAdmins[newObject->getId()] = newObject;
}

void Warehouse::addPhysician(Physician *newObject)
{
    if(1 == Physicians.count(newObject->getId()))
    {
        Physician *obsolete = Physicians[newObject->getId()];
        Physicians[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        Physicians[newObject->getId()] = newObject;
}

void Warehouse::addConsultation(Consultation *newObject)
{
    if(1 == Consultations.count(newObject->getId()))
    {
        Consultation *obsolete = Consultations[newObject->getId()];
        Consultations[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        Consultations[newObject->getId()] = newObject;
}

void Warehouse::addPatient(Patient *newObject)
{
    if(1 == Patients.count(newObject->getId()))
    {
        Patient *obsolete = Patients[newObject->getId()];
        Patients[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        Patients[newObject->getId()] = newObject;
}

void Warehouse::addReferral(Referral *newObject)
{
    if(1 == Referrals.count(newObject->getId()))
    {
        Referral *obsolete = Referrals[newObject->getId()];
        Referrals[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        Referrals[newObject->getId()] = newObject;
}

void Warehouse::addReturnConsultation(ReturnConsultation *newObject)
{
    if(1 == ReturnConsultations.count(newObject->getId()))
    {
        ReturnConsultation *obsolete = ReturnConsultations[newObject->getId()];
        ReturnConsultations[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        ReturnConsultations[newObject->getId()] = newObject;
}

void Warehouse::addMedicationRenewal(MedicationRenewal *newObject)
{
    if(1 == MedicationRenewals.count(newObject->getId()))
    {
        MedicationRenewal *obsolete = MedicationRenewals[newObject->getId()];
        MedicationRenewals[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        MedicationRenewals[newObject->getId()] = newObject;
}

void Warehouse::addMedicalTest(MedicationRenewal *newObject)
{
    if(1 == MedicationRenewals.count(newObject->getId()))
    {
        MedicationRenewal *obsolete = MedicationRenewals[newObject->getId()];
        MedicationRenewals[newObject->getId()] = newObject;
        delete obsolete;
    }
    else
        MedicationRenewals[newObject->getId()] = newObject;
}

