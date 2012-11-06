#include "messageparser.h"
#include "commsinclude.h"
#include <iostream>

MessageParser::MessageParser()
{
}

ModelObject MessageParser::qVariantMapToModelObject(QVariantMap qvm)
{
    ModelObject mod;
    QJson::QObjectHelper::qvariant2qobject(qvm, &mod);
    return mod;
}


QVariantMap MessageParser::qByteArrayToqvMap(QByteArray qba)
{
    QJson::Parser parser;
    bool ok = true;
    QVariantMap vReturn = parser.parse(qba.right(qba.size()), &ok).toMap();
    if(ok){return vReturn;}
    else{throw("failed to parse json");}
}

AdminAssistant* MessageParser::parseAdminAssistant(QVariantMap qvmap)
{
    cout << "Got to parseAdminAssistant\n";
    cout << "AA fname: " << qvmap.value("firstName").toString().toStdString() << "\n";
    return new AdminAssistant( qvmap.value("username").toString().toStdString(),
                               qvmap.value("firstName").toString().toStdString(),
                               qvmap.value("lastName").toString().toStdString(),
                               Date(qvmap.value("dateOfBirth").toMap().value("day").toInt(),
                                    qvmap.value("dateOfBirth").toMap().value("month").toInt(),
                                    qvmap.value("dateOfBirth").toMap().value("year").toInt()),
                               ContactInfo(qvmap.value("contact").toMap().value("workPhone").toString().toStdString(),
                                           qvmap.value("contact").toMap().value("cellPhone").toString().toStdString(),
                                           qvmap.value("contact").toMap().value("email").toString().toStdString(),
                                           qvmap.value("contact").toMap().value("workEmail").toString().toStdString()),
                               Address(qvmap.value("address").toMap().value("country").toString().toStdString(),
                                       qvmap.value("address").toMap().value("city").toString().toStdString(),
                                       qvmap.value("address").toMap().value("lineOne").toString().toStdString(),
                                       qvmap.value("address").toMap().value("lineTwo").toString().toStdString(),
                                       qvmap.value("address").toMap().value("postalCode").toString().toStdString()),
                               qvmap.value("deleted").toBool());
}

SysAdmin* MessageParser::parseSysAdmin(QVariantMap qvmap)
{
    return new SysAdmin(   qvmap.value("username").toString().toStdString(),
                           qvmap.value("firstName").toString().toStdString(),
                           qvmap.value("lastName").toString().toStdString(),
                           Date(qvmap.value("dateOfBirth").toMap().value("day").toInt(),
                                qvmap.value("dateOfBirth").toMap().value("month").toInt(),
                                qvmap.value("dateOfBirth").toMap().value("year").toInt()),
                           ContactInfo(qvmap.value("contact").toMap().value("workPhone").toString().toStdString(),
                                       qvmap.value("contact").toMap().value("cellPhone").toString().toStdString(),
                                       qvmap.value("contact").toMap().value("email").toString().toStdString(),
                                       qvmap.value("contact").toMap().value("workEmail").toString().toStdString()),
                           Address(qvmap.value("address").toMap().value("country").toString().toStdString(),
                                   qvmap.value("address").toMap().value("city").toString().toStdString(),
                                   qvmap.value("address").toMap().value("lineOne").toString().toStdString(),
                                   qvmap.value("address").toMap().value("lineTwo").toString().toStdString(),
                                   qvmap.value("address").toMap().value("postalCode").toString().toStdString()),
                           qvmap.value("deleted").toBool());
}

Physician* MessageParser::parsePhysician(QVariantMap qvmap)
{
    return new Physician(  qvmap.value("physicianId").toInt(),
                           qvmap.value("username").toString().toStdString(),
                           qvmap.value("firstName").toString().toStdString(),
                           qvmap.value("lastName").toString().toStdString(),
                           Date(qvmap.value("dateOfBirth").toMap().value("day").toInt(),
                                qvmap.value("dateOfBirth").toMap().value("month").toInt(),
                                qvmap.value("dateOfBirth").toMap().value("year").toInt()),
                           ContactInfo(qvmap.value("contact").toMap().value("workPhone").toString().toStdString(),
                                       qvmap.value("contact").toMap().value("cellPhone").toString().toStdString(),
                                       qvmap.value("contact").toMap().value("email").toString().toStdString(),
                                       qvmap.value("contact").toMap().value("workEmail").toString().toStdString()),
                           Address(qvmap.value("address").toMap().value("country").toString().toStdString(),
                                   qvmap.value("address").toMap().value("city").toString().toStdString(),
                                   qvmap.value("address").toMap().value("lineOne").toString().toStdString(),
                                   qvmap.value("address").toMap().value("lineTwo").toString().toStdString(),
                                   qvmap.value("address").toMap().value("postalCode").toString().toStdString()),
                           qvmap.value("deleted").toBool());
}

Consultation* MessageParser::parseConsultation(QVariantMap qvmap)
{
    return new Consultation(qvmap.value("consultID").toInt(),
                            qvmap.value("reason").toString().toStdString(),
                            qvmap.value("diagnosis").toString().toStdString(),
                            qvmap.value("comments").toString().toStdString(),
                            (Consultation::ConsultationStatus)qvmap.value("status").toInt(),
                            Date(qvmap.value("date").toMap().value("day").toInt(),
                                 qvmap.value("date").toMap().value("month").toInt(),
                                 qvmap.value("date").toMap().value("year").toInt()),
                            Time(qvmap.value("time").toMap().value("hour").toInt(),
                                 qvmap.value("time").toMap().value("minute").toInt()),
                            NULL,
                            qvmap.value("deleted").toBool());
}

Patient* MessageParser::parsePatient(QVariantMap qvmap)
{
    return new Patient(qvmap.value("id").toInt(),
                       qvmap.value("firstName").toString().toStdString(),
                       qvmap.value("lastName").toString().toStdString(),
                       qvmap.value("notes").toString().toStdString(),
                       ContactInfo(qvmap.value("contact").toMap().value("workPhone").toString().toStdString(),
                                   qvmap.value("contact").toMap().value("cellPhone").toString().toStdString(),
                                   qvmap.value("contact").toMap().value("email").toString().toStdString(),
                                   qvmap.value("contact").toMap().value("workEmail").toString().toStdString()),
                       Address(qvmap.value("address").toMap().value("country").toString().toStdString(),
                               qvmap.value("address").toMap().value("city").toString().toStdString(),
                               qvmap.value("address").toMap().value("lineOne").toString().toStdString(),
                               qvmap.value("address").toMap().value("lineTwo").toString().toStdString(),
                               qvmap.value("address").toMap().value("postalCode").toString().toStdString()),
                       Date(qvmap.value("dateOfBirth").toMap().value("day").toInt(),
                            qvmap.value("dateOfBirth").toMap().value("month").toInt(),
                            qvmap.value("dateOfBirth").toMap().value("year").toInt()),
                       Date(qvmap.value("dateAddedToSystem").toMap().value("day").toInt(),
                            qvmap.value("dateAddedToSystem").toMap().value("month").toInt(),
                            qvmap.value("dateAddedToSystem").toMap().value("year").toInt()),
                       NULL,
                       HealthCard(qvmap.value("number").toString().toStdString(),
                                  Date(qvmap.value("expiry").toMap().value("day").toInt(),
                                       qvmap.value("expiry").toMap().value("month").toInt(),
                                       qvmap.value("expiry").toMap().value("year").toInt())),
                       qvmap.value("deleted").toBool());
}

ReturnConsultation* MessageParser::parseReturnConsultation(QVariantMap qvmap)
{
    return new ReturnConsultation(  qvmap.value("id").toInt(),
                                    (Followup::FollowupStatus)qvmap.value("status").toInt(),
                                    Date(qvmap.value("dateDue").toMap().value("day").toInt(),
                                         qvmap.value("dateDue").toMap().value("month").toInt(),
                                         qvmap.value("dateDue").toMap().value("year").toInt()),
                                    Date(qvmap.value("dateReceived").toMap().value("day").toInt(),
                                         qvmap.value("dateReceived").toMap().value("month").toInt(),
                                         qvmap.value("dateReceived").toMap().value("year").toInt()),
                                    Date(qvmap.value("dateCompleted").toMap().value("day").toInt(),
                                         qvmap.value("dateCompleted").toMap().value("month").toInt(),
                                         qvmap.value("dateCompleted").toMap().value("year").toInt()),
                                    NULL,
                                    qvmap.value("deleted").toBool());
}

MedicationRenewal* MessageParser::parseMedicationRenewal(QVariantMap qvmap)
{
    return new MedicationRenewal(   qvmap.value("id").toInt(),
                                    (Followup::FollowupStatus)qvmap.value("status").toInt(),
                                    Date(qvmap.value("dateDue").toMap().value("day").toInt(),
                                         qvmap.value("dateDue").toMap().value("month").toInt(),
                                         qvmap.value("dateDue").toMap().value("year").toInt()),
                                    Date(qvmap.value("dateReceived").toMap().value("day").toInt(),
                                         qvmap.value("dateReceived").toMap().value("month").toInt(),
                                         qvmap.value("dateReceived").toMap().value("year").toInt()),
                                    Date(qvmap.value("dateCompleted").toMap().value("day").toInt(),
                                         qvmap.value("dateCompleted").toMap().value("month").toInt(),
                                         qvmap.value("dateCompleted").toMap().value("year").toInt()),
                                    qvmap.value("medication").toString().toStdString(),
                                    qvmap.value("deleted").toBool());
}

Referral* MessageParser::parseReferral(QVariantMap qvmap)
{
    return new Referral(qvmap.value("id").toInt(),
                        (Followup::FollowupStatus)qvmap.value("status").toInt(),
                        Date(qvmap.value("dateDue").toMap().value("day").toInt(),
                             qvmap.value("dateDue").toMap().value("month").toInt(),
                             qvmap.value("dateDue").toMap().value("year").toInt()),
                        Date(qvmap.value("dateReceived").toMap().value("day").toInt(),
                             qvmap.value("dateReceived").toMap().value("month").toInt(),
                             qvmap.value("dateReceived").toMap().value("year").toInt()),
                        Date(qvmap.value("dateCompleted").toMap().value("day").toInt(),
                             qvmap.value("dateCompleted").toMap().value("month").toInt(),
                             qvmap.value("dateCompleted").toMap().value("year").toInt()),
                        qvmap.value("results").toString().toStdString(),
                        qvmap.value("specialistName").toString().toStdString(),
                        qvmap.value("deleted").toBool());
}

MedicalTest* MessageParser::parseMedicalTest(QVariantMap qvmap)
{
    return new MedicalTest( qvmap.value("id").toInt(),
                            (Followup::FollowupStatus)qvmap.value("status").toInt(),
                            Date(qvmap.value("dateDue").toMap().value("day").toInt(),
                                 qvmap.value("dateDue").toMap().value("month").toInt(),
                                 qvmap.value("dateDue").toMap().value("year").toInt()),
                            Date(qvmap.value("dateReceived").toMap().value("day").toInt(),
                                 qvmap.value("dateReceived").toMap().value("month").toInt(),
                                 qvmap.value("dateReceived").toMap().value("year").toInt()),
                            Date(qvmap.value("dateCompleted").toMap().value("day").toInt(),
                                 qvmap.value("dateCompleted").toMap().value("month").toInt(),
                                 qvmap.value("dateCompleted").toMap().value("year").toInt()),
                            qvmap.value("results").toString().toStdString(),
                            qvmap.value("testType").toString().toStdString(),
                            qvmap.value("deleted").toBool());
}

ConsultationFilter MessageParser::parseConsultationFilter(QVariantMap qvmap)
{
    ConsultationFilter ret;
    if(qvmap.value("consultIDMatch").toBool())
        ret.consultIDSetMatch(true);
    if(qvmap.value("patientIdMatch").toBool())
        ret.patientIdSetMatch(true);
    if(qvmap.value("reasonMatch").toBool())
        ret.reasonSetMatch(true);
    if(qvmap.value("diagnosisMatch").toBool())
        ret.diagnosisSetMatch(true);
    if(qvmap.value("commentsMatch").toBool())
        ret.commentsSetMatch(true);
    if(qvmap.value("statusMatch").toBool())
        ret.statusSetMatch(true);
    if(qvmap.value("dateMatch").toBool())
        ret.dateSetMatch(true);
    if(qvmap.value("timeMatch").toBool())
        ret.timeSetMatch(true);
    if(qvmap.value("pConsultingPhysMatch").toBool())
        ret.pConsultingPhysSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    return ret;
}

PatientFilter MessageParser::parsePatientFilter(QVariantMap qvmap)
{
    PatientFilter ret;
    if(qvmap.value("idMatch").toBool())
        ret.idSetMatch(true);
    if(qvmap.value("firstNameMatch").toBool())
        ret.firstNameSetMatch(true);
    if(qvmap.value("lastNameMatch").toBool())
        ret.lastNameSetMatch(true);
    if(qvmap.value("notesMatch").toBool())
        ret.notesSetMatch(true);
    if(qvmap.value("contactMatch").toBool())
        ret.contactSetMatch(true);
    if(qvmap.value("addressMatch").toBool())
        ret.addressSetMatch(true);
    if(qvmap.value("dateOfBirthMatch").toBool())
        ret.dateOfBirthSetMatch(true);
    if(qvmap.value("dateAddedToSystemMatch").toBool())
        ret.dateAddedToSystemSetMatch(true);
    if(qvmap.value("healthCardMatch").toBool())
        ret.healthCardSetMatch(true);
    if(qvmap.value("pPhysicianMatch").toBool())
        ret.pPhysicianSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    return ret;
}

UserFilter MessageParser::parseUserFilter(QVariantMap qvmap)
{
    UserFilter ret;
    if(qvmap.value("usernameMatch").toBool())
        ret.usernameSetMatch(true);
    if(qvmap.value("firstNameMatch").toBool())
        ret.firstNameSetMatch(true);
    if(qvmap.value("lastNameMatch").toBool())
        ret.lastNameSetMatch(true);
    if(qvmap.value("titleMatch").toBool())
        ret.titleSetMatch(true);
    if(qvmap.value("dateOfBirthMatch").toBool())
        ret.dateOfBirthSetMatch(true);
    if(qvmap.value("contactMatch").toBool())
        ret.contactSetMatch(true);
    if(qvmap.value("addressMatch").toBool())
        ret.addressSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    return ret;
}

PhysicianFilter MessageParser::parsePhysicianFilter(QVariantMap qvmap)
{
    PhysicianFilter ret;
    if(qvmap.value("idMatch").toBool())
        ret.idSetMatch(true);
    if(qvmap.value("usernameMatch").toBool())
        ret.usernameSetMatch(true);
    if(qvmap.value("firstNameMatch").toBool())
        ret.firstNameSetMatch(true);
    if(qvmap.value("lastNameMatch").toBool())
        ret.lastNameSetMatch(true);
    if(qvmap.value("titleMatch").toBool())
        ret.titleSetMatch(true);
    if(qvmap.value("dateOfBirthMatch").toBool())
        ret.dateOfBirthSetMatch(true);
    if(qvmap.value("contactMatch").toBool())
        ret.contactSetMatch(true);
    if(qvmap.value("addressMatch").toBool())
        ret.addressSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    return ret;
}

ReturnConsultationFilter MessageParser::parseReturnConsultationFilter(QVariantMap qvmap)
{
    ReturnConsultationFilter ret;
    if(qvmap.value("idMatch").toBool())
        ret.idSetMatch(true);
    if(qvmap.value("statusMatch").toBool())
        ret.statusSetMatch(true);
    if(qvmap.value("dateDueMatch").toBool())
        ret.dateDueSetMatch(true);
    if(qvmap.value("dateReceivedMatch").toBool())
        ret.dateReceivedSetMatch(true);
    if(qvmap.value("dateCompletedMatch").toBool())
        ret.dateCompletedSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    if(qvmap.value("pConsultMatch").toBool())
        ret.pConsultSetMatch(true);
    return ret;
}

MedicationRenewalFilter MessageParser::parseMedicationRenewalFilter(QVariantMap qvmap)
{
    MedicationRenewalFilter ret;
    if(qvmap.value("idMatch").toBool())
        ret.idSetMatch(true);
    if(qvmap.value("statusMatch").toBool())
        ret.statusSetMatch(true);
    if(qvmap.value("dateDueMatch").toBool())
        ret.dateDueSetMatch(true);
    if(qvmap.value("dateReceivedMatch").toBool())
        ret.dateReceivedSetMatch(true);
    if(qvmap.value("dateCompletedMatch").toBool())
        ret.dateCompletedSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    if(qvmap.value("medicationMatch").toBool())
        ret.medicationSetMatch(true);
    return ret;
}

ReferralFilter MessageParser::parseReferralFilter(QVariantMap qvmap)
{
    ReferralFilter ret;
    if(qvmap.value("idMatch").toBool())
        ret.idSetMatch(true);
    if(qvmap.value("statusMatch").toBool())
        ret.statusSetMatch(true);
    if(qvmap.value("dateDueMatch").toBool())
        ret.dateDueSetMatch(true);
    if(qvmap.value("dateReceivedMatch").toBool())
        ret.dateReceivedSetMatch(true);
    if(qvmap.value("dateCompletedMatch").toBool())
        ret.dateCompletedSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    if(qvmap.value("resultsMatch").toBool())
        ret.resultsSetMatch(true);
    if(qvmap.value("specialistNameMatch").toBool())
        ret.specialistNameSetMatch(true);
    return ret;
}

MedicalTestFilter MessageParser::parseMedicalTestFilter(QVariantMap qvmap)
{
    MedicalTestFilter ret;
    if(qvmap.value("idMatch").toBool())
        ret.idSetMatch(true);
    if(qvmap.value("statusMatch").toBool())
        ret.statusSetMatch(true);
    if(qvmap.value("dateDueMatch").toBool())
        ret.dateDueSetMatch(true);
    if(qvmap.value("dateReceivedMatch").toBool())
        ret.dateReceivedSetMatch(true);
    if(qvmap.value("dateCompletedMatch").toBool())
        ret.dateCompletedSetMatch(true);
    if(qvmap.value("deletedMatch").toBool())
        ret.deletedSetMatch(true);
    if(qvmap.value("resultsMatch").toBool())
        ret.resultsSetMatch(true);
    if(qvmap.value("testTypeMatch").toBool())
        ret.testTypeSetMatch(true);
    return ret;
}

void MessageParser::parseAdminAssistantList(QList<QVariant> qvlist, vector<AdminAssistant *> *vect)
{
    std::cout << qvlist.size() << "\n";
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parseAdminAssistant(qvlist.at(i).toMap()));
    std::cout << "finished parseList\n";
    std::cout << "AA firstName from parse method: " << vect->at(0)->getFirstName() << "\n";
}

void MessageParser::parsePatientList(QList<QVariant> qvlist, vector<Patient *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parsePatient(qvlist.at(i).toMap()));
}

void MessageParser::parsePhysicianList(QList<QVariant> qvlist, vector<Physician *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parsePhysician(qvlist.at(i).toMap()));
}

void MessageParser::parseConsultationList(QList<QVariant> qvlist, vector<Consultation *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parseConsultation(qvlist.at(i).toMap()));
}

void MessageParser::parseReferralList(QList<QVariant> qvlist, vector<Referral *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parseReferral(qvlist.at(i).toMap()));
}

void MessageParser::parseMedicationRenewalList(QList<QVariant> qvlist, vector<MedicationRenewal *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parseMedicationRenewal(qvlist.at(i).toMap()));
}

void MessageParser::parseMedicalTestList(QList<QVariant> qvlist, vector<MedicalTest *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parseMedicalTest(qvlist.at(i).toMap()));
}

void MessageParser::parseReturnConsultationList(QList<QVariant> qvlist, vector<ReturnConsultation *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parseReturnConsultation(qvlist.at(i).toMap()));
}

void MessageParser::parseSysAdminList(QList<QVariant> qvlist, vector<SysAdmin *> *vect)
{
    for(int i = 0; i < qvlist.size(); i++)
        vect->push_back(MessageParser::parseSysAdmin(qvlist.at(i).toMap()));
}





