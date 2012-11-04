// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MasterController.h - Declaration of base class MasterController
// Member functions are defined in MasterController.cpp

#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include "../CuCareModel/ModelFiles.h"
#include <string>
#include <vector>

class MasterController {
public:

    // Access Control

    enum AccessControlStatus
    {
        AC_FAILED,
        AC_LOGGED_OUT,
        AC_LOGGED_IN_AS_PHYSICIAN,
        AC_LOGGED_IN_AS_ADMINASSISTANT,
        AC_LOGGED_IN_AS_SYSADMIN
    };

    AccessControlStatus loginUser(string username);
    AccessControlStatus loginStatus();
    AccessControlStatus logout();

    // Patients

    bool createPatient(Patient* pInputPatient);
    bool modifyPatient(Patient* pInputPatient);
    bool getPatientList(vector<Patient *> *pResults); // no filter
//    bool getPatientList(Patient* pPatientValues, PatientFilter patientFilter, vector<Patient*>* pResults); // filtered, will not populate consultations or followups
    bool getFullPatient(int patientId, Patient* pResults); // must supply valid UID

    Patient* getCurrentPatient();   // returns a pointer to the currently selected patient
                                    // NULL if no patient has yet been selected

    // Consultations

    bool createConsultation(Consultation* pInputConsultation);
    bool modifyConsultation(Consultation* pInputConsultation);

    // Follow-ups

    bool createFollowup(Followup* pInputFollowup);
    bool modifyFollowup(Followup* pInputFollowup);

    // Physicians

    bool getPhysicianList(vector<Physician*> *pResults);

private:

    // Stores the user object for access control
    // Set to NULL if not logged-in
    User* pCurrentUser;

    // Stores the data for the currently selected patient
    // Set to NULL if a patient has not yet been selected
    Patient* pCurrentPatient;
};


#endif // MASTERCONTROLLER_H

// EOF
