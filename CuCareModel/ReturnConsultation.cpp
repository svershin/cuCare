// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ReturnConsultation.h - Declaration of base class ReturnConsultation
// Member functions are defined in ReturnConsultation.cpp

#include "ReturnConsultation.h"

// Constructor
ReturnConsultation::ReturnConsultation
(   int idParam,
    FollowupStatus statusParam,
    Date dateDueParam,
    Date dateReceivedParam,
    Date dateCompletedParam,
    Consultation* pConsultParam,
    bool deletedParam)
    : Followup (idParam,
                statusParam,
                dateDueParam,
                dateReceivedParam,
                dateCompletedParam,
                deletedParam),
      pConsult (pConsultParam)
{
}

// Destructor
ReturnConsultation::~ReturnConsultation()
{
}

Consultation* ReturnConsultation::getConsult() { return pConsult; }
void ReturnConsultation::setConsult(Consultation* const value) { pConsult = value; }

int ReturnConsultation::getType() { return 5; }

// EOF
