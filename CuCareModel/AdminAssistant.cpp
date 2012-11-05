// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// AdminAssistant.h - Declaration of base class AdminAssistant
// Member functions are defined in AdminAssistant.cpp

#include "AdminAssistant.h"

// Constructor
AdminAssistant::AdminAssistant
(	string usernameParam,
    string firstNameParam,
    string lastNameParam,
    Date dateOfBirthParam,
    ContactInfo contactParam,
    Address addressParam,
    bool deletedParam)
    : User (usernameParam,
            firstNameParam,
            lastNameParam,
            dateOfBirthParam,
            contactParam,
            addressParam,
            deletedParam)
{}

AdminAssistant::AdminAssistant(){}

// Destructor
AdminAssistant::~AdminAssistant()
{
}

// EOF
