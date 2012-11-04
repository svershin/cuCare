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
    Physician inputUser(0, username, "", "", Date("","",""), ContactInfo("","","",""), Address("", "", "", "", "", ""), false);
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

bool MasterController::createPatient(Patient* pInputPatient, string *pErrString)
{
    int uid = 0;
    int physicianId = 0;
    int requestStatus = Request.createPatient(pInputPatient, pErrString, physicianId, &uid);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    pInputPatient->setId(pUid);

    if(!pInputPatient)
        return 1;
    else
        return 0;
}

bool MasterController::modifyPatient(Patient* pInputPatient, string *pErrString){}
bool MasterController::getPatientList(vector<Patient *> *pResults, string *pErrString){}
bool MasterController::getFullPatient(int patientId, Patient* pResults, string *pErrString){}
Patient* MasterController::getCurrentPatient(){}

// Consultations

bool MasterController::createConsultation(Consultation* pInputConsultation, string *pErrString){}
bool MasterController::modifyConsultation(Consultation* pInputConsultation, string *pErrString){}

// Follow-ups

bool MasterController::createFollowup(Followup* pInputFollowup, string *pErrString){}
bool MasterController::modifyFollowup(Followup* pInputFollowup, string *pErrString){}

// Physicians

bool MasterController::getPhysicianList(vector<Physician*> *pResults){}

// EOF
