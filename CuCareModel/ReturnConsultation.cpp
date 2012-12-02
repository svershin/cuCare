// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ReturnConsultation.cpp - Implementation of class ReturnConsultation
// Function and attribute declarations are in ReturnConsultation.h

#include "ReturnConsultation.h"
#include "IntProperty.h"

// Constructor
ReturnConsultation::ReturnConsultation()
    : consultId(0)
{
    getProperties()->push_back(new IntProperty("nextconsultationid", this, &ModelObject::getConsultId, &ModelObject::setConsultId));
}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType ReturnConsultation::getObjectType() { return RETURNCONSULTATION; }

// Class attribute get() & set() methods

int ReturnConsultation::getConsultId() { return consultId; }
void ReturnConsultation::setConsultId(const int value) { consultId = value; }

// EOF
