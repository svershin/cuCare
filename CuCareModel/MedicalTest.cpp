// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// MedicalTest.cpp - Implementation of class MedicalTest
// Function and attribute declarations are in MedicalTest.h

#include "MedicalTest.h"
#include "StringProperty.h"

// Constructor
MedicalTest::MedicalTest() {
	getProperties()->push_back(new StringProperty("testtype", this, &ModelObject::getTestType, &ModelObject::setTestType));
}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType MedicalTest::getObjectType() { return MEDICALTEST; }

// Class attribute get() & set() methods

string MedicalTest::getTestType() { return testType; }
void MedicalTest::setTestType(const string value) { testType = value; }

// EOF
