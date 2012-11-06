#include "requesthandler.h"

RequestHandler::RequestHandler()
    :pRepo (new Repository())
{
}

QByteArray RequestHandler::handleRequest(QVariantMap reqMap)
{
    ModelObject modelObject = MessageParser::qVariantMapToModelObject(reqMap.value("modelObject").toMap());
    ModelObject filter = MessageParser::qVariantMapToModelObject(reqMap.value("filter").toMap());
    vector<AdminAssistant *> *newAdminAssistants = NULL;
    vector<SysAdmin *> *newSysAdmins = NULL;
    vector<Physician *> *newPhysicians = NULL;
    vector<Consultation *> *newConsultations = NULL;
    vector<Patient *> *newPatients = NULL;
    vector<Referral *> *newReferrals = NULL;
    vector<MedicationRenewal *> *newMedicationRenewals = NULL;
    vector<MedicalTest *> *newMedicalTests = NULL;
    vector<ReturnConsultation *> *newReturnConsultations = NULL;
    int uid = 0;
    switch (reqMap.value("requestType").toInt())
    {
    case(Messenger::CREATE_ADMIN_ASSISTANT):
        pRepo->createAdminAssistant((AdminAssistant*)&modelObject);
        break;
    case(Messenger::CREATE_CONSULTATION):
        pRepo->createConsultation((Consultation*)&modelObject, reqMap.value("physicianId").toInt(), reqMap.value("patientId").toInt(), &uid);
        break;
    case(Messenger::CREATE_MEDICAL_TEST):
        pRepo->createMedicalTest((MedicalTest*)&modelObject, reqMap.value("consultationId").toInt(), &uid);
        break;
    case(Messenger::CREATE_MEDICATION_RENEWAL):
        pRepo->createMedicationRenewal((MedicationRenewal*)&modelObject, reqMap.value("consultationId").toInt(), &uid);
        break;
    case(Messenger::CREATE_REFERRAL):
        pRepo->createReferral((Referral*)&modelObject, reqMap.value("consultationId").toInt(), &uid);
        break;
    case(Messenger::CREATE_RETURN_CONSULTATION):
        pRepo->createReturnConsultation((ReturnConsultation*)&modelObject, reqMap.value("consultationId").toInt(), reqMap.value("nextConsultationId").toInt(), &uid);
        break;
    case(Messenger::CREATE_SYS_ADMIN):
        pRepo->createSysAdmin((SysAdmin*)&modelObject);
        break;
    case(Messenger::CREATE_PHYSICIAN):
        pRepo->createPhysician((Physician*)&modelObject, &uid);
        break;
    case(Messenger::CREATE_PATIENT):
        pRepo->createPatient((Patient*)&modelObject, reqMap.value("physicianId").toInt(), &uid);
        break;

    case(Messenger::PUSH_USER):
        pRepo->pushUser((User*)&modelObject);
        break;
    case(Messenger::PUSH_CONSULTATION):
        pRepo->pushConsultation((Consultation*)&modelObject, reqMap.value("physicianID").toInt(), reqMap.value("patientId").toInt());
        break;
    case(Messenger::PUSH_MEDICAL_TEST):
        pRepo->pushMedicalTest((MedicalTest*)&modelObject, reqMap.value("consultationId").toInt());
        break;
    case(Messenger::PUSH_MEDICATION_RENEWAL):
        pRepo->pushMedicationRenewal((MedicationRenewal*)&modelObject, reqMap.value("consultationId").toInt());
        break;
    case(Messenger::PUSH_REFERRAL):
        pRepo->pushReferral((Referral*)&modelObject, reqMap.value("consultationId").toInt());
        break;
    case(Messenger::PUSH_RETURN_CONSULTATION):
        pRepo->pushReturnConsultation((ReturnConsultation*)&modelObject, reqMap.value("consultationId").toInt(), reqMap.value("nextConsultationId").toInt());
        break;
    case(Messenger::PUSH_PATIENT):
        pRepo->pushPatient((Patient*)&modelObject, reqMap.value("physicianId").toInt());
        break;

    case(Messenger::PULL_ADMIN_ASSISTANT):
        pRepo->pullAdminAssistant((AdminAssistant*)&modelObject, *((UserFilter*)&filter), newAdminAssistants);
        break;
    case(Messenger::PULL_SYS_ADMIN):
        pRepo->pullSysAdmin((SysAdmin*)&modelObject, *((UserFilter*)&filter), newSysAdmins);
        break;
    case(Messenger::PULL_PHYSICIAN):
        pRepo->pullPhysician((Physician*)&modelObject, *((PhysicianFilter*)&filter), newPhysicians);
        break;
    case(Messenger::PULL_CONSULTATION):
        pRepo->pullConsultation((Consultation*)&modelObject, *((ConsultationFilter*)&filter), reqMap.value("physicianId").toInt(), reqMap.value("patientId").toInt(), newConsultations);
        break;
    case(Messenger::PULL_PATIENT):
        pRepo->pullPatient((Patient*)&modelObject, *((PatientFilter*)&filter), reqMap.value("physicianId").toInt(), newPatients);
        break;
    case(Messenger::PULL_REFERRAL):
        pRepo->pullReferral((Referral*)&modelObject, *((ReferralFilter*)&filter), reqMap.value("consultationId").toInt(), newReferrals);
        break;
    case(Messenger::PULL_MEDICATION_RENEWAL):
        pRepo->pullMedicationRenewal((MedicationRenewal*)&modelObject, *((MedicationRenewalFilter*)&filter), reqMap.value("consultationId").toInt(), newMedicationRenewals);
        break;
    case(Messenger::PULL_MEDICAL_TEST):
        pRepo->pullMedicalTest((MedicalTest*)&modelObject, *((MedicalTestFilter*)&filter), reqMap.value("consultationId").toInt(), newMedicalTests);
        break;
    case(Messenger::PULL_RETURN_CONSULTATION):
        pRepo->pullReturnConsultation((ReturnConsultation*)&modelObject, *((ReturnConsultationFilter*)&filter), reqMap.value("consultationId").toInt(), reqMap.value("nextConsultationId").toInt(), newReturnConsultations);
        break;
    }
}

