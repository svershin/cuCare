// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// MedicationRenewal.h - Declaration of class MedicationRenewal
// Member functions are defined in MedicationRenewal.cpp

#ifndef MEDICATIONRENEWAL_H
#define MEDICATIONRENEWAL_H

#include "Followup.h"
#include <string>

using namespace std;

class MedicationRenewal:public Followup
{
public:
	// Constructor
	MedicationRenewal ();

	// Declaration of functions declared as virtual in ModelObject 

	ObjectType getObjectType();

	// Class attribute get() & set() methods

	string getMedication();
	void setMedication(const string value);

private:
	string medication;
};

#endif // MEDICATIONRENEWAL_H

// EOF
