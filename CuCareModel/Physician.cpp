// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Physician.cpp - Implementation of class Physician
// Function and attribute declarations are in Physician.h

#include "IntProperty.h"
#include "Physician.h"

// Constructor
Physician::Physician()
    : physicianId(0)
{
      getProperties()->push_back(new IntProperty("physicianid", this, &ModelObject::getPhysicianId, &ModelObject::setPhysicianId));
}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType Physician::getObjectType() { return ModelObject::PHYSICIAN; }

// Class attribute get() & set() methods

int Physician::getPhysicianId() { return physicianId; };
void Physician::setPhysicianId(const int value) { physicianId = value; }

// EOF
