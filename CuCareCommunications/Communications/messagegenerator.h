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

    static QByteArray wrapQVariantMap(QVariantMap reqMessage);
    static QVariantMap qObjectToQVariantMap(ModelObject *);

    //Creation functions
    static QByteArray createPhysicianMessage(Physician *pInputPhysician);
    static QByteArray createAdminAssistantMessage(AdminAssistant *pInputAdminAssistant);
    static QByteArray createSysAdminMessage(SysAdmin *pInputSysAdmin);
    static QByteArray createPatientMessage(Patient *pInputPatient, int physicianId);
    static QByteArray createConsultationMessage(Consultation *pInputConsultation, int physicianId, int patientId);
    static QByteArray createReferralMessage(Referral *pInputReferral, int consultationId);
    static QByteArray createMedicalTestMessage(MedicalTest *pInputMedicalTest, int consultationId);
    static QByteArray createReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId);
    static QByteArray createMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int consultationId);

    //Modification functions
    static QByteArray pushUserMessage(User *pInputUser);
    static QByteArray pushPatientMessage(Patient *pInputPatient, int physicianId);
    static QByteArray pushConsultationMessage(Consultation *pInputPatient, int physicianId, int patientId);
    static QByteArray pushReferralMessage(Referral *pInputReferral, int consultationId);
    static QByteArray pushMedicalTestMessage(MedicalTest *pInputMedicalTest, int consultationId);
    static QByteArray pushReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId);
    static QByteArray pushMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int consultationId);

    //Object retrieval functions
    static QByteArray pullPhysicianMessage(Physician *pPhysicianValues, PhysicianFilter inputFilter);
    static QByteArray pullAdminAssistantMessage(AdminAssistant *pPhysicianValues, UserFilter inputFilter);
    static QByteArray pullSysAdminMessage(SysAdmin *pSysAdminValues, UserFilter inputFilter);
    static QByteArray pullPatientMessage(Patient *pPatientValues, PatientFilter inputFilter, int physicianId);
    static QByteArray pullConsultationMessage(Consultation *pConsultationValues, ConsultationFilter inputFilter, int physicianId, int patientId);
    static QByteArray pullReferralMessage(Referral *pReferralValues, ReferralFilter inputFilter, int consultationId);
    static QByteArray pullMedicalTestMessage(MedicalTest *pMedicalTestValues, MedicalTestFilter inputFilter, int consultationId);
    static QByteArray pullReturnConsultationMessage(ReturnConsultation *pReturnConsultationValues, ReturnConsultationFilter inputFilter, int consultationId, int nextConsultationId);
    static QByteArray pullMedicationRenewalMessage(MedicationRenewal *pMedicationRenewalValues, MedicationRenewalFilter inputFilter, int consultationId);


    //Reply messages
    //

    static QByteArray errorReplyMessage(QString err);
    static QByteArray createReplyMessage();
    static QByteArray pushReplyMessage();
    static QByteArray pullReplyMessage(vector<ModelObject*>);
};





#endif // MESSAGEGENERATOR_H
