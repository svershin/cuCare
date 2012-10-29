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
    bool createConsultation(Consultation* pInputconsultation, int physicianId, int patientId, int* uid);
    bool createReferral(Referral* pInputReferral, int consultationId, int* uid);
    bool createMedicalTest(MedicalTest* pInputMedicalTest, int consultationId, int* uid);
    bool createReturnConsultation(ReturnConsultation* pInputReturnConsultation, int consultationId, int nextconsultationId, int* uid);
    bool createMedicationRenewal(MedicationRenewal* pInputMedicationRenewal, int consultationId, int* uid);

//    bool pushPhysician(Physician* pInputPhysician);
//    bool pushAdminAssistant(AdminAssistant* pInputAdminAssistant);
//    bool pushSysAdmin(SysAdmin* pInputSysAdmin);
//    bool pushPatient(Patient* pInputPatient, int physicianId);
//    bool pushconsultation(consultation* pInputconsultation, int physicianId, int patientId);
//    bool pushReferral(Referral* pInputReferral, int consultationId);
//    bool pushMedicalTest(MedicalTest* pInputMedicalTest, int consultationId);
//    bool pushReturnConsultation(ReturnConsultation* pInputReturnConsultation, int consultationId, int nextconsultationId);
//    bool pushMedicationRenewal(MedicationRenewal* pInputMedicationRenewal, int consultationId);

private:
    Database* db;

    void createSchema();
    bool databaseExists();

    string itos(int integer); //I can't believe these aren't standard library functions.
    int stoi(string stringvalue);

    bool insertStatement(string table, map<string,string> values);
    bool insertStatement(string table, string idname, map<string,string> values);

    bool createUser(User* pInputUser);
    bool createFollowup(Followup* pInputFollowup, int consultationId, int* uid);
    bool createResultantFollowup(ResultantFollowup* pInputResultantFollowup, int consultationId, int* uid);

    const string createScriptFilename;
};

#endif // REPOSITORY_H
