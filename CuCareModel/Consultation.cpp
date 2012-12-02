// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Consultation.cpp - Implementation of class Consultation
// Function and attribute declarations are in Consultation.h

#include "Consultation.h"
#include "StringProperty.h"
#include "IntProperty.h"

Consultation::Consultation()
    : consultId (0),
      reason (""),
      diagnosis (""),
      comments (""),
      status (CSTAT_PENDING),
      consultingPhysId (0)
{
    getProperties()->push_back(new IntProperty(ID_NAME, this, &ModelObject::getId, &ModelObject::setId));
	getProperties()->push_back(new IntProperty("physicianid", this, &ModelObject::getPhysicianId, &ModelObject::setPhysicianId));
	getProperties()->push_back(new StringProperty("reason", this, &ModelObject::getReason, &ModelObject::setReason));
	getProperties()->push_back(new StringProperty("diagnosis", this, &ModelObject::getDiagnosis, &ModelObject::setDiagnosis));
	getProperties()->push_back(new IntProperty("status", this, &ModelObject::getCStatus, &ModelObject::setCStatus));
	getProperties()->push_back(new IntProperty("day", this, &ModelObject::getDay, &ModelObject::setDay));
	getProperties()->push_back(new IntProperty("month", this, &ModelObject::getMonth, &ModelObject::setMonth));
	getProperties()->push_back(new IntProperty("year", this, &ModelObject::getYear, &ModelObject::setYear));
	getProperties()->push_back(new StringProperty("comments", this, &ModelObject::getComments, &ModelObject::setComments));
	getProperties()->push_back(new IntProperty("hours", this, &ModelObject::getHour, &ModelObject::setHour));
	getProperties()->push_back(new IntProperty("minutes", this, &ModelObject::getMinute, &ModelObject::setMinute));
}

// Static attribute definition

const string Consultation::TABLE_NAME = "CONSULTATIONS";
const string Consultation::ID_NAME = "consultationid";

// Definition of functions declared as virtual in ModelObject 

string Consultation::getTableName() { return TABLE_NAME; }
string Consultation::getIdName() { return ID_NAME; }

ModelObject::ObjectType Consultation::getObjectType() { return CONSULTATION; }

// Class attribute get() & set() methods

int Consultation::getId() { return consultId; }
void Consultation::setId(const int newConsultId) { consultId = newConsultId; }

int Consultation::getPhysicianId() { return consultingPhysId; }
void Consultation::setPhysicianId(const int value) { consultingPhysId = value; }

string Consultation::getReason() { return reason; }
void Consultation::setReason(const string value) { reason = value; }

string Consultation::getDiagnosis() { return diagnosis; }
void Consultation::setDiagnosis(const string value) { diagnosis = value; }

int Consultation::getCStatus() { return (int)status; }
void Consultation::setCStatus(const int value) { status = (ConsultationStatus)value; }

Date Consultation::getDate() { return date; }
void Consultation::setDate(const Date value) { date = value; }

	int Consultation::getDay() { return date.getDay(); }
	void Consultation::setDay(const int value) { date.setDay(value); }

	int Consultation::getMonth() { return date.getMonth(); }
	void Consultation::setMonth(const int value) { date.setMonth(value); }

	int Consultation::getYear() { return date.getYear(); }
	void Consultation::setYear(const int value) { date.setYear(value); }

string Consultation::getComments() { return comments; }
void Consultation::setComments(const string value) { comments = value; }

Time Consultation::getTime() { return time; }
void Consultation::setTime(const Time value) { time = value; }

	int Consultation::getHour() { return time.getHour(); }
	void Consultation::setHour(const int value) { time.setHour(value); }

	int Consultation::getMinute() { return time.getMinute(); }
	void Consultation::setMinute(const int value) { time.setMinute(value); }

vector<int>* Consultation::getFollowupIds() { return &followupIds; }
void Consultation::addFollowupId(const int value) { followupIds.push_back(value); }

// EOF
