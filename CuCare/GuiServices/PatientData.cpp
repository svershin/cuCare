#include "PatientData.h"

PatientData::PatientData()
    : clientData(ClientData::getInstance())
{
}

list<Patient*> PatientData::getPatientList(PatientData::FilterType filterType, int physicianId, ModelObject::FollowupStatus followupStatus)
{
    Patient patientFilter;
    list<Patient*> patientList;
    list<int> patientIds;

    list<int> fupList;
    list<int> physList;

    switch(filterType)
    {
    case (NO_FILTER):
        patientFilter.getProperties()->clear();
        patientIds = clientData.pull(&patientFilter);
        break;
    case (FILTER_BY_PHYSICIAN):
        patientIds = getPatientsByPhysician(physicianId);
        break;
    case (FILTER_BY_FOLLOWUP_STATUS):
        patientIds = clientData.pullPatientsByFollowupStatus(followupStatus);
        break;
    case (FILTER_BY_PHYSICIAN_AND_FOLLOWUP_STATUS):
        physList = getPatientsByPhysician(physicianId);
        fupList = clientData.pullPatientsByFollowupStatus(followupStatus);

        //Only add patients that show up in both lists
        for(list<int>::iterator physIt = physList.begin(); physIt != physList.end(); ++physIt)
            for(list<int>::iterator fupIt = fupList.begin(); fupIt != fupList.end(); ++fupIt)
                if((*physIt) == (*fupIt))
                    patientIds.push_back((*physIt));
        break;
    default:
        throw "Invalid filter type.";
    }

    for(list<int>::iterator it = patientIds.begin(); it != patientIds.end(); ++it)
        patientList.push_back(clientData.getPatient(*it));

    return patientList;
}

list<int> PatientData::getPatientsByPhysician(int physicianId)
{
    //Set up the filter
    Patient patientFilter;
    patientFilter.setPhysicianId(physicianId);
    list<Property*> *filters = patientFilter.getProperties();
    Property *idProp = NULL;
    for(list<Property*>::iterator it = filters->begin(); it != filters->end(); ++it)
        if((*it)->getName() == "physicianid")
            idProp = (*it);
    filters->clear();
    filters->push_back(idProp);

    //Do the pull
    return clientData.pull(&patientFilter);
}

list<int> PatientData::getPatientsByFollowupStatus(ModelObject::FollowupStatus fstatus)
{
    return clientData.pullPatientsByFollowupStatus(fstatus);
}

Patient *PatientData::getFullPatient(int patientId)
{
    Patient* patient = clientData.getPatient(patientId);
    Patient patientFilter;
    patientFilter.getProperties()->clear();
    patient->setConsultationIds(clientData.pull(&patientFilter, patientId));

    list<int>* consultList = patient->getConsultationIds();
    for(list<int>::iterator it=consultList->begin(); it!=consultList->end(); it++)
        getConsultation(*it);

    return patient;
}

int PatientData::createPatient(Patient *patient)
{
    return clientData.create(patient);
}

void PatientData::modifyPatient(Patient *patient)
{
    clientData.modify(patient);
}

Consultation *PatientData::getConsultation(int consultationId)
{
    Consultation* consultation = clientData.getConsultation(consultationId);
    Consultation consultationFilter;
    consultationFilter.getProperties()->clear();
    consultation->setFollowupIds(clientData.pull(&consultationFilter, consultationId));

    list<int>* followupList = consultation->getFollowupIds();
    for(list<int>::iterator it=followupList->begin(); it!=followupList->end(); it++)
        getFollowup(*it);

    return consultation;
}

int PatientData::createConsultation(Consultation *consult, int parentId)
{
    int newConsultId = clientData.create(consult, parentId);
    clientData.getPatient(parentId)->addConsultationId(newConsultId);
    return newConsultId;
}

void PatientData::modifyConsultation(Consultation *consult)
{
    clientData.modify(consult);
}

Followup *PatientData::getFollowup(int followupId)
{
    Followup* returnFollowup = NULL;

    returnFollowup = clientData.getMedicalTest(followupId);
    if(returnFollowup != NULL)
        return returnFollowup;

    returnFollowup = clientData.getMedicationRenewal(followupId);
    if(returnFollowup != NULL)
        return returnFollowup;

    returnFollowup = clientData.getReferral(followupId);
    if(returnFollowup != NULL)
        return returnFollowup;

    returnFollowup = clientData.getReturnConsultation(followupId);
    if(returnFollowup != NULL)
        return returnFollowup;

    throw "Followup with the given id does not exist.";
}

int PatientData::createFollowup(Followup *followup, int parentId)
{
    int newFollowupId = clientData.create(followup, parentId);
    clientData.getConsultation(parentId)->addFollowupId(newFollowupId);
    return newFollowupId;
}

void PatientData::modifyFollowup(Followup *followup)
{
    clientData.modify(followup);
}

list<Physician*> PatientData::getPhysicianList()
{
    Physician physicianFilter;
    physicianFilter.getProperties()->clear();

    list<Physician*> physicianList;
    list<int> physicianIds = clientData.pull(&physicianFilter);

    for(list<int>::iterator it = physicianIds.begin(); it != physicianIds.end(); ++it)
        physicianList.push_back(clientData.getPhysician(*it));

    return physicianList;
}
