// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// Consultation.h - Declaration of base class Consultation
// Member functions are defined in Consultation.cpp

#include "Consultation.h"

// Constructor
Consultation::Consultation
(   int consultIDParam,
    string reasonParam,
    string diagnosisParam,
    string commentsParam,
    Consultation::ConsultationStatus statusParam,
    Date dateParam,
    Time timeParam,
    Physician* pConsultingPhysParam,
    bool deletedParam)
    : QObject(),
      consultID (consultIDParam),
      reason (reasonParam),
      diagnosis (diagnosisParam),
      comments (commentsParam),
      status (statusParam),
      date (dateParam),
      time (timeParam),
      pConsultingPhys (pConsultingPhysParam),
      deleted (deletedParam)
{}


//Blank constructor
Consulation::Consulation()
{}

//Copy Constructor
Consultation::Consultation(const Address& origin) :
QObject(),
consultID (origin.consultID),
reason (origin.reason),
diagnosis (origin.diagnosis),
comments (origin.comments),
status (origin.status),
date (origin.date),
time (origin.time),
pConsultingPhys (origin.pConsultingPhys),
deleted (origin.deleted)
{}


//Assignment operator
Consultation& Consultation::operator=(const Consultation& origin)
{
    consultID = origin.consultID;
    reason = origin.reason;
    diagnosis = origin.diagnosis;
    comments = origin.comments;
    status = origin.status;
    date = origin.date;
    time = origin.time;
    pConsultingPhys = origin.pConsultingPhys;
    deleted = origin.deleted;
    return *this;
}


// Destructor
Consultation::~Consultation()
{
    for(unsigned int i=0; i < Followups.size(); i++)
    delete Followups[i];
}

int Consultation::getConsultID() { return consultID; }
void Consultation::setConsultID(int newConsultID) { consultID = newConsultID; }

string Consultation::getReason() { return reason; }
void Consultation::setReason(const string value) { reason = value; }

string Consultation::getDiagnosis() { return diagnosis; }
void Consultation::setDiagnosis(const string value) { diagnosis = value; }

string Consultation::getComments() { return comments; }
void Consultation::setComments(const string value) { comments = value; }

Consultation::ConsultationStatus Consultation::getStatus() { return status; }
void Consultation::setStatus(const ConsultationStatus value) { status = value; }

Date Consultation::getDate() { return date; }
void Consultation::setDate(const Date value) { date = value; }

Time Consultation::getTime() { return time; }
void Consultation::setTime(const Time value) { time = value; }

Physician* Consultation::getConsultingPhys() { return pConsultingPhys; }
void Consultation::setConsultingPhys(Physician* const value) { pConsultingPhys = value; }

vector<Followup*>* Consultation::getFollowups() { return &Followups; }

void Consultation::markDeleted() { deleted = true; }
bool Consultation::isDeleted() { return deleted; }


// Special getters and setters for serialization purposes
//
QString Consultation::qGetReason(){return QString::fromStdString(reason);}
void Consultation::qSetReason(const QString value){reason = value.toStdString();}

QString Consultation::qGetDiagnosis(){return QString::fromStdString(diagnosis);}
void Consultation::qSetDiagnosis(const QString value){diagnosis = value.toStdString();}

QString Consultation::qGetComments(){return QString::fromStdString(comments);}
void Consultation::qSetComments(const QString value){comments = value.toStdString();}

QVariantMap Consultation::qGetDate(){return QJson::QObjectHelper::qobject2qvariant(&date);}
//void Consultation::qSetDate(const QVariantMap value);

QVariantMap Consultation::qGetTime(){return QJson::QObjectHelper::qobject2qvariant(&time);}
//void Consultation::qSetTime(const QVariantMap value);

void Consultation::qPutDeleted(const bool value){deleted = value;}

// EOF
