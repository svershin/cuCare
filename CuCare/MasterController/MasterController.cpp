// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MasterController.cpp - Definition of class MasterController
// Member functions are decalred in MasterController.h

#include "MasterController.h"

// Access Control

/*MasterController::MasterController()
    : pCurrentUser (NULL),
      pCurrentPatient (NULL)
{
}*/

MasterController::AccessControlStatus MasterController::loginUser(string username)
{
    return MasterController::AC_LOGGED_IN_AS_PHYSICIAN;
}

MasterController::AccessControlStatus MasterController::loginStatus(){return MasterController::AC_LOGGED_IN_AS_PHYSICIAN;}

MasterController::AccessControlStatus MasterController::logout(){return MasterController::AC_LOGGED_OUT;}

// Patients

bool MasterController::createPatient(Patient* pInputPatient){return true;}
bool MasterController::modifyPatient(Patient* pInputPatient){return true;}
bool MasterController::getPatientList(vector<Patient *> *pResults){return true;}
bool MasterController::getFullPatient(int patientId, Patient* pResults){return true;}
Patient* MasterController::getCurrentPatient(){return NULL;}

// Consultations

bool MasterController::createConsultation(Consultation* pInputConsultation){return true;}
bool MasterController::modifyConsultation(Consultation* pInputConsultation){return true;}

// Follow-ups

bool MasterController::createFollowup(Followup* pInputFollowup){return true;}
bool MasterController::modifyFollowup(Followup* pInputFollowup){return true;}

// Physicians

bool MasterController::getPhysicianList(vector<Physician*> *pResults){return true;}

// EOF
