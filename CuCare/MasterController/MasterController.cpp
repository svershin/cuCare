// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MasterController.cpp - Definition of class MasterController
// Member functions are decalred in MasterController.h

#include "MasterController.h"

// Access Control

MasterController::MasterController()
    : pCurrentUser (NULL),
      pCurrentPatient (NULL),
      status (AC_LOGGED_OUT)
{
}

// at present only pulling with the expectation to get a physician
// since the prototype functionality requires consult and followup creation
// AdminAssistant and SysAdmin pulls TBC
AccessControlStatus MasterController::loginUser(string username, string *pErrString)
{
    // initialize request objects
    Physician inputUser(0, username, "", "", Date(0, 0, 0), ContactInfo("","","",""), Address("", "", "", "", "", ""), false);
    PhysicianFilter inputFilter;
    inputFilter->usernameSetMatch(true);
    vector<Physician*>* pReturnUser = NULL;

    int requestStatus = Request.pullPhysician(pErrString, &inputUser, inputFilter, pReturnUSer);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    if(!pReturnUser->empty() )
        return authorize(pReturnUser->front());

    else
        return AC_FAILED; // NO SUCH USER
}

AccessControlStatus MasterController::loginStatus() { return status; }

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

// Patients

bool MasterController::createPatient(Patient* pInputPatient, int physicianId, string *pErrString)
{
    int uid = 0;
    int requestStatus = Request.createPatient(pErrString, pInputPatient, physicianId, &uid);

    if(!requestStatus)
        return 0; // COMMS ERROR

    if(pCurrentPatient != NULL)
        delete pCurrentPatient;
    pCurrentPatient = pInputPatient;
    pCurrentPatient->setId(pUid);

    if(!pCurrentPatient)
        return 1;
    else
        return 0;
}

bool MasterController::modifyPatient(Patient* pInputPatient, int physicianId, string *pErrString)
{
    int requestStatus = Request.pushPatient(pErrString, pInputPatient, physicianId);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    delete pCurrentPatient;
    pCurrentPatient = pInputPatient;

    if(!pCurrentPatient)
        return 0;
    else
        return 0;
}

bool MasterController::getPatientList(vector<Patient *> *pResults, string *pErrString){}

// ASSUME A PARTIAL PATIENT IS BEING PASSED
// TODO: Pull Consultations and Follow-ups
bool MasterController::getFullPatient(Patient* newCurrentPatient, string *pErrString)
{
    delete pCurrentPatient;

    PatientFilter inputFilter;
    inputFilter->patientIdSetMatch(true);
    vector<Patient*>* pResults = NULL;

    int requestStatus = Request.pullPatient(pErrString, newCurrentPatient, inputFilter, pResults);
    if(!requestStatus)
        return 0; // COMMS ERROR

    if(!pResults->empty()) {
        pCurrentPatient = pResults->front());
        newCurrentPatient = pCurrentPatient;
        return 1;
    } else
        return 0;
}

Patient* MasterController::getCurrentPatient()
{
    return pCurrentPatient;
}

// Consultations

bool MasterController::createConsultation(Consultation* pInputConsultation, string *pErrString){}
bool MasterController::modifyConsultation(Consultation* pInputConsultation, string *pErrString){}

// Follow-ups

bool MasterController::createFollowup(Followup* pInputFollowup, string *pErrString){}
bool MasterController::modifyFollowup(int followupId, string *pErrString){}

// Physicians

bool MasterController::getPhysicianList(vector<Physician*> *pResults){}

// EOF
