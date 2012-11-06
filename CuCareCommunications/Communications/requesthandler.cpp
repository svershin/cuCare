#include "requesthandler.h"
#include <iostream>

RequestHandler::RequestHandler()
    :pRepo (new Repository())
{
}

QByteArray RequestHandler::interactWithDatabase(QVariantMap reqMap)
{
    vector<AdminAssistant *> *newAdminAssistants = NULL;
    vector<SysAdmin *> *newSysAdmins = NULL;
    vector<Physician *> *newPhysicians = NULL;
    vector<Consultation *> *newConsultations = NULL;
    vector<Patient *> *newPatients = NULL;
    vector<Referral *> *newReferrals = NULL;
    vector<MedicationRenewal *> *newMedicationRenewals = NULL;
    vector<MedicalTest *> *newMedicalTests = NULL;
    vector<ReturnConsultation *> *newReturnConsultations = NULL;
    vector<int> *physicianIds = NULL;
    QByteArray retValue;
    QVariantMap retMapValue;
    QVariantList retMapList;
    retMapValue.insert("outcome", 1);
    int uid = 0;
    switch (reqMap.value("request-type").toInt())
    {
    case(Messenger::CREATE_ADMIN_ASSISTANT):
        pRepo->createAdminAssistant(MessageParser::parseAdminAssistant(reqMap.value("model-object").toMap()));
        break;
    case(Messenger::CREATE_CONSULTATION):
        pRepo->createConsultation(MessageParser::parseConsultation(reqMap.value("model-object").toMap()), reqMap.value("physicianId").toInt(), reqMap.value("patientId").toInt(), &uid);
        retMapValue.insert("payload", uid);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::CREATE_MEDICAL_TEST):
        pRepo->createMedicalTest(MessageParser::parseMedicalTest(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt(), &uid);
        retMapValue.insert("payload", uid);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::CREATE_MEDICATION_RENEWAL):
        pRepo->createMedicationRenewal(MessageParser::parseMedicationRenewal(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt(), &uid);
        retMapValue.insert("payload", uid);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::CREATE_REFERRAL):
        pRepo->createReferral(MessageParser::parseReferral(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt(), &uid);
        retMapValue.insert("payload", uid);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::CREATE_RETURN_CONSULTATION):
        pRepo->createReturnConsultation(MessageParser::parseReturnConsultation(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt(), reqMap.value("nextConsultationId").toInt(), &uid);
        retMapValue.insert("payload", uid);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::CREATE_SYS_ADMIN):
        pRepo->createSysAdmin(MessageParser::parseSysAdmin(reqMap.value("model-object").toMap()));
        break;
    case(Messenger::CREATE_PHYSICIAN):
        std::cout << "calling repo\n";
        pRepo->createPhysician(MessageParser::parsePhysician(reqMap.value("model-object").toMap()), &uid);
        retMapValue.insert("payload", uid);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::CREATE_PATIENT):
        pRepo->createPatient(MessageParser::parsePatient(reqMap.value("model-object").toMap()), reqMap.value("physicianId").toInt(), &uid);
        retMapValue.insert("payload", uid);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;

    case(Messenger::PUSH_USER):
        pRepo->pushUser(MessageParser::parseAdminAssistant(reqMap.value("model-object").toMap()));
        break;
    case(Messenger::PUSH_CONSULTATION):
        pRepo->pushConsultation(MessageParser::parseConsultation(reqMap.value("model-object").toMap()), reqMap.value("physicianID").toInt(), reqMap.value("patientId").toInt());
        break;
    case(Messenger::PUSH_MEDICAL_TEST):
        pRepo->pushMedicalTest(MessageParser::parseMedicalTest(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt());
        break;
    case(Messenger::PUSH_MEDICATION_RENEWAL):
        pRepo->pushMedicationRenewal(MessageParser::parseMedicationRenewal(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt());
        break;
    case(Messenger::PUSH_REFERRAL):
        pRepo->pushReferral(MessageParser::parseReferral(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt());
        break;
    case(Messenger::PUSH_RETURN_CONSULTATION):
        pRepo->pushReturnConsultation(MessageParser::parseReturnConsultation(reqMap.value("model-object").toMap()), reqMap.value("consultationId").toInt(), reqMap.value("nextConsultationId").toInt());
        break;
    case(Messenger::PUSH_PATIENT):
        pRepo->pushPatient(MessageParser::parsePatient(reqMap.value("model-object").toMap()), reqMap.value("physicianId").toInt());
        break;

    case(Messenger::PULL_ADMIN_ASSISTANT):
        pRepo->pullAdminAssistant(MessageParser::parseAdminAssistant(reqMap.value("model-object").toMap()), MessageParser::parseUserFilter(reqMap.value("filter").toMap()), newAdminAssistants);
        for(int i = 0; i < newAdminAssistants->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newAdminAssistants->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_SYS_ADMIN):
        pRepo->pullSysAdmin(MessageParser::parseSysAdmin(reqMap.value("model-object").toMap()), MessageParser::parseUserFilter(reqMap.value("filter").toMap()), newSysAdmins);
        for(int i = 0; i < newSysAdmins->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newSysAdmins->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_PHYSICIAN):
        pRepo->pullPhysician(MessageParser::parsePhysician(reqMap.value("model-object").toMap()), MessageParser::parsePhysicianFilter(reqMap.value("filter").toMap()), newPhysicians);
        for(int i = 0; i < newPhysicians->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newPhysicians->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_CONSULTATION):
        pRepo->pullConsultation(MessageParser::parseConsultation(reqMap.value("model-object").toMap()), MessageParser::parseConsultationFilter(reqMap.value("filter").toMap()), physicianIds, reqMap.value("physicianId").toInt(), reqMap.value("patientId").toInt(), newConsultations);
        for(int i = 0; i < newConsultations->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newConsultations->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_PATIENT):
        pRepo->pullPatient(MessageParser::parsePatient(reqMap.value("model-object").toMap()), MessageParser::parsePatientFilter(reqMap.value("filter").toMap()), reqMap.value("physicianId").toInt(), newPatients);
        for(int i = 0; i < newPatients->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newPatients->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_REFERRAL):
        pRepo->pullReferral(MessageParser::parseReferral(reqMap.value("model-object").toMap()), MessageParser::parseReferralFilter(reqMap.value("filter").toMap()), reqMap.value("consultationId").toInt(), newReferrals);
        for(int i = 0; i < newReferrals->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newReferrals->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_MEDICATION_RENEWAL):
        pRepo->pullMedicationRenewal(MessageParser::parseMedicationRenewal(reqMap.value("model-object").toMap()), MessageParser::parseMedicationRenewalFilter(reqMap.value("filter").toMap()), reqMap.value("consultationId").toInt(), newMedicationRenewals);
        for(int i = 0; i < newMedicationRenewals->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newMedicationRenewals->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_MEDICAL_TEST):
        pRepo->pullMedicalTest(MessageParser::parseMedicalTest(reqMap.value("model-object").toMap()), MessageParser::parseMedicalTestFilter(reqMap.value("filter").toMap()), reqMap.value("consultationId").toInt(), newMedicalTests);
        for(int i = 0; i < newMedicalTests->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newMedicalTests->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    case(Messenger::PULL_RETURN_CONSULTATION):
        pRepo->pullReturnConsultation(MessageParser::parseReturnConsultation(reqMap.value("model-object").toMap()), MessageParser::parseReturnConsultationFilter(reqMap.value("filter").toMap()), reqMap.value("consultationId").toInt(), reqMap.value("nextConsultationId").toInt(), newReturnConsultations);
        for(int i = 0; i < newReturnConsultations->size(); i++)
            retMapList.append(MessageGenerator::qObjectToQVariantMap(newReturnConsultations->at(i)));
        retMapValue.insert("payload", retMapList);
        retValue = MessageGenerator::wrapQVariantMap(retMapValue);
        break;
    }
    QString testOut(retValue);
    cout << testOut.toStdString() << "\n";
    return retValue;
}



