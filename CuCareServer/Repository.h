#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Database.h"
#include "../CuCareModel/ModelFiles.h"
#include <iostream>
#include <fstream>
#include <map>

class Repository
{
public:
    Repository();

    ~Repository();

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

private:
    Database* db;
    const string createScriptFilename;

    void createSchema();
    bool databaseExists();

    string itos(int integer); //I can't believe these aren't standard library functions.
    int stoi(string stringvalue);

    bool insertStatement(string table, map<string,string> values);
    bool insertStatement(string table, string idname, map<string,string> values);
    bool updateStatement(string table, string idname, string idvalue, map<string, string> values);

    bool createUser(User* pInputUser);
    bool createFollowup(Followup* pInputFollowup, int consultationId, int* uid);
    bool createResultantFollowup(ResultantFollowup* pInputResultantFollowup, int consultationId, int* uid); 

    bool pushFollowup(Followup *pInputFollowup, int consultationId);
    bool pushResultantFollowup(ResultantFollowup *pInputResultantFollowup, int consultationId);

    map<string, string> getUserValues(User* pInputUser);
    map<string, string> getFollowupValues(Followup* pInputFollowup, int consultationId);
    map<string, string> getResultantFollowupValues(ResultantFollowup* pInputResultantFollowup);

    map<string, string> getPatientValues(Patient* pInputPatient, int physicianId);
    map<string, string> getConsultationValues(Consultation* pInputConsultation, int physicianId, int patientId);
    map<string, string> getReferralValues(Referral* pInputReferral);
    map<string, string> getMedicalTestValues(MedicalTest* pInputMedicalTest);
    map<string, string> getReturnConsultationValues(int nextConsultationId);
    map<string, string> getMedicationRenewalValues(MedicationRenewal* pInputMedicationRenewal);
};

#endif // REPOSITORY_H
