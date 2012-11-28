// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// ModelObject.cpp - Implementation of class ModelObject
// Function and attribute declarations are in ModelObject.h

#include "ModelObject.h"
#include "IntProperty.h"

ModelObject::ModelObject() : properties () {
	getProperties()->push_back(new IntProperty("deleted", this, &ModelObject::isDeleted, &ModelObject::markDeleted));
}

ModelObject::~ModelObject() {
	while(!properties.empty()) {
        delete properties.front();
        properties.pop_front();
	}
}

list<Property*>* ModelObject::getProperties() { return &properties; }

int ModelObject::isDeleted() { return (int)deleted; }
void ModelObject::markDeleted(int value) { deleted = true; }

// From User.h

int ModelObject::getId() { return 0; }
void ModelObject::setId(const int value) { }

string ModelObject::getUsername() { return ""; }
void ModelObject::setUsername(const string value) { }

string ModelObject::getFirstName() { return ""; }
void ModelObject::setFirstName(const string value) { }

string ModelObject::getLastName() { return ""; }
void ModelObject::setLastName(const string value) { }

string ModelObject::getCountry() { return ""; }
void ModelObject::setCountry(const string value) { }

string ModelObject::getCity() { return ""; }
void ModelObject::setCity(const string value) { }

string ModelObject::getLineOne() { return ""; }
void ModelObject::setLineOne(const string value) { }

string ModelObject::getLineTwo() { return ""; }
void ModelObject::setLineTwo(const string value) { }

string ModelObject::getPostalCode() { return ""; }
void ModelObject::setPostalCode(const string value) { }

string ModelObject::getWorkPhone() { return ""; }
void ModelObject::setWorkPhone(const string value) { }

string ModelObject::getCellPhone() { return ""; }
void ModelObject::setCellPhone(const string value) { }

string ModelObject::getEmail() { return ""; }
void ModelObject::setEmail(const string value) { }

string ModelObject::getWorkEmail() { return ""; }
void ModelObject::setWorkEmail(const string value) { }

int ModelObject::getDay() { return 0; }
void ModelObject::setDay(const int value) { }

int ModelObject::getMonth() { return 0; }
void ModelObject::setMonth(const int value) { }

int ModelObject::getYear() { return 0; }
void ModelObject::setYear(const int value) { }

// from Physician.h

int ModelObject::getPhysicianId() { return 0; }
void ModelObject::setPhysicianId(const int value) { }

// from Patient.h

int ModelObject::getDay1() { return 0; }
void ModelObject::setDay1(const int value) { }

int ModelObject::getMonth1() { return 0; }
void ModelObject::setMonth1(const int value) { }

int ModelObject::getYear1() { return 0; }
void ModelObject::setYear1(const int value) { }

string ModelObject::getHCNumber() { return ""; }
void ModelObject::setHCNumber(const string value) { }

int ModelObject::getHCExpiryDay() { return 0; }
void ModelObject::setHCExpiryDay(const int value) { }

int ModelObject::getHCExpiryMonth() { return 0; }
void ModelObject::setHCExpiryMonth(const int value) { }

int ModelObject::getHCExpiryYear() { return 0; }
void ModelObject::setHCExpiryYear(const int value) { }

string ModelObject::getNotes() { return ""; }
void ModelObject::setNotes(const string value) { }

// from Consultation.h

string ModelObject::getReason() { return ""; }
void ModelObject::setReason(const string value) { }

string ModelObject::getDiagnosis() { return ""; }
void ModelObject::setDiagnosis(const string value) { }

string ModelObject::getComments() { return ""; }
void ModelObject::setComments(const string value) { }

int ModelObject::getCStatus() { return 0; }
void ModelObject::setCStatus(const int value) { }

int ModelObject::getHour() { return 0; }
void ModelObject::setHour(int value) { }

int ModelObject::getMinute() { return 0; }
void ModelObject::setMinute(int value) { }

// from Followup.h

int ModelObject::getFStatus() { return 0; }
void ModelObject::setFStatus(const int value) { }

int ModelObject::getDay2() { return 0; }
void ModelObject::setDay2(const int value) { }

int ModelObject::getMonth2() { return 0; }
void ModelObject::setMonth2(const int value) { }

int ModelObject::getYear2() { return 0; }
void ModelObject::setYear2(const int value) { }

// from MedicationRenewal.h

string ModelObject::getMedication() { return ""; }
void ModelObject::setMedication(const string value) { }

// from ResultantFollowup.h

string ModelObject::getResults() { return ""; }
void ModelObject::setResults(const string value) { }

// from MedicalTest.h

string ModelObject::getTestType() { return ""; }
void ModelObject::setTestType(const string value) { }

// from Referral.h

string ModelObject::getSpecialistName() { return ""; }
void ModelObject::setSpecialistName(const string value) { }

// from ReturnConsultation.h

int ModelObject::getConsultId() { return 0; }
void ModelObject::setConsultId(const int value) { }
// EOF
