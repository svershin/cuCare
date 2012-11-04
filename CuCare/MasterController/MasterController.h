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
#include "../CuCareCommunications/Communications/request.h"
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

    AccessControlStatus loginUser(string username, string *pErrString);
    AccessControlStatus loginStatus(); // see AccessControlStatus above for return codes
    AccessControlStatus logout();

    /* Return types for methods below:
       0 - FAIL
       1 - SUCCESS
    */

    // PATIENT MANAGEMENT

    /* createPatient() - Creates a new patient in storage, and sets pCurrentPatient
       pInputPatient - A ptr to a Patient object with the new data (DO NOT DELETE, this will get assigned to currentPatient)
       physicianId - The UID of the Patient's Physician (HINT: will need to call getPhysicianList() first)
       pErrString - A ptr to a string that will be populated with the error message (if any)
    */
    bool createPatient(Patient* pInputPatient, int physicianId, string *pErrString);

    /* modifyPatient() - Pushes changes to pCurrentPatient to storage
       pErrString - A ptr to a string that will be populated with the error message (if any)
    */

    bool modifyPatient(string *pErrString);

    /* getPatientList() - Fetches a list of "shallow" Patient objects from storage
       pResults - Ptr to a vector of Patient ptrs, will get populated with data from storage
       pErrString - A ptr to a string that will be populated with the error message (if any)
    */
    bool getPatientList(vector<Patient *> *pResults, string *pErrString); // no filter

    /* NOTES: This is is not required for the prototype, will allow filtered pulling of patients
       bool getPatientList(Patient* pPatientValues, PatientFilter patientFilter, vector<Patient*>* pResults, string *pErrString);
    */

    /* setCurrentPatient() - Fetches a full patient record (including consultations and followups) from storage
       patientId - A valid UID for a patient record (HINT: will need to call getPatientList() first)
       pErrString - A ptr to a string that will be populated with the error message (if any)
    */
    bool getFullPatient(int patientId, string *pErrString);

    /* getCurrentPatient() - Returns a pointer to the currently selected patient
       Note: Returns a NULL ptr if no patient has yet been selected (using setCurrentPatient)
    */
    Patient* getCurrentPatient();

    // CONSULTATIONS

    bool createConsultation(Consultation* pInputConsultation, string *pErrString);
    bool modifyConsultation(Consultation* pInputConsultation, string *pErrString);

    // FOLLOWUPS

    bool createFollowup(Followup* pInputFollowup, string *pErrString);
    bool modifyFollowup(Followup* pInputFollowup, string *pErrString);

    // PHYSICIANS

    /* getPhysicianList() - Fetches a list of "shallow" Physician objects from storage
       pResults - Ptr to a vector of Physician ptrs; will get populated with data from storage
    */

    bool getPhysicianList(vector<Physician*> *pResults, string *pErrString);

private:

    AccessControlStatus authorize(User* user);

    // Stores the user object for access control
    // Set to NULL if not logged-in
    User* pCurrentUser;

    //
    AccessControlStatus status;

    // Stores the data for the currently selected patient
    // Set to NULL if a patient has not yet been selected
    Patient* pCurrentPatient;
};


#endif // MASTERCONTROLLER_H

// EOF
