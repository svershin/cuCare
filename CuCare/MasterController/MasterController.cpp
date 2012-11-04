// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MasterController.cpp - Definition of class MasterController
// Member functions are decalred in MasterController.h

#include "MasterController.h"

// Constructor
MasterController::MasterController()
    : pCurrentUser (NULL),
      pCurrentPatient (NULL),
      status (AC_LOGGED_OUT)
{
}

// Destructor
MasterController::~MasterController()
{
    delete pCurrentUser;
    delete pCurrentPatient;
}

// Access Control ---------------------------------------------------------------------------------------

AccessControlStatus MasterController::loginUser(string username, string *pErrString)
{
    // Try to see if the user is a valid AdminAssistant
    AdminAssistant inputAdminAssistant(username, "", "", Date(0,0,0), ConactInfo("","","",""), Address("","","","",""), false);
    UserFilter inputFilterUser;
    inputFilterUser->usernameSetMatch(true);
    vector<AdminAssistant*>* pReturnAdminAssistant = NULL;

    requestStatus = Request.pullAdminAssistant(pErrString, &inputAdminAssistant, inputFilterUser, pReturnAdminAssistant);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    if(!pReturnAdminAssistant->empty() )
        return authorize((User)pReturnAdminAssistant->front());

    // Try to see if the user is a valid Physician
    Physician inputPhysician(0, username, "", "", Date(0,0,0), ContactInfo("","","",""), Address("", "", "", "", ""), false);
    PhysicianFilter inputFilterPhysician;
    inputFilterPhysician->usernameSetMatch(true);
    vector<Physician*>* pReturnPhysician = NULL;

    int requestStatus = Request.pullPhysician(pErrString, &inputPhysician, inputFilterPhysician, pReturnPhysician);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    if(!pReturnPhysician->empty() )
        return authorize((User)pReturnPhysician->front());

    // Try to see if the user is a valid Physician
    SysAdmin inputSysAdmin(username, "", "", Date(0,0,0), ContactInfo("","","",""), Address("", "", "", "", ""), false);
    vector<SysAdmin*>* pReturnSysAdmin = NULL;

    int requestStatus = Request.pullSysAdmin(pErrString, &inputSysAdmin, inputFilterUser, pReturnSysAdmin);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    if(!pReturnSysAdmin->empty() )
        return authorize((User)pReturnSysAdmin->front());

    return AC_FAILED;
}

AccessControlStatus MasterController::loginStatus()
{
    return status;
}

AccessControlStatus MasterController::authorize(User* user)
{
    pCurrentUser = user;
    status = pCurrentUser->getType();
    return loginStatus();
}

AccessControlStatus MasterController::logout()
{
    delete pCurrentUser;
    pCurrentUser = NULL;
    status = AC_LOGGED_OUT;
    return loginStatus();
}

// Patients ---------------------------------------------------------------------------------------

bool MasterController::createPatient(Patient* pInputPatient, int physicianId, string *pErrString)
{
    int uid = 0;
    int requestStatus = Request.createPatient(pErrString, pInputPatient, physicianId, &uid);

    if(!requestStatus)
        return 0; // COMMS ERROR

    if(pCurrentPatient != NULL)
        delete pCurrentPatient;
    pCurrentPatient = pInputPatient;
    pCurrentPatient->setId(uid);

    if(pCurrentPatient != NULL)
        return 1;
    else
        return 0;
}

bool MasterController::modifyPatient(string *pErrString)
{
    int requestStatus = Request.pushPatient(pErrString, pCurrentPatient, pCurrentPatient->getPhysician()->getId());

    if(!requestStatus)
        return 0; // COMMS ERROR

    return 1;
}

bool MasterController::getPatientList(vector<Patient *> *pResults, string *pErrString)
{
    Patient inputPatient(0, "", "", "", ConactInfo("","","",""), Address("","","","",""), Date(0,0,0), Date(0,0,0), NULL, HealthCard("", Date(0,0,0)), false);
    PatientFilter inputFilter;

    requestStatus = Request.pullPatient(pErrString, &inputPatient, inputFilter, pResults);

    if(!requestStatus)
        return 0; // COMMS ERROR

    return 1;
}

bool MasterController::setCurrentPatient(int patientId, string *pErrString)
{
    if(pCurrentPatient != NULL)
        delete pCurrentPatient;

    Patient inputPatient(patientId, "", "", "", ConactInfo("","","",""), Address("","","","",""), Date(0,0,0), Date(0,0,0), NULL, HealthCard("", Date(0,0,0)), false);
    PatientFilter inputFilter;
    inputFilter->patientIdSetMatch(true);
    vector<Patient*>* pResults = NULL;

    int requestStatus = Request.pullPatient(pErrString, inputPatient, inputFilter, pResults);
    if(!requestStatus)
        return 0; // COMMS ERROR

    if(!pResults->empty()) {
        pCurrentPatient = pResults->front());
    } else
        return 0;

    // !!! need to add code here to populate consultations and followups

}

Patient* MasterController::getCurrentPatient()
{
    return pCurrentPatient;
}

// Consultations ---------------------------------------------------------------------------------------

bool MasterController::createConsultation(Consultation* pInputConsultation, string *pErrString)
{
    int uid = 0;
    int requestStatus = Request.createConsultation(pErrString, pInputPatient, physicianId, &uid);

    if(!requestStatus)
        return 0; // COMMS ERROR

    if(pCurrentPatient != NULL)
        delete pCurrentPatient;
    pCurrentPatient = pInputPatient;
    pCurrentPatient->setId(uid);

    if(pCurrentPatient != NULL)
        return 1;
    else
        return 0;

    // !!! need to add code here to add the consultation to currentPatient
}

bool MasterController::modifyConsultation(int consultId, string *pErrString)
{
}

// Follow-ups ---------------------------------------------------------------------------------------

bool MasterController::createFollowup(Followup* pInputFollowup, string *pErrString)
{
}

bool MasterController::modifyFollowup(int followupId, string *pErrString){}

// Physicians

bool MasterController::getPhysicianList(vector<Physician*> *pResults, string *pErrString){}

// EOF
