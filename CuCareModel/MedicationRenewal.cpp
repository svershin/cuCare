// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MedicationRenewal.cpp - Implementation of class MedicationRenewal
// Function and attribute declarations are in MedicationRenewal.h

#include "MedicationRenewal.h"
#include "StringProperty.h"

// Constructor
MedicationRenewal::MedicationRenewal()
    : medication("0")
{
	getProperties()->push_back(new StringProperty("medication", this, &ModelObject::getMedication, &ModelObject::setMedication));
}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType MedicationRenewal::getObjectType() { return MEDICATIONRENEWAL; }

// Class attribute get() & set() methods

string MedicationRenewal::getMedication() { return medication; }
void MedicationRenewal::setMedication(const string value) { medication = value; }

// EOF
