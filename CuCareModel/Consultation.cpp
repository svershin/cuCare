// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Consultation.h - Declaration of base class Consultation
// Member functions are defined in Consultation.cpp

#include "Consultation.h"

//You will need these includes
#include "StringProperty.h"
#include "IntProperty.h"

Consultation::Consultation()
{
    //This is where properties get added.
    //Use IntProperty or StringProperty depending on the type
    //First parmeter is the property name.  It should be the same as the name of the data member
    //Second parameter is always this
    //Third parameter is the virtual get method from ModelObject.  &ModelObject::nameOfGetMethod
    //There are no brackets after the method name - watch out, the autocomplete will try to put them in for you.
    //Fourth paremeter is the virtual set method from ModelObject.  Same format.
    getProperties()->push_back(new IntProperty("consultId", this, &ModelObject::getConsultId, &ModelObject::setConsultId));
    getProperties()->push_back(new StringProperty("reason", this, &ModelObject::getReason, &ModelObject::setReason));
}

Consultation::~Consultation()
{
}

int Consultation::getConsultId() { return consultID; }
void Consultation::setConsultId(int newConsultID) { consultID = newConsultID; }

string Consultation::getReason() { return reason; }
void Consultation::setReason(const string value) { reason = value; }

string Consultation::getDiagnosis() { return diagnosis; }
void Consultation::setDiagnosis(const string value) { diagnosis = value; }

string Consultation::getComments() { return comments; }
void Consultation::setComments(const string value) { comments = value; }

Consultation::ConsultationStatus Consultation::getStatus() { return status; }
void Consultation::setStatus(const ConsultationStatus value) { status = value; }

int Consultation::getDay() { return date.getDay(); }
void Consultation::setDay(int value) { date.setDay(value); }

int Consultation::getMonth() { return date.getMonth(); }
void Consultation::setMonth(int value) { date.setMonth(value); }

int Consultation::getYear() { return date.getYear(); }
void Consultation::setYear(int value) { date.setYear(value); }

int Consultation::getHour() { return time.getHour(); }
void Consultation::setHour(int value) { time.setHour(value); }

int Consultation::getMinute() { return time.getMinute(); }
void Consultation::setMinute(int value) { time.setMinute(value); }

int Consultation::getConsultingPhysId() { return consultingPhysId; }
void Consultation::setConsultingPhysId(int value) { consultingPhysId = value; }

vector<int>* Consultation::getFollowupIds() { return &Followups; }

// EOF
