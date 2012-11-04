// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
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
    : consultID (consultIDParam),
      reason (reasonParam),
      diagnosis (diagnosisParam),
      comments (commentsParam),
      status (statusParam),
      date (dateParam),
      time (timeParam),
      pConsultingPhys (pConsultingPhysParam),
      deleted (deletedParam)
{
}

// Destructor
Consultation::~Consultation()
{
    for(unsigned int i=0; i < Followups.size(); i++)
        delete Followups[i];
}

int Consultation::getConsultID() { return consultID; }
void Consultation::setConsultID(int newConsultID) { consultID = newConsultID };

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

void Consultation::markDeleted() { deleted = true; }
bool Consultation::isDeleted() { return deleted; }
// EOF
