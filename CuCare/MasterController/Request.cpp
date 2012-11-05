// Request.cpp - Dummy for testing purposes

#include "Request.h"

// CREATE
int Request::createPhysician(string *pErrString, Physician *pInputPhysician, int *pUid)
{
    return 0;
}

int Request::createAdminAssistant(string *pErrString, AdminAssistant *pInputAdminAssistant, int *pUid)
{
    return 0;
}

int Request::createSysAdmin(string *pErrString, SysAdmin *pInputSysAdmin, int *pUid)
{
    return 0;
}

int Request::createPatient(string *pErrString, Patient *pInputPatient, int physicianId, int *pUid)
{
    return 0;
}

int Request::createConsultation(string *pErrString, Consultation *pInputConsultation, int physicianId, int patientId, int *pUid)
{
    return 0;
}

int Request::createReferral(string *pErrString, Referral *pInputReferral, int consultationId, int *pUid)
{
    return 0;
}

int Request::createMedicalTest(string *pErrString, MedicalTest *pInputMedicalTest, int consultationId, int *pUid)
{
    return 0;
}

int Request::createReturnConsultation(string *pErrString, ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId, int *pUid)
{
    return 0;
}

int Request::createMedicationRenewal(string *pErrString, MedicationRenewal *pInputMedicationRenewal, int consultationId, int *pUid)
{
    return 0;
}

// PUSH
int Request::pushUser(string *pErrString, User *pInputUser)
{
    return 0;
}

int Request::pushPatient(string *pErrString, Patient *pInputPatient, int physicianId)
{
    return 0;
}

int Request::pushConsultation(string *pErrString, Consultation *pInputPatient, int physicianId, int patientId)
{
    return 0;
}

int Request::pushReferral(string *pErrString, Referral *pInputReferral, int consultationId)
{
    return 0;
}

int Request::pushMedicalTest(string *pErrString, MedicalTest *pInputMedicalTest, int physicianId)
{
    return 0;
}

int Request::pushReturnConsultation(string *pErrString, ReturnConsultation *pInputReturnConsultation, int physicianId, int nextConsultationId)
{
    return 0;
}

int Request::pushMedicationRenewal(string *pErrString, MedicationRenewal *pInputMedicationRenewal, int physicianId)
{
    return 0;
}

// PULL
int Request::pullPhysician(string *pErrString, Physician *pPhysicianValues, PhysicianFilter inputFilter, vector<Physician*> *pOutputPhysicians)
{
    return 0;
}

int Request::pullAdminAssistant(string *pErrString, AdminAssistant *pPhysicianValues, UserFilter inputFilter, vector<AdminAssistant*> *pOutputAdminAssistants)
{
    return 0;
}

int Request::pullSysAdmin(string *pErrString, SysAdmin *pSysAdminValues, UserFilter inputFilter, vector<SysAdmin*> *pOutputSysAdmins)
{
    return 0;
}

int Request::pullPatient(string *pErrString, Patient *pPatientValues, PatientFilter inputFilter, int physicianId, vector<Patient*> *pOutputPatients)
{
    return 0;
}

int Request::pullConsultation(string *pErrString, Consultation *pConsultationValues, ConsultationFilter inputFilter, int physicianId, int patientId, vector<Consultation*> *pOutputConsultations)
{
    return 0;
}

int Request::pullReferral(string *pErrString, Referral *pReferralValues, ReferralFilter inputFilter, int consultationId, vector<Referral*> *pOutputReferral)
{
    return 0;
}

int Request::pullMedicalTest(string *pErrString, MedicalTest *pMedicalTestValues, MedicalTestFilter inputFilter, int consultationId, vector<MedicalTest*> *pOutputMedicalTests)
{
    return 0;
}

int Request::pullReturnConsultation(string *pErrString, ReturnConsultation *pReturnConsultationValues, ReturnConsultationFilter inputFilter, int consultationId, int nextConsultationId, vector<ReturnConsultation*> *pOutputReturnConsultation)
{
    return 0;
}

int Request::pullMedicationRenewal(string *pErrString, MedicationRenewal *pMedicationRenewalValues, MedicationRenewalFilter inputFilter, int consultationId, vector<MedicationRenewal*> *pOutputMedicationRenewal)
{
    return 0;
}

// EOF
