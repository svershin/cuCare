#include "request.h"

Request::Request(string serverAddressArg, quint16 serverPortArg)
{
    serverIPAddress = QHostAddress(QString::fromStdString(serverAddressArg));
    serverPort = serverPortArg;
}

Request::~Request()
{}

int Request::sendRecieve(string *pErrString, QByteArray input, QVariantMap *output)
{

}

//Creation functions

int Request::createPhysician(string *pErrString, Physician  *inputPhysician, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createPhysicianMessage(inputPhysician);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}

int Request::createAdminAssistant(string *pErrString, AdminAssistant  *inputAdminAssistant, int *pUid)
{


    QByteArray reqBytes = MessageGenerator::createAdminAssistantMessage(inputAdminAssistant);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;


}

int Request::createSysAdmin(string *pErrString, SysAdmin *inputSysAdmin, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createSysAdminMessage(inputSysAdmin);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}

int Request::createPatient(string *pErrString, Patient *inputPatient, int physicianId, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createPatientMessage(inputPatient, physicianId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}

int Request::createConsultation(string *pErrString, Consultation *inputConsultation, int physicianId, int patientId, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createConsultationMessage(inputConsultation, physicianId, patientId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}

int Request::createReferral(string *pErrString, Referral *inputReferral, int consultationId, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createReferralMessage(inputReferral, consultationId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}

int Request::createMedicalTest(string *pErrString, MedicalTest *inputMedicalTest, int consultationId, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createMedicalTestMessage(inputMedicalTest, consultationId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}

int Request::createReturnConsultation(string *pErrString, ReturnConsultation *inputReturnConsultation, int consultationId, int nextConsultationId, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createReturnConsultationMessage(inputReturnConsultation, consultationId, nextConsultationId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}

int Request::createMedicationRenewal(string *pErrString, MedicationRenewal *inputMedicationRenewal, int consultationId, int *pUid)
{
    QByteArray reqBytes = MessageGenerator::createMedicationRenewalMessage(inputMedicationRenewal, consultationId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    *pUid = reply.value("payload").toInt();
    return 0;
}




//Modification functions
//
int Request::pushUser(string *pErrString, User *inputUser)
{
    QByteArray reqBytes = MessageGenerator::pushUserMessage(inputUser);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    return 0;

}

int Request::pushPatient(string *pErrString, Patient *inputPatient, int physicianId)
{
    QByteArray reqBytes = MessageGenerator::pushPatientMessage(inputPatient, physicianId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    return 0;
}

int Request::pushConsultation(string *pErrString, Consultation *inputPatient, int physicianId, int patientId)
{
    QByteArray reqBytes = MessageGenerator::pushConsultationMessage(inputPatient, physicianId, patientId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    return 0;
}

int Request::pushReferral(string *pErrString, Referral *inputReferral, int consultationId)
{
    QByteArray reqBytes = MessageGenerator::pushReferralMessage(inputReferral, consultationId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    return 0;
}

int Request::pushMedicalTest(string *pErrString, MedicalTest *inputMedicalTest, int physicianId)
{
    QByteArray reqBytes = MessageGenerator::pushMedicalTestMessage(inputMedicalTest, physicianId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    return 0;
}

int Request::pushReturnConsultation(string *pErrString, ReturnConsultation *inputReturnConsultation, int physicianId, int nextConsultationId)
{
    QByteArray reqBytes = MessageGenerator::pushReturnConsultationMessage(inputReturnConsultation, physicianId, nextConsultationId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    return 0;
}

int Request::pushMedicationRenewal(string *pErrString, MedicationRenewal *inputMedicationRenewal, int physicianId)
{
    QByteArray reqBytes = MessageGenerator::pushMedicationRenewalMessage(inputMedicationRenewal, physicianId);

    string localErrString;
    QVariantMap reply;

    int temp = sendRecieve(&localErrString, reqBytes, &reply);

    if(0 != temp)
    {
        *pErrString = localErrString;
        return temp;
    }

    if(!reply.value("outcome").toBool())
    {
        *pErrString = "something went wrong on the server";
        return -3;
    }

    return 0;
}



//Object retreival methods
//
int Request::pullPhysician(string *pErrString, Physician *pPhysicianValues, PhysicianFilter inputFilter, vector<Physician*> *pOutputPhysicians)
{
    QByteArray reqBytes = MessageGenerator::pullPhysicianMessage(pPhysicianValues, inputFilter);
}

int Request::pullAdminAssistant(string *pErrString, AdminAssistant *pPhysicianValues, UserFilter inputFilter, vector<AdminAssistant*> *pOutputAdminAssistants)
{
    QByteArray reqBytes = MessageGenerator::pullAdminAssistantMessage(pPhysicianValues, inputFilter);
}

int Request::pullSysAdmin(string *pErrString, SysAdmin *pSysAdminValues, UserFilter inputFilter, vector<SysAdmin*> *pOutputSysAdmins)
{
    QByteArray reqBytes = MessageGenerator::pullSysAdminMessage(pSysAdminValues, inputFilter);
}

int Request::pullPatient(string *pErrString, Patient *pPatientValues, PatientFilter inputFilter, int physicianId, vector<Patient*> *pOutputPatients)
{
    QByteArray reqBytes = MessageGenerator::pullPatientMessage(pPatientValues, inputFilter, physicianId);
}

int Request::pullConsultation(string *pErrString, Consultation *pConsultationValues, ConsultationFilter inputFilter, int physicianId, int patientId, vector<Consultation*> *pOutputConsultations)
{
    QByteArray reqBytes = MessageGenerator::pullConsultationMessage(pConsultationValues, inputFilter, physicianId, patientId);
}

int Request::pullReferral(string *pErrString, Referral *pReferralValues, ReferralFilter inputFilter, int consultationId, vector<Referral*> *pOutputReferral)
{
    QByteArray reqBytes = MessageGenerator::pullReferralMessage(pReferralValues, inputFilter, consultationId);
}

int Request::pullMedicalTest(string *pErrString, MedicalTest *pMedicalTestValues, MedicalTestFilter inputFilter, int consultationId, vector<MedicalTest*> *pOutputMedicalTests)
{
    QByteArray reqBytes = MessageGenerator::pullMedicalTestMessage(pMedicalTestValues, inputFilter, consultationId);
}

int Request::pullReturnConsultation(string *pErrString, ReturnConsultation *pReturnConsultationValues, ReturnConsultationFilter inputFilter, int consultationId, int nextConsultationId, vector<ReturnConsultation*> *pOutputReturnConsultation)
{
    QByteArray reqBytes = MessageGenerator::pullReturnConsultationMessage(pReturnConsultationValues, inputFilter, consultationId, nextConsultationId);
}

int Request::pullMedicationRenewal(string *pErrString, MedicationRenewal *pMedicationRenewalValues, MedicationRenewalFilter inputFilter, int consultationId, vector<MedicationRenewal*> *pOutputMedicationRenewal)
{
    QByteArray reqBytes = MessageGenerator::pullMedicationRenewalMessage(pMedicationRenewalValues, inputFilter, consultationId);
}

