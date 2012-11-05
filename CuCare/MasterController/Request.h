#ifndef REQUEST_H
#define REQUEST_H

#include "../CuCareModel/ModelFiles.h"

class Request {
public:
    /* ***Server Interface Functions***
       The following functions deal with sending information to, and recieving information from, server.
       They all follow the same rules for RETURN values:
        0: Success
       -1: Bad input
       -2: Network error
       -3: Server error
       If an error occurs, a message will be placed into pErrString, a string pointer which all of these functions take.
      */

    //Creation functions

    int createPhysician(string *pErrString, Physician *pInputPhysician, int *pUid);
    int createAdminAssistant(string *pErrString, AdminAssistant *pInputAdminAssistant, int *pUid);
    int createSysAdmin(string *pErrString, SysAdmin *pInputSysAdmin, int *pUid);
    int createPatient(string *pErrString, Patient *pInputPatient, int physicianId, int *pUid);
    int createConsultation(string *pErrString, Consultation *pInputConsultation, int physicianId, int patientId, int *pUid);
    int createReferral(string *pErrString, Referral *pInputReferral, int consultationId, int *pUid);
    int createMedicalTest(string *pErrString, MedicalTest *pInputMedicalTest, int consultationId, int *pUid);
    int createReturnConsultation(string *pErrString, ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId, int *pUid);
    int createMedicationRenewal(string *pErrString, MedicationRenewal *pInputMedicationRenewal, int consultationId, int *pUid);

    //Modification functions

    int pushUser(string *pErrString, User *pInputUser);
    int pushPatient(string *pErrString, Patient *pInputPatient, int physicianId);
    int pushConsultation(string *pErrString, Consultation *pInputPatient, int physicianId, int patientId);
    int pushReferral(string *pErrString, Referral *pInputReferral, int consultationId);
    int pushMedicalTest(string *pErrString, MedicalTest *pInputMedicalTest, int consultationId);
    int pushReturnConsultation(string *pErrString, ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId);
    int pushMedicationRenewal(string *pErrString, MedicationRenewal *pInputMedicationRenewal, int consultationId);

    //Object retrieval functions

    int pullPhysician(string *pErrString, Physician *pPhysicianValues, PhysicianFilter inputFilter, vector<Physician*> *pOutputPhysicians);
    int pullAdminAssistant(string *pErrString, AdminAssistant *pPhysicianValues, UserFilter inputFilter, vector<AdminAssistant*> *pOutputAdminAssistants);
    int pullSysAdmin(string *pErrString, SysAdmin *pSysAdminValues, UserFilter inputFilter, vector<SysAdmin*> *pOutputSysAdmins);
    int pullPatient(string *pErrString, Patient *pPatientValues, PatientFilter inputFilter, int physicianId, vector<Patient*> *pOutputPatients);
    int pullConsultation(string *pErrString, Consultation *pConsultationValues, ConsultationFilter inputFilter, int physicianId, int patientId, vector<Consultation*> *pOutputConsultations);
    int pullReferral(string *pErrString, Referral *pReferralValues, ReferralFilter inputFilter, int consultationId, vector<Referral*> *pOutputReferral);
    int pullMedicalTest(string *pErrString, MedicalTest *pMedicalTestValues, MedicalTestFilter inputFilter, int consultationId, vector<MedicalTest*> *pOutputMedicalTests);
    int pullReturnConsultation(string *pErrString, ReturnConsultation *pReturnConsultationValues, ReturnConsultationFilter inputFilter, int consultationId, int nextConsultationId, vector<ReturnConsultation*> *pOutputReturnConsultation);
    int pullMedicationRenewal(string *pErrString, MedicationRenewal *pMedicationRenewalValues, MedicationRenewalFilter inputFilter, int consultationId, vector<MedicationRenewal*> *pOutputMedicationRenewal);
};

#endif // REQUEST_H
