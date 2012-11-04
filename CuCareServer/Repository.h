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

    bool pullAdminAssistant(AdminAssistant *pAdminAssitantValues, UserFilter userFilter, vector<AdminAssistant*>* pResults);
    bool pullPhysician(Physician *pPhysicianValues, PhysicianFilter physicianFilter, vector<Physician*>* pResults);
    bool pullSysAdmin(SysAdmin *pSysAdminValues, UserFilter userFilter, vector<SysAdmin*>* pResults);
    bool pullPatient(Patient* pPatientValues, PatientFilter patientFilter, int physicianId, vector<Patient*>* pResults);
    bool pullConsultation(Consultation* pConsultationValues, ConsultationFilter consultationFilter, int physicianId, int patientId, vector<Consultation*>* pResults);
    bool pullReferral(Referral* pReferralValues, ReferralFilter referralFilter, int consultationId, vector<Referral*>* pResults);
    bool pullMedicalTest(MedicalTest* pMedicalTestValues, MedicalTestFilter medicalTestFilter, int consultationId, vector<MedicalTest*>* pResults);
    bool pullReturnConsultation(ReturnConsultation* pReturnConsultationValues, ReturnConsultationFilter returnConsultationFilter, int consultationId, int nextConsultationId, vector<ReturnConsultation*>* pResults);
    bool pullMedicationRenewal(MedicationRenewal* pMedicationRenewalValues, MedicationRenewalFilter medicationRenewalFilter, int consultationId, vector<MedicationRenewal*>* pResults);

    string getDbErrorText();
private:
    Database* db;
    const string createScriptFilename;
    const string adminAssistantColumns;
    const string physicianColumns;
    const string sysAdminColumns;
    const string patientColumns;
    const string consultationColumns;
    const string referralColumns;
    const string medicalTestColumns;
    const string returnConsultationColumns;
    const string medicationRenewalColumns;

    void createSchema();
    bool databaseExists();

    string itos(int integer); //I can't believe these aren't standard library functions.
    int stoi(string stringValue);
    string squote(string stringValue);

    bool insertStatement(string table, map<string,string> values);
    bool insertStatement(string table, string idname, map<string,string> values);
    bool updateStatement(string table, string idname, string idvalue, map<string, string> values);
    bool selectStatement(string table, map<string, string> where, string columns, QueryResult*& pResults);

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

    map<string, string> getFollowupConditions(Followup* pFollowupValues, FollowupFilter followupFilter, int consultationId);
    map<string, string> getResultantFollowupConditions(ResultantFollowup* pResultantFollowupValues, ResultantFollowupFilter resultantFollowupFilter, int consultationId);

    map<string, string> getUserConditions(User* pUserValues, UserFilter userFilter);
    map<string, string> getPhysicianConditions(Physician* pPhysicianValues, PhysicianFilter physicianFilter);
    map<string, string> getPatientConditions(Patient* pPatientValues, PatientFilter patientFilter, int physicianId);
    map<string, string> getConsultationConditions(Consultation* pConsultationValues, ConsultationFilter consultationFilter, int physicianId, int patientId);
    map<string, string> getReferralConditions(Referral* pReferralValues, ReferralFilter referralFilter, int consultationId);
    map<string, string> getMedicalTestConditions(MedicalTest* pMedicalTestValues, MedicalTestFilter medicalTestFilter, int consultationId);
    map<string, string> getMedicationRenewalConditions(MedicationRenewal* pMedicationRenewalValues, MedicationRenewalFilter medicationRenewalFilter, int consultationId);
    map<string, string> getReturnConsultationConditions(ReturnConsultation* pReturnConsultationValues, ReturnConsultationFilter returnConsultationFilter, int nextConsultationId, int consultationId);

    void instantiateAdminAssistants(vector<AdminAssistant*>* pResults, QueryResult* queryResult);
    void instantiatePhysicians(vector<Physician*>* pResults, QueryResult* queryResult);
    void instantiateSysAdmins(vector<SysAdmin*>* pResults, QueryResult* queryResult);
    void instantiateConsultations(vector<Consultation*>* pResults, QueryResult* queryResult);
    void instantiatePatients(vector<Patient*>* pResults, QueryResult* queryResult);
    void instantiateMedicationRenewals(vector<MedicationRenewal*>* pResults, QueryResult* queryResult);
    void instantiateReturnConsultations(vector<ReturnConsultation*>* pResults, QueryResult* queryResult);
    void instantiateMedicalTests(vector<MedicalTest*>* pResults, QueryResult* queryResult);
    void instantiateReferrals(vector<Referral*>* pResults, QueryResult* queryResult);
};

#endif // REPOSITORY_H
