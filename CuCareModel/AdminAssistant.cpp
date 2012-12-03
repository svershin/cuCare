// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// AdminAssistant.cpp - Implementation of class AdminAssistant
// Function and attribute declarations are in AdminAssistant.h

#include "AdminAssistant.h"

AdminAssistant::AdminAssistant()
{
}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType AdminAssistant::getObjectType() { return ModelObject::ADMINASSISTANT; }

// EOF
