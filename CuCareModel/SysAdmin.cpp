// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// SysAdmin.cpp - Implementation of class SysAdmin
// Function and attribute declarations are in SysAdmin.h

#include "SysAdmin.h"

SysAdmin::SysAdmin()
{

}

// Definition of functions declared as virtual in ModelObject 

ModelObject::ObjectType SysAdmin::getObjectType() { return ModelObject::SYSADMIN; }

// EOF
