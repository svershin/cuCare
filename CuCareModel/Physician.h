// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// Physician.h - Declaration of class Physician
// Member functions are defined in Physician.cpp

#ifndef PHYSICIAN_H
#define PHYSICIAN_H

#include "User.h"

class Physician : public User
{
public:
    Physician();

    // Declaration of functions declared as virtual in ModelObject 

    ObjectType getObjectType();

    // Class attribute get() & set() methods

    int getPhysicianId();
    void setPhysicianId(const int value);

private:
    int physicianId;
};


#endif // PHYSICIAN_H

// EOF
