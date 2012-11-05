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
    static QByteArray makeCreatePhysicianMessage(Physician *pInputPhysician);
    static QByteArray makeCreateAdminAssistantMessage(AdminAssistant *pInputAdminAssistant);
    static QByteArray makeCreateSysAdminMessage(SysAdmin *pInputSysAdmin);
    static QByteArray makeCreatePatientMessage(Patient *pInputPatient, int physicianId);
    static QByteArray makeCreateConsultationMessage(Consultation *pInputConsultation, int physicianId, int patientId);
    static QByteArray makeCreateReferralMessage(Referral *pInputReferral, int consultationId);
    static QByteArray makeCreateMedicalTestMessage(MedicalTest *pInputMedicalTest, int consultationId);
    static QByteArray makeCreateReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId);
    static QByteArray makeCreateMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int consultationId);

    //Modification functions
    static QByteArray makePushUserMessage(User *pInputUser);
    static QByteArray makePushPatientMessage(Patient *pInputPatient, int physicianId);
    static QByteArray makePushConsultationMessage(Consultation *pInputPatient, int physicianId, int patientId);
    static QByteArray makePushReferralMessage(Referral *pInputReferral, int consultationId);
    static QByteArray makePushMedicalMessage(MedicalTest *pInputMedicalTest, int physicianId);
    static QByteArray makePushReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int physicianId, int nextConsultationId);
    static QByteArray makePushMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int physicianId);

    //Object retrieval functions    static QString makePullPhysiciansMessage(PhysicianFilter *pInputFilter);
    static QByteArray pullAdminAssistants(UserFilter *pInputFilter);
    static QByteArray pullSysAdmins(UserFilter *pInputFilter);
    static QByteArray pullPatients(PatientFilter *pInputFilter);
    static QByteArray pullConsultations(ConsultationFilter *pInputFilter);
    static QByteArray pulleReferrals(ReferralFilter *pInputFilter);
    static QByteArray pullMedicalTests(MedicalTestFilter *pInputFilter);
    static QByteArray pullReturnConsultations(ReturnConsultationFilter *pInputFilter);
    static QByteArray pullMedicationRenewals(MedicationRenewalFilter *pInputFilter);
};

#endif // MESSAGEGENERATOR_H
