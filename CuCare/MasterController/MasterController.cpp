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
      status (AC_LOGGED_OUT),
      pCurrentPatient (NULL)
{
}

// Destructor
MasterController::~MasterController()
{


    delete pCurrentUser;
    delete pCurrentPatient;
}

// Access Control ---------------------------------------------------------------------------------------

MasterController::AccessControlStatus MasterController::loginUser(string username, string *pErrString)
{
    // Try to see if the user is a valid AdminAssistant
    AdminAssistant inputAdminAssistant(username, "", "", Date(0,0,0), ContactInfo("","","",""), Address("","","","",""), false);
    UserFilter inputFilterUser;
    inputFilterUser.usernameSetMatch(true);
    vector<AdminAssistant*>* pReturnAdminAssistant = NULL;

    int requestStatus = server.pullAdminAssistant(pErrString, &inputAdminAssistant, inputFilterUser, pReturnAdminAssistant);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    if(!pReturnAdminAssistant->empty() )
        return authorize(pReturnAdminAssistant->front());

    // Try to see if the user is a valid Physician
    Physician inputPhysician(0, username, "", "", Date(0,0,0), ContactInfo("","","",""), Address("", "", "", "", ""), false);
    PhysicianFilter inputFilterPhysician;
    inputFilterPhysician.usernameSetMatch(true);
    vector<Physician*>* pReturnPhysician = NULL;

    requestStatus = server.pullPhysician(pErrString, &inputPhysician, inputFilterPhysician, pReturnPhysician);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    if(!pReturnPhysician->empty() )
        return authorize(pReturnPhysician->front());

    // Try to see if the user is a valid Physician
    SysAdmin inputSysAdmin(username, "", "", Date(0,0,0), ContactInfo("","","",""), Address("", "", "", "", ""), false);
    vector<SysAdmin*>* pReturnSysAdmin = NULL;

    requestStatus = server.pullSysAdmin(pErrString, &inputSysAdmin, inputFilterUser, pReturnSysAdmin);

    if(!requestStatus)
        return AC_FAILED; // COMMS ERROR

    if(!pReturnSysAdmin->empty() )
        return authorize(pReturnSysAdmin->front());

    return AC_FAILED;
}

MasterController::AccessControlStatus MasterController::loginStatus()
{
    return status;
}

MasterController::AccessControlStatus MasterController::authorize(User* user)
{
    pCurrentUser = user;
    status = (AccessControlStatus)(pCurrentUser->getType());
    return loginStatus();
}

MasterController::AccessControlStatus MasterController::logout()
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
    int requestStatus = server.createPatient(pErrString, pInputPatient, physicianId, &uid);

    if(!requestStatus)
        return 0; // COMMS ERROR

    if(pCurrentPatient != NULL)
        delete pCurrentPatient;
    pCurrentPatient = pInputPatient;
    pCurrentPatient->setId(uid);

    return 1;
}

bool MasterController::modifyPatient(string *pErrString)
{
    int requestStatus = server.pushPatient(pErrString, pCurrentPatient, pCurrentPatient->getPhysician()->getId());

    if(!requestStatus)
        return 0; // COMMS ERROR

    return 1;
}

bool MasterController::getPatientList(vector<Patient *>* &pResults, string *pErrString)
{
    Patient inputPatient(0, "", "", "", ContactInfo("","","",""), Address("","","","",""), Date(0,0,0), Date(0,0,0), NULL, HealthCard("", Date(0,0,0)), false);
    PatientFilter inputFilter;

    int requestStatus = server.pullPatient(pErrString, &inputPatient, inputFilter, 0, pResults);

    if(!requestStatus)
        return 0; // COMMS ERROR

    return 1;
}

bool MasterController::setCurrentPatient(int patientId, string *pErrString)
{
    if(pCurrentPatient != NULL)
        delete pCurrentPatient;

    Patient inputPatient(patientId, "", "", "", ContactInfo("","","",""), Address("","","","",""), Date(0,0,0), Date(0,0,0), NULL, HealthCard("", Date(0,0,0)), false);
    PatientFilter inputFilter;
    inputFilter.idSetMatch(true);
    vector<Patient*>* pResults = NULL;

    int requestStatus = server.pullPatient(pErrString, &inputPatient, inputFilter, 0, pResults);
    if(!requestStatus)
        return 0; // COMMS ERROR

    if(!pResults->empty()) {
        pCurrentPatient = pResults->front();
    } else
        return 0;

    Consultation inputConsultation(0, "", "", "", (Consultation::ConsultationStatus)0, Date(0,0,0), Time(0,0), NULL, false);
    ConsultationFilter inputFilterConsultation;
    inputFilterConsultation.patientIdSetMatch(true);

    // *** TO DO: will need to change as physican ids will come back as a vector of ints
    requestStatus = server.pullConsultation(pErrString, &inputConsultation, inputFilterConsultation, 0, pCurrentPatient->getId(), pCurrentPatient->getConsultations());
    if(!requestStatus)
        return 0; // COMMS ERROR

    // Need to populate physicians into every consultation

    for(unsigned int i=0; i < pCurrentPatient->getConsultations()->size(); i++) {
        Referral pReferralValues(0, (Followup::FollowupStatus)0, Date(0,0,0), Date(0,0,0), Date(0,0,0), "", "", false);
        ReferralFilter inputFilterReferral;
        vector<Referral*> pOutputReferral;
        server.pullReferral(pErrString, &pReferralValues, inputFilterReferral, pCurrentPatient->getConsultations()->at(i)->getConsultID(), &pOutputReferral);
        if(!requestStatus)
            return 0; // COMMS ERROR

        MedicalTest pMedicalTestValues(0, (Followup::FollowupStatus)0, Date(0,0,0), Date(0,0,0), Date(0,0,0), "", "", false);
        MedicalTestFilter inputFilterMedicalTest;
        vector<MedicalTest*> pOutputMedicalTest;
        server.pullMedicalTest(pErrString, &pMedicalTestValues, inputFilterMedicalTest, pCurrentPatient->getConsultations()->at(i)->getConsultID(), &pOutputMedicalTest);
        if(!requestStatus)
            return 0; // COMMS ERROR

        ReturnConsultation pReturnConsultationValues(0, (Followup::FollowupStatus)0, Date(0,0,0), Date(0,0,0), Date(0,0,0), NULL, false);
        ReturnConsultationFilter inputFilterReturnConsultation;
        vector<ReturnConsultation*> pOutputReturnConsultation;
        server.pullReturnConsultation(pErrString, &pReturnConsultationValues, inputFilterReturnConsultation, pCurrentPatient->getConsultations()->at(i)->getConsultID(), 0, &pOutputReturnConsultation);
        if(!requestStatus)
            return 0; // COMMS ERROR

        MedicationRenewal pMedicationRenewalValues(0, (Followup::FollowupStatus)0, Date(0,0,0), Date(0,0,0), Date(0,0,0), "", false);
        MedicationRenewalFilter inputFilterMedicationRenewal;
        vector<MedicationRenewal*> pOutputMedicationRenewal;
        server.pullMedicationRenewal(pErrString, &pMedicationRenewalValues, inputFilterMedicationRenewal, pCurrentPatient->getConsultations()->at(i)->getConsultID(), &pOutputMedicationRenewal);
        if(!requestStatus)
            return 0; // COMMS ERROR

        for(unsigned int i=0; i < pOutputReferral.size(); i++)
            pCurrentPatient->getConsultations()->at(i)->getFollowups()->push_back(pOutputReferral.at(i));
        for(unsigned int i=0; i < pOutputMedicalTest.size(); i++)
            pCurrentPatient->getConsultations()->at(i)->getFollowups()->push_back(pOutputMedicalTest.at(i));
        for(unsigned int i=0; i < pOutputReturnConsultation.size(); i++)
            pCurrentPatient->getConsultations()->at(i)->getFollowups()->push_back(pOutputReturnConsultation.at(i));
        for(unsigned int i=0; i < pOutputMedicationRenewal.size(); i++)
            pCurrentPatient->getConsultations()->at(i)->getFollowups()->push_back(pOutputMedicationRenewal.at(i));
    }

    return 1;
}

Patient* MasterController::getCurrentPatient()
{
    return pCurrentPatient;
}

// Consultations ---------------------------------------------------------------------------------------

bool MasterController::createConsultation(Consultation* pInputConsultation, string *pErrString)
{
    int uid = 0;

    int requestStatus = server.createConsultation(pErrString, pInputConsultation, pInputConsultation->getConsultingPhys()->getId(), pCurrentPatient->getId(), &uid);
    if(!requestStatus)
        return 0; // COMMS ERROR

    pInputConsultation->setConsultID(uid);

    pCurrentPatient->getConsultations()->push_back(pInputConsultation);

    return 1;
}

bool MasterController::modifyConsultation(int consultId, string *pErrString)
{
    Consultation* pConsultation2BUpdated = NULL;

    for(unsigned int i=0; i < pCurrentPatient->getConsultations()->size(); i++) {
        if(pCurrentPatient->getConsultations()->at(i)->getConsultID() == consultId)
            pConsultation2BUpdated = pCurrentPatient->getConsultations()->at(i);
    }

    if(pConsultation2BUpdated == NULL)
        return 0;

    int requestStatus = server.pushConsultation(pErrString, pConsultation2BUpdated, pConsultation2BUpdated->getConsultingPhys()->getId(), pCurrentPatient->getId());
    if(!requestStatus)
        return 0; // COMMS ERROR

    return 1;
}

// Follow-ups ---------------------------------------------------------------------------------------

bool MasterController::createFollowup(Followup* pInputFollowup, int consultId, string *pErrString)
{
    int requestStatus = 0;
    int uid = 0;
    Consultation* pParentConsult = NULL;

    for(unsigned int i=0; i < pCurrentPatient->getConsultations()->size(); i++) {
        if(pCurrentPatient->getConsultations()->at(i)->getConsultID() == consultId)
            pParentConsult = pCurrentPatient->getConsultations()->at(i);
    }

    int followupType = pInputFollowup->getType();

    switch(followupType) {
    case 1: // MedicalTest
        requestStatus = server.createMedicalTest(pErrString, (MedicalTest*)pInputFollowup, consultId, &uid);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    case 2: // MedicationRenewal
        requestStatus = server.createMedicationRenewal(pErrString, (MedicationRenewal*)pInputFollowup, consultId, &uid);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    case 3: // Referral
        requestStatus = server.createReferral(pErrString, (Referral*)pInputFollowup, consultId, &uid);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    case 4: // ReturnConsultation
        requestStatus = server.createReturnConsultation(pErrString, (ReturnConsultation*)pInputFollowup, consultId, 0, &uid);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    default:
        return 0;
    }

    pInputFollowup->setId(uid);
    pParentConsult->getFollowups()->push_back(pInputFollowup);

    return 1;
}

bool MasterController::modifyFollowup(int followupId, int consultId, string *pErrString)
{
    int requestStatus = 0;
    Consultation* pParentConsult = NULL;
    Followup* followup2BUpdated = NULL;

    for(unsigned int i=0; i < pCurrentPatient->getConsultations()->size(); i++) {
        if(pCurrentPatient->getConsultations()->at(i)->getConsultID() == consultId)
            pParentConsult = pCurrentPatient->getConsultations()->at(i);
    }

    for(unsigned int i=0; i < pParentConsult->getFollowups()->size(); i++) {
        if(pParentConsult->getFollowups()->at(i)->getId() == followupId)
            followup2BUpdated = pParentConsult->getFollowups()->at(i);
    }

    int followupType = followup2BUpdated->getType();

    switch(followupType) {
    case 1: // MedicalTest
        requestStatus = server.pushMedicalTest(pErrString, (MedicalTest*)followup2BUpdated, consultId);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    case 2: // MedicationRenewal
        requestStatus = server.pushMedicationRenewal(pErrString, (MedicationRenewal*)followup2BUpdated, consultId);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    case 3: // Referral
        requestStatus = server.pushReferral(pErrString, (Referral*)followup2BUpdated, consultId);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    case 4: // ReturnConsultation
        requestStatus = server.pushReturnConsultation(pErrString, (ReturnConsultation*)followup2BUpdated, consultId, 0);
        if(!requestStatus)
            return 0; // COMMS ERROR
        break;
    default:
        return 0;
    }

    return 1;
}

// Physicians

bool MasterController::getPhysicianList(vector<Physician*> *pResults, string *pErrString)
{
    Physician inputPhysician(0, "", "", "", Date(0,0,0), ContactInfo("","","",""), Address("","","","",""), false);
    PhysicianFilter inputFilter;

    int requestStatus = server.pullPhysician(pErrString, &inputPhysician, inputFilter, pResults);

    if(!requestStatus)
        return 0; // COMMS ERROR

    return 1;
}

// EOF
