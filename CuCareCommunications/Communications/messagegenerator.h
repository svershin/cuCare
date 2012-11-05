#ifndef MESSAGEGENERATOR_H
#define MESSAGEGENERATOR_H

#include "commsinclude.h"

class MessageGenerator
{
public:
    MessageGenerator();
    ~MessageGenerator();

    //Function to convert any QObject into Json
    static QByteArray qObjectToJson(const QObject &modelObject);

    //Creation functions
    static QString makeCreatePhysicianMessage(Physician *pInputPhysician);
    static QString makeCreateAdminAssistantMessage(AdminAssistant *pInputAdminAssistant);
    static QString makeCreateSysAdminMessage(SysAdmin *pInputSysAdmin);
    static QString makeCreatePatientMessage(Patient *pInputPatient, int physicianId);
    static QString makeCreateConsultationMessage(Consultation *pInputConsultation, int physicianId, int patientId);
    static QString makeCreateReferralMessage(Referral *pInputReferral, int consultationId);
    static QString makeCreateMedicalTestMessage(MedicalTest *pInputMedicalTest, int consultationId);
    static QString makeCreateReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId);
    static QString makeCreateMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int consultationId);

    //Modification functions
    static QString makePushUserMessage(User *pInputUser);
    static QString makePushPatientMessage(Patient *pInputPatient, int physicianId);
    static QString makePushConsultationMessage(Consultation *pInputPatient, int physicianId, int patientId);
    static QString makePushReferralMessage(Referral *pInputReferral, int consultationId);
    static QString makePushMedicalMessage(MedicalTest *pInputMedicalTest, int physicianId);
    static QString makePushReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int physicianId, int nextConsultationId);
    static QString makePushMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int physicianId);

    //Object retrieval functions    static QString makePullPhysiciansMessage(PhysicianFilter *pInputFilter);
    static QString pullAdminAssistants(UserFilter *pInputFilter);
    static QString pullSysAdmins(UserFilter *pInputFilter);
    static QString pullPatients(PatientFilter *pInputFilter);
    static QString pullConsultations(ConsultationFilter *pInputFilter);
    static QString pulleReferrals(ReferralFilter *pInputFilter);
    static QString pullMedicalTests(MedicalTestFilter *pInputFilter);
    static QString pullReturnConsultations(ReturnConsultationFilter *pInputFilter);
    static QString pullMedicationRenewals(MedicationRenewalFilter *pInputFilter);
};

#endif // MESSAGEGENERATOR_H
