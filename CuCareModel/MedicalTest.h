// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MedicalTest.h - Declaration of class MedicalTest
// Member functions are defined in MedicalTest.cpp

#ifndef MDEICALTEST_H
#define MDEICALTEST_H

#include <string>
#include "ResultantFollowup.h"

using namespace std;

class MedicalTest:public ResultantFollowup
{
public:
	// Constructor
	MedicalTest();

	// Declaration of functions declared as virtual in ModelObject 

	ObjectType getObjectType();

	// Class attribute get() & set() methods

	string getTestType();
	void setTestType(const string value);

private:
	string testType;
};

#endif // MDEICALTEST_H

// EOF
