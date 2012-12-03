// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Referral.h - Declaration of class Referral
// Member functions are defined in Referral.cpp

#ifndef REFERRAL_H
#define REFERRAL_H

#include "ResultantFollowup.h"
#include <string>

using namespace std;

class Referral:public ResultantFollowup
{
public:
	// Constructor
	Referral ();

	// Declaration of functions declared as virtual in ModelObject 

	ObjectType getObjectType();

	// Class attribute get() & set() methods

	string getSpecialistName();
	void setSpecialistName(const string value);

private:
	string specialistName;
};

#endif // REFERRAL_H

// EOF