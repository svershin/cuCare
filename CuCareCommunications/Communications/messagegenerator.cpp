#include "messagegenerator.h"
#include <iostream>
#include "messenger.h"

MessageGenerator::MessageGenerator()
{}

QByteArray MessageGenerator::MessageGenerator::qObjectToJson(const QObject &modelObject)
{
    QJson::Serializer cerealizer;
    QBuffer buffer;
    bool ok = true;

    //Turn the passed object into a QVariantMap, use the serializer to serialize it, and return the JSON in the form of a QByteArray
    const QVariantMap variantMap = QJson::QObjectHelper::qobject2qvariant(&modelObject);

    cerealizer.serialize(variantMap, &buffer, &ok);
    if(!ok)
    {
        cout << "damn: " << ok << endl;
        throw("serialize failed");
    }

    return buffer.data();
}

// A function to simplify the serialization process
QByteArray MessageGenerator::wrapQVariantMap(QVariantMap reqMessage)
{
    QJson::Serializer cerealizer;
    QBuffer buffer;
    bool ok = true;

    cerealizer.serialize(reqMessage, &buffer, &ok);
    if(!ok)
    {
        cout << "damn: " << ok << endl;
        throw("serialize failed");
    }

    //NOTE: for some reason, the serializer likes to stick 4 out-of-place characters at the start of the json byte array.
    //It may be that this is for some reason, but it makes the parser barf, and I can't see why we need them, so I truncate them here.
    return buffer.data().right(buffer.data().size() - JSON_LEADING_STRIP);

}


QVariantMap MessageGenerator::qObjectToQVariantMap(ModelObject *obj)
{
    return QJson::QObjectHelper::qobject2qvariant(obj);
}


//Creation functions
//
QByteArray MessageGenerator::createPhysicianMessage(Physician *pInputPhysician)
{
    QVariantMap requestMessage;
    requestMessage.insert("request-type", Messenger::CREATE_PHYSICIAN);
    requestMessage.insert("model-object", QJson::QObjectHelper::qobject2qvariant(pInputPhysician));
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::createAdminAssistantMessage(AdminAssistant *pInputAdminAssistant)
{
    QVariantMap requestMessage;
    requestMessage.insert("request-type", Messenger::CREATE_ADMIN_ASSISTANT);
    requestMessage.insert("model-object", QJson::QObjectHelper::qobject2qvariant(pInputAdminAssistant));
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::createSysAdminMessage(SysAdmin *pInputSysAdmin)
{
    QVariantMap requestMessage;
    requestMessage.insert("request-type", Messenger::CREATE_SYS_ADMIN);
    requestMessage.insert("model-object", QJson::QObjectHelper::qobject2qvariant(pInputSysAdmin));
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::createPatientMessage(Patient *pInputPatient, int physicianId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::CREATE_PATIENT);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputPatient));
    requestMessage.insert("physicianId", physicianId);
    return wrapQVariantMap(requestMessage);
}


QByteArray MessageGenerator::createConsultationMessage(Consultation *pInputConsultation, int physicianId, int patientId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::CREATE_CONSULTATION);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputConsultation));
    requestMessage.insert("physicianId", physicianId);
    requestMessage.insert("patientId", patientId);
    return wrapQVariantMap(requestMessage);
}


QByteArray MessageGenerator::createReferralMessage(Referral *pInputReferral, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::CREATE_REFERRAL);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputReferral));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}


QByteArray MessageGenerator::createMedicalTestMessage(MedicalTest *pInputMedicalTest, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::CREATE_MEDICAL_TEST);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputMedicalTest));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}


QByteArray MessageGenerator::createReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::CREATE_RETURN_CONSULTATION);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputReturnConsultation));
    requestMessage.insert("consultationId", consultationId);
    requestMessage.insert("nextConsultationId", nextConsultationId);
    return wrapQVariantMap(requestMessage);
}


QByteArray MessageGenerator::createMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::CREATE_MEDICATION_RENEWAL);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputMedicationRenewal));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}



//Modification functions
//
QByteArray MessageGenerator::pushUserMessage(User *pInputUser)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PUSH_USER);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputUser));
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pushPatientMessage(Patient *pInputPatient, int physicianId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PUSH_PATIENT);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputPatient));
    requestMessage.insert("physicianId", physicianId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pushConsultationMessage(Consultation *pInputPatient, int physicianId, int patientId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PUSH_CONSULTATION);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputPatient));
    requestMessage.insert("physicianId", physicianId);
    requestMessage.insert("patientId", patientId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pushReferralMessage(Referral *pInputReferral, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PUSH_REFERRAL);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputReferral));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pushMedicalTestMessage(MedicalTest *pInputMedicalTest, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PUSH_MEDICAL_TEST);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputMedicalTest));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pushReturnConsultationMessage(ReturnConsultation *pInputReturnConsultation, int consultationId, int nextConsultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PUSH_RETURN_CONSULTATION);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputReturnConsultation));
    requestMessage.insert("consultationId", consultationId);
    requestMessage.insert("nextConsultationId", nextConsultationId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pushMedicationRenewalMessage(MedicationRenewal *pInputMedicationRenewal, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PUSH_MEDICATION_RENEWAL);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pInputMedicationRenewal));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}


//Object retrieval functions
//
QByteArray MessageGenerator::pullPhysicianMessage(Physician *pPhysicianValues, PhysicianFilter inputFilter)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_PHYSICIAN);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pPhysicianValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullAdminAssistantMessage(AdminAssistant *pPhysicianValues, UserFilter inputFilter)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_ADMIN_ASSISTANT);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pPhysicianValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullSysAdminMessage(SysAdmin *pSysAdminValues, UserFilter inputFilter)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_SYS_ADMIN);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pSysAdminValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullPatientMessage(Patient *pPatientValues, PatientFilter inputFilter, int physicianId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_PATIENT);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pPatientValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    requestMessage.insert("physicianId", physicianId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullConsultationMessage(Consultation *pConsultationValues, ConsultationFilter inputFilter, int physicianId, int patientId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_CONSULTATION);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pConsultationValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    requestMessage.insert("physicianId", physicianId);
    requestMessage.insert("patientId", patientId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullReferralMessage(Referral *pReferralValues, ReferralFilter inputFilter, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_REFERRAL);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pReferralValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullMedicalTestMessage(MedicalTest *pMedicalTestValues, MedicalTestFilter inputFilter, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_MEDICAL_TEST);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pMedicalTestValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullReturnConsultationMessage(ReturnConsultation *pReturnConsultationValues, ReturnConsultationFilter inputFilter, int consultationId, int nextConsultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_RETURN_CONSULTATION);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pReturnConsultationValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    requestMessage.insert("consultationId", consultationId);
    requestMessage.insert("nextConsultationId", nextConsultationId);
    return wrapQVariantMap(requestMessage);
}

QByteArray MessageGenerator::pullMedicationRenewalMessage(MedicationRenewal *pMedicationRenewalValues, MedicationRenewalFilter inputFilter, int consultationId)
{
    QVariantMap requestMessage;
    requestMessage.insert("requestType", Messenger::PULL_MEDICATION_RENEWAL);
    requestMessage.insert("modelObject", QJson::QObjectHelper::qobject2qvariant(pMedicationRenewalValues));
    requestMessage.insert("filter", QJson::QObjectHelper::qobject2qvariant(&inputFilter));
    requestMessage.insert("consultationId", consultationId);
    return wrapQVariantMap(requestMessage);
}

