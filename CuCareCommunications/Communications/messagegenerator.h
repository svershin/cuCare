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
    static QString makeCreatePhysicianMessage(Physician inputPhysician);
    static QString makeCreateAdminAssistantMessage(AdminAssistant inputAdminAssistant);
    static QString makeCreateSysAdminMessage(SysAdmin inputSysAdmin);
    static QString makeCreatePatientMessage(Patient inputPatient, int physicianId);
    static QString makeCreateConsultationMessage(Consultation inputConsultation, int physicianId, int patientId);
    static QString makeCreateReferralMessage(Referral inputReferral, int consultationId);
    static QString makeCreateMedicalTestMessage(MedicalTest inputMedicalTest, int consultationId, QString **ppOutputMessage);
    static QString makeCreateReturnConsultationMessage(ReturnConsultation inputReturnConsultation, int consultationId, int nextConsultationId, QString **ppOutputMessage);
    static QString makeCreateMedicationRenewalMessage(MedicationRenewal inputMedicationRenewal, int consultationId, QString **ppOutputMessage);

    //Modification functions
    static QString makePushUserMessage(User inputUser, QString **ppOutputMessage);
    static QString makePushPatientMessage(Patient inputPatient, int physicianId, QString **ppOutputMessage);
    static QString makePushConsultationMessage(Consultation inputPatient, int physicianId, int patientId, QString **ppOutputMessage);
    static QString makePushReferralMessage(Referral inputReferral, int consultationId, QString **ppOutputMessage);
    static QString makePushMedicalMessage(MedicalTest inputMedicalTest, int physicianId, QString **ppOutputMessage);
    static QString makePushReturnConsultationMessage(ReturnConsultation inputReturnConsultation, int physicianId, int nextConsultationId, QString **ppOutputMessage);
    static QString makePushMedicationRenewalMessage(MedicationRenewal inputMedicationRenewal, int physicianId, QString **ppOutputMessage);

    //Object retrieval functions    static QString makePullPhysiciansMessage(PhysicianFilter inputFilter);
//    static QString pullAdminAssistants(AdminAssistantFilter inputFilter);
//    static QString pullSysAdmins(SysAdminFilter inputFilter);
//    static QString pullPatients(PatientFilter inputFilter);
//    static QString pullConsultations(ConsultationFilter inputFilter);
//    static QString pulleReferrals(ReferralFilter inputFilter);
//    static QString pullMedicalTests(MedicalTestFilter inputFilter);
//    static QString pullReturnConsultations(ReturnConsultationFilter inputFilter);
//    static QString pullMedicationRenewals(MedicationRenewalsFilter inputFilter);



};

#endif // MESSAGEGENERATOR_H
