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

    // Consultations

    bool createConsultation(Consultation* pInputConsultation);
    bool modifyConsultation(Consultation* pInputConsultation);

    // Follow-ups

    bool createFollowup(Followup* pInputFollowup);
    bool modifyFollowup(Followup* pInputFollowup);

    // Physicians

    bool getPhysicianList(vector<Physician*> *pResults);

private:

    // Communications method declarations
    bool createPhysician(Physician* pInputPhysician, int* uid);
    bool createAdminAssistant(AdminAssistant* pInputAdminAssistant);
    bool createSysAdmin(SysAdmin* pInputSysAdmin);
    bool createPatient(Patient* pInputPatient, int physicianId, int* uid);
    bool createConsultation(Consultation* pInputConsultation, int physicianId, int patientId, int* uid);
    bool createReferral(Referral* pInputReferral, int consultationId, int* uid);
    bool createMedicalTest(MedicalTest* pInputMedicalTest, int consultationId, int* uid);
    bool createReturnConsultation(ReturnConsultation* pInputReturnConsultation, int consultationId, int nextconsultationId, int* uid);
    bool createMedicationRenewal(MedicationRenewal* pInputMedicationRenewal, int consultationId, int* uid);

    bool pushUser(User *pInputUser);
    bool pushPatient(Patient* pInputPatient, int physicianId);
    bool pushConsultation(Consultation* pInputConsultation, int physicianId, int patientId);
    bool pushReferral(Referral* pInputReferral, int consultationId);
    bool pushMedicalTest(MedicalTest* pInputMedicalTest, int consultationId);
    bool pushReturnConsultation(ReturnConsultation* pInputReturnConsultation, int consultationId, int nextConsultationId);
    bool pushMedicationRenewal(MedicationRenewal* pInputMedicationRenewal, int consultationId);

    bool pullAdminAssistant(AdminAssistant *pAdminAssitantValues, UserFilter userFilter, vector<AdminAssistant*>* pResults);
    bool pullPhysician(Physician *pPhysicianValues, PhysicianFilter physicianFilter, vector<Physician*>* pResults);
    bool pullSysAdmin(SysAdmin *pSysAdminValues, UserFilter userFilter, vector<SysAdmin*>* pResults);
    bool pullPatient(Patient* pPatientValues, PatientFilter patientFilter, int physicianId, vector<Patient*>* pResults);
    bool pullConsultation(Consultation* pConsultationValues, ConsultationFilter consultationFilter, int physicianId, int patientId, vector<Consultation*>* pResults);
    bool pullReferral(Referral* pReferralValues, ReferralFilter referralFilter, int consultationId, vector<Referral*>* pResults);
    bool pullMedicalTest(MedicalTest* pMedicalTestValues, MedicalTestFilter medicalTestFilter, int consultationId, vector<MedicalTest*>* pResults);
    bool pullReturnConsultation(ReturnConsultation* pReturnConsultationValues, ReturnConsultationFilter returnConsultationFilter, int consultationId, int nextConsultationId, vector<ReturnConsultation*>* pResults);
    bool pullMedicationRenewal(MedicationRenewal* pMedicationRenewalValues, MedicationRenewalFilter medicationRenewalFilter, int consultationId, vector<MedicationRenewal*>* pResults);
};


#endif // MASTERCONTROLLER_H

// EOF
