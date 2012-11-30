// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// AdminAssistant.cpp - Implementation of class AdminAssistant
// Function and attribute declarations are in AdminAssistant.h

#include "AdminAssistant.h"

AdminAssistant::AdminAssistant()
{
    getProperties()->push_back(new IntProperty("physicianid", this, &ModelObject::getPhysicianId, &ModelObject::setPhysicianId));
}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType AdminAssistant::getObjectType() { return ADMINASSISTANT; }

// EOF
