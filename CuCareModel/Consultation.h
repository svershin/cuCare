// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Consultation.h - Declaration of base class Consultation
// Member functions are defined in Consultation.cpp

#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <string>
#include <vector>
#include "Date.h"
#include "Time.h"
#include "Followup.h"
#include "Physician.h"
#include <QtGlobal>
#include <QVariantMap>

using namespace std;

class Consultation : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int consultID READ getConsultID WRITE setConsultID)
    Q_PROPERTY(QString reason READ qGetReason WRITE qSetReason)
    Q_PROPERTY(QString diagnosis READ qGetDiagnosis WRITE qSetDiagnosis)
    Q_PROPERTY(QString comments READ qGetComments WRITE qSetComments)
    Q_PROPERTY(ConsultationStatus status READ getStatus WRITE setStatus)
    Q_PROPERTY(QVariantMap date READ qGetDate WRITE qSetDate)
    Q_PROPERTY(QVariantMap time READ qGetTime WRITE qSetTime)
    Q_PROPERTY(bool deleted READ isDeleted WRITE qPutDeleted)
    Q_ENUMS(ConsultationStatus)




public:

    enum ConsultationStatus
    {
        CSTAT_ERROR,
        CSTAT_PENDING,
        CSTAT_OCCURED,
        CSTAT_COMPLETED
    };

    // Constructor
    Consultation (int consultIDParam,
                  string reasonParam,
                  string diagnosisParam,
                  string commentsParam,
                  ConsultationStatus statusParam,
                  Date dateParam,
                  Time timeParam,
                  Physician* pConsultingPhysParam,
                  bool deletedParam);

    // Destructor
    ~Consultation();

    int getConsultID();
    void setConsultID(int newConsultID);

    string getReason();
    void setReason(const string value);

    string getDiagnosis();
    void setDiagnosis(const string value);

    string getComments();
    void setComments(const string value);

    ConsultationStatus getStatus();
    void setStatus(const ConsultationStatus value);

    Date getDate();
    void setDate(const Date value);

    Time getTime();
    void setTime(const Time value);

    Physician* getConsultingPhys();
    void setConsultingPhys(Physician* const value);

    vector<Followup*>* getFollowups();

    void markDeleted();
    bool isDeleted();


    //Special getters and setters for serialization purposes
    QString qGetReason();
    void qSetReason(const QString value);

    QString qGetDiagnosis();
    void qSetDiagnosis(const QString value);

    QString qGetComments();
    void qSetComments(const QString value);

    QVariantMap qGetDate();
    void qSetDate(const QVariantMap value);

    QVariantMap qGetTime();
    void qSetTime(const QVariantMap value);

    void qPutDeleted(const bool value);

protected:
private:
    int consultID;
    string reason;
    string diagnosis;
    string comments;
    ConsultationStatus status;
    Date date;
    Time time;
    vector<Followup*> Followups;
    Physician* pConsultingPhys;
    bool deleted;
};


#endif

// EOF
