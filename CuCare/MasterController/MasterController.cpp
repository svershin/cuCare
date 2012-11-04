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
      pCurrentPatient (NULL)
{
}

AccessControlStatus MasterController::loginUser(string username)
{

}

AccessControlStatus MasterController::loginStatus(){}

AccessControlStatus MasterController::logout(){}

// Patients

bool MasterController::createPatient(Patient* pInputPatient){}
bool MasterController::modifyPatient(Patient* pInputPatient){}
bool MasterController::getPatientList(vector<Patient *> *pResults){}
bool MasterController::getFullPatient(int patientId, Patient* pResults){}
Patient* MasterController::getCurrentPatient(){}

// Consultations

bool MasterController::createConsultation(Consultation* pInputConsultation){}
bool MasterController::modifyConsultation(Consultation* pInputConsultation){}

// Follow-ups

bool MasterController::createFollowup(Followup* pInputFollowup){}
bool MasterController::modifyFollowup(Followup* pInputFollowup){}

// Physicians

bool MasterController::getPhysicianList(vector<Physician*> *pResults){}

// EOF
