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

    enum FollowupStatus {
        FSTAT_ERROR,
        FSTAT_PENDING,
        FSTAT_OVERDUE,
        FSTAT_RECEIVED,
        FSTAT_COMPLETED
    };

    PatientData();

    list<Patient*> getPatientList(FilterType filterType, int physicianId, FollowupStatus followupStatus); // TODO pull by Followup type AND pull by FU type AND physician

    Patient* getFullPatient(int patientId);
    int createPatient(Patient *patient);
    void modifyPatient(Patient *patient);

    Consultation* getConsultation(int consultationId);
    int createConsultation(Consultation *consult, int parentId);
    void modifyConsultation(Consultation *consult);

    Followup* getFollowup(int followupId); // TODO : use the same strategy as in AccessControl to figure out what type of Follow-up it is, and then use getX to get the object poiinter
    int createFollowup(Followup *followup, int parentId);
    void modifyFollowup(Followup *followup);

    list<Physician *> getPhysicianList();

private:
    ClientData& clientData;
};

#endif // PATIENTDATA_H
