#include "request.h"

Request::Request(string serverAddressArg, quint16 serverPortArg)
{
    serverIPAddress = QHostAddress(QString::fromStdString(serverAddressArg));
    serverPort = serverPortArg;


}

Request::~Request()
{ }

//Creation functions

int Request::createPhysician(string **ppErrString, Physician inputPhysician, int **ppUid)
{
    QString *pRequestMessage;
    QString *pReplyMessage;
    string *pLocalErrString;
    int *pLocalUid;
    ClientSocket theSock(serverIPAddress, serverPort);

    try
    {
    MessageGenerator::makeCreatePhysicianMessage(inputPhysician, &pRequestMessage);
    }
    catch(char const* pErrStr)
    {
        (*ppErrString) = new string(pErrStr);
        return -1;
    }

    if (! theSock.sendRecieve(&localErrString, *pRequestMessage, &pReplyMessage))
    {
        delete pRequestMessage;
        (*ppErrString) = pLocalErrString;
        return -2;
    }

    delete pRequestMessage;

    if(! MessageParser::parseCreateReply(&localErrString, *pReplyMessage, &pLocalUid))
    {

        delete pReplyMessage;
        return -3;
    }

    delete pReplyMessage;
    (*ppUid) = pLocalUid;
    return 0;

}

int Request::createAdminAssistant(string **ppErrString, AdminAssistant inputAdminAssistant, int **ppUid)
{
    QString *pRequestMessage;
    QString *pReplyMessage;
    string *pLocalErrString;
    int *pLocalUid;
    ClientSocket theSock(serverIPAddress, serverPort);

    try
    {
    MessageGenerator::makeCreateAdminAssistantMessage(inputAdminAssistant, &pRequestMessage);
    }
    catch(char const* pErrStr)
    {
        (*ppErrString) = new string(pErrStr);
        return -1;
    }

    if (! theSock.sendRecieve(&localErrString, *pRequestMessage, &pReplyMessage))
    {
        delete pRequestMessage;
        (*ppErrString) = pLocalErrString;
        return -2;
    }

    delete pRequestMessage;

    if(! MessageParser::parseCreateReply(&localErrString, *pReplyMessage, &pLocalUid))
    {

        delete pReplyMessage;
        return -3;
    }

    delete pReplyMessage;
    (*ppUid) = pLocalUid;
    return 0;
}

int Request::createSysAdmin(string **ppErrString, SysAdmin inputSysAdmin, int **ppUid)
{
    //TODO: either abstract out some functionality, or copy paste most of the above code into each of these
}

int Request::createPatient(string **ppErrString, Patient inputPatient, int physicianId, int **ppUid)
{

}

int Request::createConsultation(string **ppErrString, Consultation inputConsultation, int physicianId, int patientId, int **ppUid)
{

}

int Request::createReferral(string **ppErrString, Referral inputReferral, int consultationId, int **ppUid)
{

}

int Request::createMedicalTest(string **ppErrString, MedicalTest inputMedicalTest, int consultationId, int **ppUid)
{

}

int Request::createReturnConsultation(string **ppErrString, ReturnConsultation inputReturnConsultation, int consultationId, int nextConsultationId, int **ppUid)
{

}

int Request::createMedicationRenewal(string **ppErrString, MedicationRenewal inputMedicationRenewal, int consultationId, int **ppUid)
{

}


//Modification functions

int Request::pushUser(string **ppErrString, User inputUser)
{

}

int Request::pushPatient(string **ppErrString, Patient inputPatient, int physicianId)
{

}

int Request::pushConsultation(string **ppErrString, Consultation inputPatient, int physicianId, int patientId)
{

}

int Request::pushReferral(string **ppErrString, Referral inputReferral, int consultationId)
{

}

int Request::pushMedicalTest(string **ppErrString, MedicalTest inputMedicalTest, int physicianId)
{

}

int Request::pushReturnConsultation(string **ppErrString, ReturnConsultation inputReturnConsultation, int physicianId, int nextConsultationId)
{

}

int Request::pushMedicationRenewal(string **ppErrString, MedicationRenewal inputMedicationRenewal, int physicianId)
{

}

//Object Retrieval Functions

//    int Request::pullPhysicians(string **ppErrString, PhysicianFilter inputFilter, vector<Physician> *pOutputPhysicians)
//    {

//    }

//    int Request::pullAdminAssistants(string **ppErrString, AdminAssistantFilter inputFilter, vector<AdminAssistant> *pOutputAdminAssistants)
//    {

//    }

//    int Request::pullSysAdmins(string **ppErrString, SysAdminFilter inputFilter, vector<SysAdmin> *pOutputSysAdmins)
//    {

//    }

//    int Request::pullPatients(string **ppErrString, PatientFilter inputFilter)
//    {

//    }

//    int Request::pullConsultatiosn(string **ppErrString, ConsultationFilter inputFilter)
//    {

//    }

//    int Request::pulleReferrals(string **ppErrString, ReferralFilter inputFilter)
//    {

//    }

//    int Request::pullMedicalTests(string **ppErrString, MedicalTestFilter inputFilter)
//    {

//    }

//    int Request::pullReturnConsultations(string **ppErrString, ReturnConsultationFilter inputFilter)
//    {

//    }

//    int Request::pullMedicationRenewals(string **ppErrString, MedicationRenewalsFilter inputFilter)
//    {

//    }


//int Request::makeRequest(string *pErrString, QString requestString, QString *pReplyString);
