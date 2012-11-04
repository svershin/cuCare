#ifndef MESSAGEGENERATOR_H
#define MESSAGEGENERATOR_H

#include "commsinclude.h"

class MessageGenerator
{
public:
    MessageGenerator();
    ~MessageGenerator();

    //Function to convert any QObject into Json
    static QString objectToJson(const QObject *modelObject);

    //Creation functions
    static bool makeCreatePhysicianMessage(Physician inputPhysician, QString **ppOutputMessage);
    static bool makeCreateAdminAssistantMessage(AdminAssistant inputAdminAssistant, QString **ppOutputMessage);
    static bool makeCreateSysAdminMessage(SysAdmin inputSysAdmin, QString **ppOutputMessage);
    static bool makeCreatePatientMessage(Patient inputPatient, int physicianId, QString **ppOutputMessage);
    static bool makeCreateConsultationMessage(Consultation inputConsultation, int physicianId, int patientId, QString **ppOutputMessage);
    static bool makeCreateReferralMessage(Referral inputReferral, int consultationId, QString **ppOutputMessage);
    static bool makeCreateMedicalTestMessage(MedicalTest inputMedicalTest, int consultationId, QString **ppOutputMessage);
    static bool makeCreateReturnConsultationMessage(ReturnConsultation inputReturnConsultation, int consultationId, int nextConsultationId, QString **ppOutputMessage);
    static bool makeCreateMedicationRenewalMessage(MedicationRenewal inputMedicationRenewal, int consultationId, QString **ppOutputMessage);

    //Modification functions
    static bool makePushUserMessage(User inputUser, QString **ppOutputMessage);
    static bool makePushPatientMessage(Patient inputPatient, int physicianId, QString **ppOutputMessage);
    static bool makePushConsultationMessage(Consultation inputPatient, int physicianId, int patientId, QString **ppOutputMessage);
    static bool makePushReferralMessage(Referral inputReferral, int consultationId, QString **ppOutputMessage);
    static bool makePushMedicalMessage(MedicalTest inputMedicalTest, int physicianId, QString **ppOutputMessage);
    static bool makePushReturnConsultationMessage(ReturnConsultation inputReturnConsultation, int physicianId, int nextConsultationId, QString **ppOutputMessage);
    static bool makePushMedicationRenewalMessage(MedicationRenewal inputMedicationRenewal, int physicianId, QString **ppOutputMessage);

    //Object retrieval functions
//    static bool makePullPhysiciansMessage(PhysicianFilter inputFilter);
//    static bool pullAdminAssistants(AdminAssistantFilter inputFilter);
//    static bool pullSysAdmins(SysAdminFilter inputFilter);
//    static bool pullPatients(PatientFilter inputFilter);
//    static bool pullConsultations(ConsultationFilter inputFilter);
//    static bool pulleReferrals(ReferralFilter inputFilter);
//    static bool pullMedicalTests(MedicalTestFilter inputFilter);
//    static bool pullReturnConsultations(ReturnConsultationFilter inputFilter);
//    static bool pullMedicationRenewals(MedicationRenewalsFilter inputFilter);


};

#endif // MESSAGEGENERATOR_H
