#ifndef REQUEST_H
#define REQUEST_H


#include "commsinclude.h"
#include "clientsocket.h"
#include "messagegenerator.h"
#include <QVariant>
#include "messageparser.h"

class Request {

private:
    quint16 serverPort;
    QHostAddress serverIPAddress;

public:
    Request(string serverIPAddressParam, quint16 serverPortParam);
    ~Request();

    //Creation functions
    int createPhysician(string **ppErrString, Physician inputPhysician, int **ppUid);
    int createAdminAssistant(string **ppErrString, AdminAssistant inputAdminAssistant, int **ppUid);
    int createSysAdmin(string **ppErrString, SysAdmin inputSysAdmin, int **ppUid);
    int createPatient(string **ppErrString, Patient inputPatient, int physicianId, int **ppUid);
    int createConsultation(string **ppErrString, Consultation inputConsultation, int physicianId, int patientId, int **ppUid);
    int createReferral(string **ppErrString, Referral inputReferral, int consultationId, int **ppUid);
    int createMedicalTest(string **ppErrString, MedicalTest inputMedicalTest, int consultationId, int **ppUid);
    int createReturnConsultation(string **ppErrString, ReturnConsultation inputReturnConsultation, int consultationId, int nextConsultationId, int **ppUid);
    int createMedicationRenewal(string **ppErrString, MedicationRenewal inputMedicationRenewal, int consultationId, int **ppUid);

    //Modification functions
    int pushUser(string **ppErrString, User inputUser);
    int pushPatient(string **ppErrString, Patient inputPatient, int physicianId);
    int pushConsultation(string **ppErrString, Consultation inputPatient, int physicianId, int patientId);
    int pushReferral(string **ppErrString, Referral inputReferral, int consultationId);
    int pushMedicalTest(string **ppErrString, MedicalTest inputMedicalTest, int physicianId);
    int pushReturnConsultation(string **ppErrString, ReturnConsultation inputReturnConsultation, int physicianId, int nextConsultationId);
    int pushMedicationRenewal(string **ppErrString, MedicationRenewal inputMedicationRenewal, int physicianId);

    //Object retrieval functions
//    int pullPhysicians(string **ppErrString, PhysicianFilter inputFilter, vector<Physician> *pOutputPhysicians);
//    int pullAdminAssistants(string **ppErrString, AdminAssistantFilter inputFilter, vector<AdminAssistant> *pOutputAdminAssistants);
//    int pullSysAdmins(string **ppErrString, SysAdminFilter inputFilter, vector<SysAdmin> *pOutputSysAdmins);
//    int pullPatients(string **ppErrString, PatientFilter inputFilter);
//    int pullConsultatiosn(string **ppErrString, ConsultationFilter inputFilter);
//    int pulleReferrals(string **ppErrString, ReferralFilter inputFilter);
//    int pullMedicalTests(string **ppErrString, MedicalTestFilter inputFilter);
//    int pullReturnConsultations(string **ppErrString, ReturnConsultationFilter inputFilter);
//    int pullMedicationRenewals(string **ppErrString, MedicationRenewalsFilter inputFilter);


private:
    QHostAddress getServerAddress();
    quint16 getServerPort();
};

#endif // REQUEST_H
