// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// AdminAssistant.h - Declaration of base class AdminAssistant
// Member functions are defined in AdminAssistant.cpp

#ifndef ADMINASSISTANT_H
#define ADMINASSISTANT_H

#include "User.h"

class AdminAssistant : public User
{
public:
    AdminAssistant();
	// Declaration of functions declared as virtual in ModelObject 

	ObjectType getObjectType();
};

#endif // ADMINASSISTANT_H

// EOF
