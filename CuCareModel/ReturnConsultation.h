// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ReturnConsultation.h - Declaration of class ReturnConsultation
// Member functions are defined in ReturnConsultation.cpp

#ifndef RETURNCONSULTAION_H
#define RETURNCONSULTAION_H

#include "Followup.h"

class ReturnConsultation : public Followup
{
public:
    // Constructor
    ReturnConsultation ();

    // Declaration of functions declared as virtual in ModelObject 

    ObjectType getObjectType();

    // Class attribute get() & set() methods

    int getConsultId();
    void setConsultId(const int value);

private:
    int consultId;
};

#endif

// EOF
