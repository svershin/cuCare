// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ReturnConsultation.cpp - Implementation of class ReturnConsultation
// Function and attribute declarations are in ReturnConsultation.h

#include "Referral.h"
#include "StringProperty.h"

// Constructor
Referral::Referral()
    : specialistName("0")
{
    getProperties()->push_back(new StringProperty("specialistname", this, &ModelObject::getSpecialistName, &ModelObject::setSpecialistName));
}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType Referral::getObjectType() { return REFERRAL; }

// Class attribute get() & set() methods

string Referral::getSpecialistName() { return specialistName; }
void Referral::setSpecialistName(const string value) { specialistName = value; }

// EOF
