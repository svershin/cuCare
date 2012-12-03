#include "ClientData.h"

ClientData::ClientData()
    : warehouse(factory.getWarehouse()){
}

ClientData* ClientData::instance = NULL;

ClientData& ClientData::getInstance() {
    if(instance != NULL) {
        return *instance;
    } else {
        instance = new ClientData();
        return *instance;
    }
}

// Warehouse

AdminAssistant *ClientData::getAdminAssistant(int index) {
    return warehouse->getAdminAssistant(index);
}

Physician *ClientData::getPhysician(int index) {
    return warehouse->getPhysician(index);
}

SysAdmin *ClientData::getSysAdmin(int index) {
    return warehouse->getSysAdmin(index);
}

Consultation *ClientData::getConsultation(int index) {
    return warehouse->getConsultation(index);
}

Patient *ClientData::getPatient(int index) {
    return warehouse->getPatient(index);
}

MedicalTest *ClientData::getMedicalTest(int index) {
    return warehouse->getMedicalTest(index);
}

MedicationRenewal *ClientData::getMedicationRenewal(int index) {
    return warehouse->getMedicationRenewal(index);
}

Referral *ClientData::getReferral(int index) {
    return warehouse->getReferral(index);
}

ReturnConsultation *ClientData::getReturnConsultation(int index) {
    return warehouse->getReturnConsultation(index);
}

// Factory

int ClientData::create(ModelObject *object, int parentId) {
    return factory.create(object, parentId);
}

void ClientData::modify(ModelObject *object) {
    return factory.modify(object);
}

list<int> ClientData::pull(ModelObject *filteredObject, int parentId) {
    return factory.pull(filteredObject, parentId);
}

list<int> ClientData::pullPatientsByFollowupStatus(ModelObject::FollowupStatus status)
{
    return factory.pullPatientsByFollowupStatus(status);
}
