// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Physician.h - Declaration of base class Physician
// Member functions are defined in Physician.cpp

#include "Physician.h"

// Constructor
Physician::Physician
(	int idParam,
    string usernameParam,
    string firstNameParam,
    string lastNameParam,
    string titleParam,
    Date dateOfBirthParam,
    ContactInfo contactParam,
    Address addressParam,
    bool deletedParam)
    : User (usernameParam,
            firstNameParam,
            lastNameParam,
            titleParam,
            dateOfBirthParam,
            contactParam,
            addressParam,
            deletedParam),
      id (idParam)
{
}

// Destructor
Physician::~Physician()
{
}

int Physician::getId() { return id; }

// EOF
