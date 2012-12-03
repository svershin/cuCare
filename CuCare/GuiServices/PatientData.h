#ifndef PATIENTDATA_H
#define PATIENTDATA_H

#include <list>
#include "../ClientDataStorage/ClientData.h"
#include "../../CuCareModel/ModelObject.h"

class PatientData
{
public:

    enum FilterType {
        NO_FILTER,
        FILTER_BY_PHYSICIAN,
        FILTER_BY_FOLLOWUP_STATUS,
        FILTER_BY_PHYSICIAN_AND_FOLLOWUP_STATUS
    };

    PatientData();

    list<Patient*> getPatientList(FilterType filterType, int physicianId, ModelObject::FollowupStatus followupStatus);

    Patient* getFullPatient(int patientId);
    int createPatient(Patient *patient);
    void modifyPatient(Patient *patient);

    Consultation* getConsultation(int consultationId);
    int createConsultation(Consultation *consult, int parentId);
    void modifyConsultation(Consultation *consult);

    Followup* getFollowup(int followupId);
    int createFollowup(Followup *followup, int parentId);
    void modifyFollowup(Followup *followup);

    list<Physician *> getPhysicianList();

private:
    ClientData& clientData;

    list<int> getPatientsByPhysician(int physicianId);
    list<int> getPatientsByFollowupStatus(ModelObject::FollowupStatus fstatus);
};

#endif // PATIENTDATA_H
