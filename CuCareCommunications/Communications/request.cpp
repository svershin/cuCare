#include "request.h"

Request::Request(string serverAddressArg, quint16 serverPortArg)
{
    serverIPAddress = QHostAddress(QString::fromStdString(serverAddressArg));
    serverPort = serverPortArg;
}

Request::~Request()
{ }

//Creation functions

int Request::createPhysician(string *pErrString, Physician  *inputPhysician, int *pUid)
{
//    QString *pRequestMessage;
//    QString *pReplyMessage;
//    string *pLocalErrString;
//    int *pLocalUid;
//    ClientSocket theSock(serverIPAddress, serverPort);

//    try
//    {
//    MessageGenerator::makeCreatePhysicianMessage(inputPhysician, &pRequestMessage);
//    }
//    catch(char const* pErrStr)
//    {
//        (*pErrString) = pErrStr;
//        return -1;
//    }

//    if (! theSock.sendRecieve(&pLocalErrString, *pRequestMessage, &pReplyMessage))
//    {
//        delete pRequestMessage;
//        (*pErrString) = *pLocalErrString;
//        return -2;
//    }

//    delete pRequestMessage;

//    if(! MessageParser::parseCreateReply(&pLocalErrString, *pReplyMessage, &pLocalUid))
//    {

//        delete pReplyMessage;
//        return -3;
//    }

//    delete pReplyMessage;
//    (*pUid) = pLocalUid;
//    return 0;

}

int Request::createAdminAssistant(string *pErrString, AdminAssistant  *inputAdminAssistant, int *pUid)
{

}

int Request::createSysAdmin(string *pErrString, SysAdmin *inputSysAdmin, int *pUid)
{
    //TODO: either abstract out some functionality, or copy paste most of the above code into each of these
}

int Request::createPatient(string *pErrString, Patient *inputPatient, int physicianId, int *pUid)
{

}

int Request::createConsultation(string *pErrString, Consultation *inputConsultation, int physicianId, int patientId, int *pUid)
{

}

int Request::createReferral(string *pErrString, Referral *inputReferral, int consultationId, int *pUid)
{

}

int Request::createMedicalTest(string *pErrString, MedicalTest *inputMedicalTest, int consultationId, int *pUid)
{

}

int Request::createReturnConsultation(string *pErrString, ReturnConsultation *inputReturnConsultation, int consultationId, int nextConsultationId, int *pUid)
{

}

int Request::createMedicationRenewal(string *pErrString, MedicationRenewal *inputMedicationRenewal, int consultationId, int *pUid)
{

}


//Modification functions

int Request::pushUser(string *pErrString, User *inputUser)
{

}

int Request::pushPatient(string *pErrString, Patient *inputPatient, int physicianId)
{

}

int Request::pushConsultation(string *pErrString, Consultation *inputPatient, int physicianId, int patientId)
{

}

int Request::pushReferral(string *pErrString, Referral *inputReferral, int consultationId)
{

}

int Request::pushMedicalTest(string *pErrString, MedicalTest *inputMedicalTest, int physicianId)
{

}

int Request::pushReturnConsultation(string *pErrString, ReturnConsultation *inputReturnConsultation, int physicianId, int nextConsultationId)
{

}

int Request::pushMedicationRenewal(string *pErrString, MedicationRenewal *inputMedicationRenewal, int physicianId)
{

}

//Object Retrieval Functions

//    int Request::pullPhysicians(string *pErrString, PhysicianFilter *inputFilter, vector<Physician> *pOutputPhysicians)
//    {

//    }

//    int Request::pullAdminAssistants(string *pErrString, AdminAssistantFilter *inputFilter, vector<AdminAssistant> *pOutputAdminAssistants)
//    {

//    }

//    int Request::pullSysAdmins(string *pErrString, SysAdminFilter *inputFilter, vector<SysAdmin> *pOutputSysAdmins)
//    {

//    }

//    int Request::pullPatients(string *pErrString, PatientFilter *inputFilter)
//    {

//    }

//    int Request::pullConsultatiosn(string *pErrString, ConsultationFilter *inputFilter)
//    {

//    }

//    int Request::pulleReferrals(string *pErrString, ReferralFilter *inputFilter)
//    {

//    }

//    int Request::pullMedicalTests(string *pErrString, MedicalTestFilter *inputFilter)
//    {

//    }

//    int Request::pullReturnConsultations(string *pErrString, ReturnConsultationFilter *inputFilter)
//    {

//    }

//    int Request::pullMedicationRenewals(string *pErrString, MedicationRenewalsFilter *inputFilter)
//    {

//    }


//int Request::makeRequest(string *pErrString, QString requestString, QString *pReplyString);
